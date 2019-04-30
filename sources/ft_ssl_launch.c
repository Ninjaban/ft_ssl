
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

static t_bool		ft_ssl_launch_file(t_pchar *args, t_file *file,
										t_pchar type)
{
	static int		n = 0;

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

/*
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
*/

static void			ft_ssl_launch_function(t_command *command, t_uint n, void (*print)(t_pchar, t_pchar, t_pchar, t_command *), t_pchar type)
{
	void			(*function)(t_pvoid *);
	void			(*launch)(t_pchar *, t_pchar *);
	t_pchar			hash;
	t_file			file;

	if (!command[n].active)
		return ;
	if (ft_strcmp(command[n].name, "LAUNCH"))
	{
		if ((function = command[n].function))
			function((t_pvoid)(&(command[n])));
	}
	else
	{
		launch = command[n].function;
		if (ft_strcmp(command[n - 1].name, "ARGS"))
		{
			launch(command[n - 1].param, &hash);
			print(hash, command[n - 1].param, NULL, command);
			ft_strdel((t_pchar *)&command[n - 1].param);
		}
		else
		{
			while (ft_ssl_launch_file(command[n - 1].param, &file, type))
			{
				if (file.name)
				{
					launch(file.content.bytes, &hash);
					print(hash, file.content.bytes, file.name, command);
					if (!ft_unmap_file(&file.content))
						return;
				}
			}
		}
	}

}

extern t_bool		ft_ssl_launch(t_pchar type, t_command *command)
{
//	t_file			file;
//	t_pchar			*args;
	void			(*print)(t_pchar, t_pchar, t_pchar, t_command *);
	t_uint			n;

	n = 0;
	print = ft_ssl_tools_get_cmd_function(command, "PRINT");
	while (command[n].name != NULL && ft_strcmp(command[n].name, "PRINT"))
	{
		FT_DEBUG("name %s active %s", command[n].name, (command[n].active) ? "TRUE" : "FALSE");
		ft_ssl_launch_function(command, n, print, type);

		n = n + 1;
	}

	return (TRUE);
	/*
	args = ft_ssl_tools_get_cmd_param(command, "ARGS");
	if (ft_ssl_tools_get_cmd_active(flags, "-p"))
	{
		ft_ssl_launch_hash(type, ft_ssl_tools_get_cmd_param(flags, "-p"), NULL, flags);
		free(ft_ssl_tools_get_cmd_param(flags, "-p"));
	}
	if (ft_ssl_tools_get_cmd_active(flags, "-s"))
		ft_ssl_launch_hash(type, ft_ssl_tools_get_cmd_param(flags, "-s"), NULL, flags);
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
	*/
}
