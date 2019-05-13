/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:28:44 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/13 12:10:05 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "internal.h"

static t_bool		ft_ssl_init_hash(t_command **command, void (*function))
{
	int		n;

	if ((*command = malloc(sizeof(t_command) * 10)) == NULL)
		return (FALSE);
	n = 0;
	ft_ssl_init_add_cmd("-p", &ft_ssl_tools_stdin, ninit(0, FALSE),
						&((*command)[n++]));
	ft_ssl_init_add_default(ft_strsplit("-s ARGS", " "), &((*command)[n - 1]));
	ft_ssl_init_add_launch(function, &((*command)[n++]));
	ft_ssl_init_add_cmd("-s", NULL, ninit(1, TRUE), &((*command)[n++]));
	ft_ssl_init_add_launch(function, &((*command)[n++]));
	ft_ssl_init_add_cmd("ARGS", NULL, ninit(0, FALSE), &((*command)[n++]));
	ft_ssl_init_add_launch(function, &((*command)[n++]));
	ft_ssl_init_add_cmd("PRINT", &ft_ssl_print, ninit(0, FALSE),
						&((*command)[n++]));
	ft_ssl_init_add_cmd("-r", NULL, ninit(0, FALSE), &((*command)[n++]));
	ft_ssl_init_add_cmd("-q", NULL, ninit(0, FALSE), &((*command)[n++]));
	ft_ssl_init_add_cmd(NULL, NULL, ninit(0, FALSE), &((*command)[n]));
	return (TRUE);
}

extern t_bool		ft_ssl_init(t_command **command, t_pchar type)
{
	if (!command)
		return (FALSE);
	if (!ft_strcmp(type, "md5") && ft_ssl_init_hash(command, &ft_md5_main))
		return (TRUE);
	if (!ft_strcmp(type, "sha256")
			&& ft_ssl_init_hash(command, &ft_sha256_main))
		return (TRUE);
	if (!ft_strcmp(type, "whirlpool")
			&& ft_ssl_init_hash(command, &ft_whirlpool_main))
		return (TRUE);
	return (FALSE);
}
