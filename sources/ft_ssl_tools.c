/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:28:58 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 11:29:01 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "types.h"
#include "internal.h"

extern t_bool		ft_ssl_tools_get_cmd_active(t_command *command,
												t_pchar name)
{
	t_uint		n;

	n = 0;
	while (command[n].name != NULL && ft_strcmp(command[n].name, name))
		n = n + 1;
	return (command[n].active);
}

extern t_pvoid		ft_ssl_tools_get_cmd_param(t_command *command, t_pchar name)
{
	t_uint		n;

	n = 0;
	while (command[n].name != NULL && ft_strcmp(command[n].name, name))
		n = n + 1;
	return (command[n].param);
}

extern t_pvoid		ft_ssl_tools_get_cmd_function(t_command *command,
													t_pchar name)
{
	t_uint		n;

	n = 0;
	while (command[n].name != NULL && ft_strcmp(command[n].name, name))
		n = n + 1;
	return (command[n].function);
}

extern t_bool		ft_ssl_tools_stdin(t_pvoid args)
{
	t_command	*command;
	t_pchar		line;
	t_pchar		p;
	t_pchar		tmp;
	int			nbr;

	command = args;
	if ((p = ft_strdup("")) == NULL)
		return (FALSE);
	if ((line = malloc(4096 + 1)) == NULL)
		return (FALSE);
	while ((nbr = read(0, line, 4096)) > 0)
	{
		line[nbr] = '\0';
		if ((tmp = ft_strjoin(p, line)) == NULL)
			return (FALSE);
		free(p);
		p = tmp;
	}
	free(line);
	(*command).param = p;
	return (TRUE);
}

extern t_bool		ft_ssl_tools_file(t_pvoid args)
{
	t_command	*command;
	t_buffer	file;

	command = args;
	if (!ft_map_file(command->param, &file))
		return (FALSE);
	free(command->param);
	command->param = file.bytes;
	return (TRUE);
}