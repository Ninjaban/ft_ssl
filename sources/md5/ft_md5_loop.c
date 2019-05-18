/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:50 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 13:15:54 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal/md5.h"

static void			ft_md5_loop_main_i(t_md5_var *var, uint32_t *f,
										uint32_t *g, t_uint i)
{
	if (i < 16)
	{
		*f = ((*var).b & (*var).c) | ((~(*var).b) & (*var).d);
		*g = i;
	}
	else if (i < 32)
	{
		*f = ((*var).d & (*var).b) | ((~(*var).d) & (*var).c);
		*g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		*f = (*var).b ^ (*var).c ^ (*var).d;
		*g = (3 * i + 5) % 16;
	}
	else
	{
		*f = (*var).c ^ ((*var).b | (~(*var).d));
		*g = (7 * i) % 16;
	}
}

static void			ft_md5_loop_main(t_md5 md5, const int *w, t_md5_var *var)
{
	uint32_t	f;
	uint32_t	g;
	uint32_t	tmp;
	t_uint		i;

	i = 0;
	while (i < 64)
	{
		ft_md5_loop_main_i(var, &f, &g, i);
		tmp = (*var).d;
		(*var).d = (*var).c;
		(*var).c = (*var).b;
		(*var).b = (LEFTROTATE(((*var).a + f + md5.k[i] + w[g]), md5.r[i])) +
					(*var).b;
		(*var).a = tmp;
		i = i + 1;
	}
}

extern t_bool		ft_md5_loop(t_md5 *md5, t_puchar block, size_t size)
{
	size_t		offset;
	int			*w;
	t_md5_var	var;

	offset = 0;
	while (offset < size)
	{
		w = (int *)(block + offset);
		var.a = (*md5).h0;
		var.b = (*md5).h1;
		var.c = (*md5).h2;
		var.d = (*md5).h3;
		ft_md5_loop_main(*md5, w, &var);
		(*md5).h0 += var.a;
		(*md5).h1 += var.b;
		(*md5).h2 += var.c;
		(*md5).h3 += var.d;
		offset = offset + 64;
	}
	return (TRUE);
}
