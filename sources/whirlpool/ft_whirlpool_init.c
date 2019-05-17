/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whirlpool_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:29 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/16 14:14:54 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "internal/whirlpool.h"

extern void			ft_whirlpool_init(t_whirlpool *out_whirlpool)
{
	int			i;

	ft_memset(out_whirlpool->bit_length, 0, 32);
	out_whirlpool->buffer_bits = 0;
	out_whirlpool->buffer_pos = 0;
	out_whirlpool->buffer[0] = 0;
	i = 0;
	while (i < 8)
		out_whirlpool->hash[i++] = 0L;
}
