/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_launch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:02 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/18 13:15:53 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void			ft_ssl_launch_function_launch(t_command *command, t_uint n,
													t_pchar type)
{
	void			(*launch)(t_pchar *, t_pchar *);
	void			(*print)(t_pchar, t_file, t_pchar, t_command *);
	t_pchar			hash;
	t_file			file;

	launch = command[n].function;
	print = ft_ssl_tools_get_cmd_function(command, "PRINT");
	if (ft_strcmp(command[n - 1].name, "ARGS"))
	{
		launch(command[n - 1].param, &hash);
		file.name = NULL;
		file.content.bytes = command[n - 1].param;
		file.content.size = ft_strlen(command[n - 1].param);
		print(hash, file, type, command);
		ft_strdel((t_pchar *)&command[n - 1].param);
	}
	else
		while (ft_ssl_launch_file(command[n - 1].param, &file, type))
			if (file.name)
			{
				launch(file.content.bytes, &hash);
				print(hash, file, type, command);
				if (!ft_unmap_file(&file.content))
					return ;
			}
}

static void			ft_ssl_launch_function(t_command *command, t_uint n,
											t_pchar type)
{
	void			(*function)(t_pvoid *);

	if (!command[n].active)
		return ;
	if (ft_strcmp(command[n].name, "LAUNCH"))
	{
		if ((function = command[n].function))
			function((t_pvoid)(&(command[n])));
	}
	else
		ft_ssl_launch_function_launch(command, n, type);
}

extern t_bool		ft_ssl_launch(t_pchar type, t_command *command)
{
	t_uint			n;

	n = 0;
	while (command[n].name != NULL && ft_strcmp(command[n].name, "PRINT"))
		ft_ssl_launch_function(command, n++, type);
	return (TRUE);
}
