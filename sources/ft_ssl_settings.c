
#include "libft.h"
#include "get_next_line.h"
#include "error.h"
#include "types.h"
#include "internal.h"

static t_bool		ft_ssl_settings_file(int ac, char **av,
											t_settings *settings)
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
		return (FALSE);
	while (get_next_line(0, &line) > 0)
	{
		if ((tmp = ft_strjoin(p, line)) == NULL)
			return (FALSE);
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

static t_bool		ft_ssl_settings_params(int ac, char **av, int *n,
											t_settings *settings)
{
	while (*n < ac && *(av[*n]) == '-')
	{
		if (!ft_strcmp(av[*n], "-p"))
			(*settings).p = TRUE;
		else if (!ft_strcmp(av[*n], "-q"))
			(*settings).q = TRUE;
		else if (!ft_strcmp(av[*n], "-r"))
			(*settings).r = TRUE;
		else if (!ft_strcmp(av[*n], "-s"))
		{
			if (*n + 1 >= ac)
				return (FALSE);
			(*settings).s = TRUE;
			(*settings).args.s = av[*n + 1];
			*n = *n + 2;
			break ;
		}
		else
			return (FALSE);
		*n = *n + 1;
	}
	return (TRUE);
}

extern t_bool		ft_ssl_settings(int ac, char **av, t_settings *settings)
{
	int		n;

	n = 0;
	ft_ssl_settings_init(settings);
	if (!ft_ssl_settings_params(ac, av, &n, settings))
		return (FALSE);
	if (n < ac && !ft_ssl_settings_file(ac - n, av + n, settings))
		return (FALSE);
	if (((*settings).p == TRUE || (!(*settings).s && !(*settings).args.f)))
	{
		if (!ft_ssl_settings_stdin(settings))
			return (FALSE);
	}
	return (TRUE);
}
