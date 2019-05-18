/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:55:38 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 13:15:54 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "internal.h"

extern t_bool		ft_ssl_base64_mode(t_pvoid args)
{
	t_command	*command;
	void		(*function);
	int			n;

	command = args;
	if (ft_ssl_tools_get_cmd_active(command, "-d"))
		function = ft_ssl_tools_get_cmd_function(command, "-d");
	else
		function = ft_ssl_tools_get_cmd_function(command, "-e");
	n = 0;
	while (command[n].name)
	{
		if (!ft_strcmp(command[n].name, "LAUNCH"))
			command[n].function = function;
		n = n + 1;
	}
	n = 0;
	while (command[n].name && ft_strcmp(command[n].name, "PRINT"))
		n = n + 1;
	if (ft_ssl_tools_get_cmd_active(command, "-o"))
	{
		command[n].function = ft_ssl_tools_get_cmd_function(command, "-o");
		command[n].param = ft_strdup(ft_ssl_tools_get_cmd_param(command, "-o"));
	}
	return (TRUE);
}