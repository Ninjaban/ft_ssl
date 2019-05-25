/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:47:34 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/25 12:15:49 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal/sha256.h"

static void		ft_sha256_loop_init(t_sha256 *sha256, t_sha256_var *var, int i)
{
	int			j;

	(*var).a = (*sha256).h0;
	(*var).b = (*sha256).h1;
	(*var).c = (*sha256).h2;
	(*var).d = (*sha256).h3;
	(*var).e = (*sha256).h4;
	(*var).f = (*sha256).h5;
	(*var).g = (*sha256).h6;
	(*var).h = (*sha256).h7;
	(*var).w = malloc(512);
	ft_bzero((*var).w, 512);
	ft_memcpy((*var).w, &(*var).msg_32[i * 16], 16 * 32);
	j = 16;
	while (j < 64)
	{
		(*var).o0 = RIGHTROTATE((*var).w[j - 15], 7) ^
		RIGHTROTATE((*var).w[j - 15], 18) ^ ((*var).w[j - 15] >> 3);
		(*var).o1 = RIGHTROTATE((*var).w[j - 2], 17) ^
		RIGHTROTATE((*var).w[j - 2], 19) ^ ((*var).w[j - 2] >> 10);
		(*var).w[j] = (*var).w[j - 16] + (*var).o0
		+ (*var).w[j - 7] + (*var).o1;
		j++;
	}
}

static void		sha256_algo(t_sha256 *sha256, t_sha256_var *var, int j)
{
	(*var).ch = ((*var).e & (*var).f) ^ ((~(*var).e) & (*var).g);
	(*var).maj = ((*var).a & (*var).b) ^ ((*var).a & (*var).c)
	^ ((*var).b & (*var).c);
	(*var).e0 = RIGHTROTATE((*var).a, 2) ^ RIGHTROTATE((*var).a, 13)
	^ RIGHTROTATE((*var).a, 22);
	(*var).e1 = RIGHTROTATE((*var).e, 6) ^ RIGHTROTATE((*var).e, 11)
	^ RIGHTROTATE((*var).e, 25);
	(*sha256).t1 = (*var).h + (*var).e1 + (*var).ch + (*sha256).k[j]
	+ (*var).w[j];
	(*sha256).t2 = (*var).e0 + (*var).maj;
	(*var).h = (*var).g;
	(*var).g = (*var).f;
	(*var).f = (*var).e;
	(*var).e = (*var).d + (*sha256).t1;
	(*var).d = (*var).c;
	(*var).c = (*var).b;
	(*var).b = (*var).a;
	(*var).a = (*sha256).t1 + (*sha256).t2;
}

extern t_bool	ft_sha256_loop_main(t_sha256 *sha256, t_sha256_var *var)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < (*var).offset)
	{
		ft_sha256_loop_init(sha256, var, i);
		j = -1;
		while (++j < 64)
			sha256_algo(sha256, var, j);
		(*sha256).h0 += (*var).a;
		(*sha256).h1 += (*var).b;
		(*sha256).h2 += (*var).c;
		(*sha256).h3 += (*var).d;
		(*sha256).h4 += (*var).e;
		(*sha256).h5 += (*var).f;
		(*sha256).h6 += (*var).g;
		(*sha256).h7 += (*var).h;
		free((*var).w);
		i++;
	}
	free((*var).msg_32);
	return (TRUE);
}
