/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:28:35 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/17 09:04:10 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal.h"

static void			ft_ssl_print_reverse(t_pchar hash, t_file file,
										t_pchar type, t_command *command)
{
	ft_putstr(hash);
	ft_putstr("  ");
	if (!ft_ssl_tools_get_cmd_active(command, "-q"))
	{
		if (file.name)
		{
			ft_putstr(type);
			ft_putstr(" (");
			ft_putstr(file.name);
			ft_putstr(")\n");
		}
		else if (ft_ssl_tools_get_cmd_active(command, "-p") &&
	!ft_strcmp(file.content.bytes, ft_ssl_tools_get_cmd_param(command, "-p")))
		{
			ft_putendl(file.content.bytes);
		}
		else if (!ft_strcmp(file.content.bytes,
				ft_ssl_tools_get_cmd_param(command, "-s")))
		{
			ft_putstr(type);
			ft_putstr(" ('");
			ft_putstr(file.content.bytes);
			ft_putstr("')\n");
		}
	}
}

static void			ft_ssl_print_normal(t_pchar hash, t_file file, t_pchar type,
										t_command *command)
{
	if (!ft_ssl_tools_get_cmd_active(command, "-q"))
	{
		if (file.name)
		{
			ft_putstr(type);
			ft_putstr(" (");
			ft_putstr(file.name);
			ft_putstr(") = ");
		}
		else if (ft_ssl_tools_get_cmd_active(command, "-p") &&
	!ft_strcmp(file.content.bytes, ft_ssl_tools_get_cmd_param(command, "-p")))
		{
			ft_putendl(file.content.bytes);
		}
		else if (!ft_strcmp(file.content.bytes,
				ft_ssl_tools_get_cmd_param(command, "-s")))
		{
			ft_putstr(type);
			ft_putstr(" ('");
			ft_putstr(file.content.bytes);
			ft_putstr("') = ");
		}
	}
	ft_putendl(hash);
}

extern void			ft_ssl_print(t_pchar hash, t_file file, t_pchar type,
									t_command *command)
{
	if (!ft_ssl_tools_get_cmd_active(command, "-r"))
		ft_ssl_print_normal(hash, file, type, command);
	else
		ft_ssl_print_reverse(hash, file, type, command);
	free(hash);
}
