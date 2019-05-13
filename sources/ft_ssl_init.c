/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:28:44 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/13 09:48:25 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "internal.h"

static void			ft_ssl_init_add_cmd(t_pchar name, void (*function),
								t_ninit ninit, t_command *command)
{
	(*command).name = name;
	(*command).active = FALSE;
	(*command).function = function;
	(*command).param = NULL;
	(*command).param_offset = ninit.param_offset;
	(*command).end_flags = ninit.end_flags;
	(*command).defaut.is_default = FALSE;
	(*command).defaut.list = NULL;
}

static void			ft_ssl_init_add_launch(void (*function), t_command *command)
{
	(*command).name = "LAUNCH";
	(*command).active = FALSE;
	(*command).function = function;
	(*command).param = NULL;
	(*command).param_offset = 0;
	(*command).end_flags = FALSE;
}

static void			ft_ssl_init_add_default(t_pchar *list, t_command *command)
{
	(*command).defaut.is_default = TRUE;
	(*command).defaut.list = list;
}

static t_ninit		ninit(t_uint param_offset, t_bool end_flags)
{
	t_ninit		ninit;

	ninit.param_offset = param_offset;
	ninit.end_flags = end_flags;
	return (ninit);
}

static t_bool		ft_ssl_init_md5(t_command **command, void (*function))
{
	int		n;

	if ((*command = malloc(sizeof(t_command) * 10)) == NULL)
		return (FALSE);
	n = 0;
	ft_ssl_init_add_cmd("-p", &ft_ssl_tools_stdin, ninit(0, FALSE),
						&((*command)[n++]));
	ft_ssl_init_add_default(ft_strsplit("-s", " "), &((*command)[n - 1]));
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
	if (!ft_strcmp(type, "md5") && ft_ssl_init_md5(command, &ft_md5_main))
		return (TRUE);
	if (!ft_strcmp(type, "sha256") && ft_ssl_init_md5(command, &ft_sha256_main))
		return (TRUE);
	if (!ft_strcmp(type, "whirlpool") &&
		ft_ssl_init_md5(command, &ft_whirlpool_main))
		return (TRUE);
	return (FALSE);
}
