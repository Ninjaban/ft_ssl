/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:28:44 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/18 13:15:53 by nsikora          ###   ########.fr       */
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
	ft_ssl_init_add_cmd("-p", &ft_ssl_tools_stdin, ninit(0, FALSE, NULL),
						&((*command)[n++]));
	ft_ssl_init_add_default(ft_strsplit("-s ARGS", " "), &((*command)[n - 1]));
	ft_ssl_init_add_launch(function, &((*command)[n++]));
	ft_ssl_init_add_cmd("-s", NULL, ninit(1, TRUE, NULL), &((*command)[n++]));
	ft_ssl_init_add_launch(function, &((*command)[n++]));
	ft_ssl_init_add_cmd("ARGS", NULL, ninit(0, FALSE, NULL), &((*command)[n++]));
	ft_ssl_init_add_launch(function, &((*command)[n++]));
	ft_ssl_init_add_cmd("PRINT", &ft_ssl_print, ninit(0, FALSE, NULL),
						&((*command)[n++]));
	ft_ssl_init_add_cmd("-r", NULL, ninit(0, FALSE, NULL), &((*command)[n++]));
	ft_ssl_init_add_cmd("-q", NULL, ninit(0, FALSE, NULL), &((*command)[n++]));
	ft_ssl_init_add_cmd(NULL, NULL, ninit(0, FALSE, NULL), &((*command)[n]));
	return (TRUE);
}

static t_bool		ft_ssl_init_base64(t_command **command, void (*function))
{
	int		n;

	if ((*command = malloc(sizeof(t_command) * 11)) == NULL)
		return (FALSE);
	n = 0;
	ft_ssl_init_add_cmd("MODE", &ft_ssl_base64_mode, ninit(0, FALSE, NULL), &((*command)[n++]));
	(*command)[n - 1].active = TRUE;
	ft_ssl_init_add_cmd("STDIN", &ft_ssl_tools_stdin, ninit(0, FALSE, NULL), &((*command)[n++]));
	ft_ssl_init_add_default(ft_strsplit("-i", " "), &((*command)[n - 1]));
	ft_ssl_init_add_launch(function, &((*command)[n++]));
	ft_ssl_init_add_cmd("-i", &ft_ssl_tools_file, ninit(1, FALSE, NULL), &((*command)[n++]));
	ft_ssl_init_add_launch(function, &((*command)[n++]));
	ft_ssl_init_add_cmd("PRINT", &ft_ssl_print, ninit(0, FALSE, NULL), &((*command)[n++]));
	ft_ssl_init_add_cmd("-o", &ft_ssl_print_file, ninit(1, FALSE, NULL), &((*command)[n++]));
	ft_ssl_init_add_cmd("-d", &ft_base64_decode, ninit(0, FALSE, ft_strsplit("-e", " ")), &((*command)[n++]));
	ft_ssl_init_add_cmd("-e", &ft_base64_encode, ninit(0, FALSE, ft_strsplit("-d", " ")), &((*command)[n++]));
	ft_ssl_init_add_default(ft_strsplit("-d", " "), &((*command)[n - 1]));
	ft_ssl_init_add_cmd("-q", NULL, ninit(0, FALSE, NULL), &((*command)[n++]));
	ft_ssl_init_add_default(NULL, &((*command)[n - 1]));
	ft_ssl_init_add_cmd(NULL, NULL, ninit(0, FALSE, NULL), &((*command)[n]));
	return (TRUE);
}

extern t_bool		ft_ssl_init(t_command **command, t_pchar type)
{
	if (!command)
		return (FALSE);
	if (!ft_strcmp(type, "md5")
			&& ft_ssl_init_hash(command, &ft_md5_main))
		return (TRUE);
	if (!ft_strcmp(type, "sha256")
			&& ft_ssl_init_hash(command, &ft_sha256_main))
		return (TRUE);
	if (!ft_strcmp(type, "whirlpool")
			&& ft_ssl_init_hash(command, &ft_whirlpool_main))
		return (TRUE);
	if (!ft_strcmp(type, "base64")
			&& ft_ssl_init_base64(command, NULL))
		return (TRUE);
	return (FALSE);
}
