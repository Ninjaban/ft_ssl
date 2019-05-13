/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_init_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:24:25 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/13 10:25:48 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "error.h"
#include "internal.h"

extern void			ft_ssl_init_add_cmd(t_pchar name, void (*function),
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

extern void			ft_ssl_init_add_launch(void (*function), t_command *command)
{
	(*command).name = "LAUNCH";
	(*command).active = FALSE;
	(*command).function = function;
	(*command).param = NULL;
	(*command).param_offset = 0;
	(*command).end_flags = FALSE;
}

extern void			ft_ssl_init_add_default(t_pchar *list, t_command *command)
{
	(*command).defaut.is_default = TRUE;
	(*command).defaut.list = list;
}

extern t_ninit		ninit(t_uint param_offset, t_bool end_flags)
{
	t_ninit		ninit;

	ninit.param_offset = param_offset;
	ninit.end_flags = end_flags;
	return (ninit);
}
