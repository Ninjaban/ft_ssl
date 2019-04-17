//
// Created by Jonathan CARRA on 2019-04-15.
//

#include "libft.h"
#include "get_next_line.h"
#include "types.h"
#include "error.h"
#include "internal.h"

static t_bool		ft_ssl_launch_file(t_settings settings, t_buffer *file)
{
	static int		n = 0;

	if (!settings.args.f[n])
		return (FALSE);

	if (!ft_map_file(settings.args.f[n], file))
	{
		FT_WARNING("ft_map_file() failed file %s", settings.args.f[n]);
	}
	n = n + 1;

	return (TRUE);
}

static t_bool		ft_ssl_launch_hash(t_pchar type, t_pchar text)
{
	t_pchar		hash;

	hash = NULL;
	if (!ft_strcmp(type, "md5") && !ft_md5_main(text, &hash))
	{
		FT_WARNING("ft_md5_main() failed {%.*s}", (int)ft_strlen(text), text);
		return (FALSE);
	}

	if (!ft_strcmp(type, "sha256") && !ft_sha256_main(text, &hash))
	{
		FT_WARNING("ft_sha256_main() failed {%.*s}", (int)ft_strlen(text), text);
		return (FALSE);
	}

	FT_DEBUG("%.*s", 32, hash);			//DEBUG

	return (TRUE);
}

static t_bool		ft_ssl_launch(t_pchar type, t_settings settings)
{
	t_buffer		file;

	if (settings.p)
	{
		ft_ssl_launch_hash(type, settings.args.p);
		free(settings.args.p);
	}
	if (settings.s)
		ft_ssl_launch_hash(type, settings.args.s);

	BUFFER_CLEAR(file);
	while (settings.args.f && ft_ssl_launch_file(settings, &file))
	{
		if (file.bytes)
		{
			ft_ssl_launch_hash(type, file.bytes);

			if (!ft_unmap_file(&file))
			{
				FT_WARNING("ft_unmap_file() failed %s", "");
				return (FALSE);
			}
		}
	}

	return (TRUE);
}

static t_bool		ft_ssl_settings_file(int ac, char **av, t_settings *settings)
{
	int		i;

	i = 0;
	if (((*settings).args.f = malloc(sizeof(t_buffer) * (ac + 1))) == NULL)
	{
		FT_ERROR("malloc() failed size %zu", sizeof(t_buffer) * (ac + 1));
		return (FALSE);
	}

	while (i < ac)
	{
		(*settings).args.f[i] = av[i];
		i = i + 1;
	}
	(*settings).args.f[i] = NULL;

	return (TRUE);
}

static t_bool		ft_ssl_settings_stdin(t_settings *settings)
{
	t_pchar		line;
	t_pchar		p;
	t_pchar		tmp;

	if ((p = ft_strdup("")) == NULL)
	{
		FT_ERROR("ft_strdup() failed %s", "");
		return (FALSE);
	}
	while (get_next_line(0, &line) > 0)
	{
		if ((tmp = ft_strjoin(p, line)) == NULL)
		{
			FT_ERROR("ft_strjoin() failed s1 %s s2 %s", p, line);
			return (FALSE);
		}
		free(p);
		p = tmp;
	}

	(*settings).args.p = p;
	return (TRUE);
}

static void			ft_ssl_settings_init(t_settings *settings)
{
	(*settings).p = FALSE;
	(*settings).q = FALSE;
	(*settings).r = FALSE;
	(*settings).s = FALSE;

	(*settings).args.p = NULL;
	(*settings).args.s = NULL;
	(*settings).args.f = NULL;
}

static t_bool		ft_ssl_settings(int ac, char **av, t_settings *settings)
{
	int		n;

	n = 0;
	ft_ssl_settings_init(settings);

	while (n < ac && *(av[n]) == '-')
	{
		FT_DEBUG("Param '%s' n %d", av[n], n);
		if (!ft_strcmp(av[n], "-p"))
			(*settings).p = TRUE;
		else if (!ft_strcmp(av[n], "-q"))
			(*settings).q = TRUE;
		else if (!ft_strcmp(av[n], "-r"))
			(*settings).r = TRUE;
		else if (!ft_strcmp(av[n], "-s"))
		{
			if (n + 1 >= ac)
				return (FALSE);
			(*settings).s = TRUE;
			(*settings).args.s = av[n + 1];
			n = n + 2;
			break;
		}
		else
		{
			FT_ERROR("Invalid Param '%s'", av[n]);
			return (FALSE);
		}
		n = n + 1;
	}

	FT_DEBUG("n %d ac %d", n, ac);
	if (n < ac && !ft_ssl_settings_file(ac - n, av + n, settings))
	{
		FT_WARNING("ft_ssl_settings_file() failed %s", "");
		return (FALSE);
	}

	if (((*settings).p == TRUE || (!(*settings).s && !(*settings).args.f)))
	{
		(*settings).p = TRUE;
		if (!ft_ssl_settings_stdin(settings))
		{
			FT_WARNING("ft_ssl_settings_stdin() failed %s", "");
			return (FALSE);
		}
	}

	return (TRUE);
}

extern t_bool		ft_ssl(int ac, char **av)
{
	t_settings		settings;

	if (ac < 2)
	{
		FT_ERROR("ac == %d", ac);
		ft_ssl_usage();
		return (FALSE);
	}
	if (ft_strcmp(av[1], "md5") && ft_strcmp(av[1], "sha256"))
	{
		FT_ERROR("Command Opts: %s", av[1]);
		ft_ssl_error_command(av[1]);
		return (FALSE);
	}

	if (!ft_ssl_settings(ac - 2, av + 2, &settings))
	{
		FT_WARNING("ft_ssl_args() failed%s", "");
		return (FALSE);
	}

	if (!ft_ssl_launch(av[1], settings))
	{
		FT_WARNING("ft_ssl_launch() failed %s", "");
		return (FALSE);
	}

	return (TRUE);
}
