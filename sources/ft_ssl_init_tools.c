/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_init_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:24:25 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 13:15:53 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	(*command).exclusif = ninit.exclusif;
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
	(*command).exclusif = NULL;
	(*command).defaut.is_default = FALSE;
	(*command).defaut.list = NULL;
}

extern void			ft_ssl_init_add_default(t_pchar *list, t_command *command)
{
	(*command).defaut.is_default = TRUE;
	(*command).defaut.list = list;
}

extern t_ninit		ninit(t_uint param_offset, t_bool end_flags, t_pchar *exclusif)
{
	t_ninit		ninit;

	ninit.param_offset = param_offset;
	ninit.end_flags = end_flags;
	ninit.exclusif = exclusif;
	return (ninit);
}
