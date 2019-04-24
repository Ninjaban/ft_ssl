
#include "libft.h"
#include "error.h"
#include "types.h"
#include "internal.h"

static void			ft_ssl_launch_file_error(t_pchar file_name, t_pchar type)
{
	ft_putstr("ft_ssl: ");
	ft_putstr(type);
	ft_putstr(": ");
	ft_putstr(file_name);
	ft_putstr(": No such file or directory\n");
}

static t_bool		ft_ssl_launch_file(t_settings settings, t_file *file,
										t_pchar type)
{
	static int		n = 0;

	if (!settings.args.f[n])
		return (FALSE);
	(*file).name = NULL;
	if (!ft_map_file(settings.args.f[n], &((*file).content)))
	{
		ft_ssl_launch_file_error(settings.args.f[n], type);
		n = n + 1;
		return (TRUE);
	}
	(*file).name = settings.args.f[n];
	n = n + 1;
	return (TRUE);
}

static t_bool		ft_ssl_launch_hash(t_pchar type, t_pchar text, t_pchar name,
										t_settings settings)
{
	t_pchar		hash;

	hash = NULL;
	if (!ft_strcmp(type, "md5") && !ft_md5_main(text, &hash))
		return (FALSE);
	if (!ft_strcmp(type, "sha256") && !ft_sha256_main(text, &hash))
		return (FALSE);
	if (!ft_strcmp(type, "whirlpool") && !ft_whirlpool_main(text, &hash))
		return (FALSE);
	ft_ssl_print(hash, text, name, settings);
	return (TRUE);
}

extern t_bool		ft_ssl_launch(t_pchar type, t_settings settings)
{
	t_file			file;

	if (settings.args.p)
	{
		ft_ssl_launch_hash(type, settings.args.p, NULL, settings);
		free(settings.args.p);
	}
	if (settings.s)
		ft_ssl_launch_hash(type, settings.args.s, NULL, settings);
	BUFFER_CLEAR(file.content);
	while (settings.args.f && ft_ssl_launch_file(settings, &file, type))
	{
		if (file.name)
		{
			ft_ssl_launch_hash(type, file.content.bytes, file.name, settings);
			if (!ft_unmap_file(&file.content))
				return (FALSE);
		}
	}
	return (TRUE);
}
