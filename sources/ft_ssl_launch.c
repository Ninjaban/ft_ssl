
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

static t_bool		ft_ssl_launch_file(t_lst *flags, t_file *file,
										t_pchar type)
{
	static int		n = 0;
	t_pchar			*args;

	args = ft_ssl_tools_get_flag_param(flags, "ARGS");
	if (!args[n])
		return (FALSE);
	(*file).name = NULL;
	if (!ft_map_file(args[n], &((*file).content)))
	{
		ft_ssl_launch_file_error(args[n], type);
		n = n + 1;
		return (TRUE);
	}
	(*file).name = args[n];
	n = n + 1;
	return (TRUE);
}

static t_bool		ft_ssl_launch_hash(t_pchar type, t_pchar text, t_pchar name,
										t_lst *flags)
{
	t_pchar		hash;

	hash = NULL;
	if (!ft_strcmp(type, "md5") && !ft_md5_main(text, &hash))
		return (FALSE);
	if (!ft_strcmp(type, "sha256") && !ft_sha256_main(text, &hash))
		return (FALSE);
	if (!ft_strcmp(type, "whirlpool") && !ft_whirlpool_main(text, &hash))
		return (FALSE);
	ft_ssl_print(hash, text, name, flags);
	return (TRUE);
}

extern t_bool		ft_ssl_launch(t_pchar type, t_lst *flags)
{
	t_file			file;
	t_pchar			*args;

	args = ft_ssl_tools_get_flag_param(flags, "ARGS");
	if (ft_ssl_tools_check_flag_name(flags, "-p"))
	{
		ft_ssl_launch_hash(type, ft_ssl_tools_get_flag_param(flags, "-p"), NULL, flags);
		free(ft_ssl_tools_get_flag_param(flags, "-p"));
	}
	if (ft_ssl_tools_check_flag_name(flags, "-s"))
		ft_ssl_launch_hash(type, ft_ssl_tools_get_flag_param(flags, "-s"), NULL, flags);
	BUFFER_CLEAR(file.content);
	while (args && ft_ssl_launch_file(flags, &file, type))
	{
		if (file.name)
		{
			ft_ssl_launch_hash(type, file.content.bytes, file.name, flags);
			if (!ft_unmap_file(&file.content))
				return (FALSE);
		}
	}
	return (TRUE);
}
