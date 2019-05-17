/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whirlpool_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:39 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/17 09:04:10 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "internal/whirlpool.h"

static void			ft_whirlpool_process_buffer(uint64_t (*l)[8],
							const uint64_t state[8], const uint64_t k, int n)
{
	(*l)[n] = g_c0[(int)(state[n] >> 56u)]
			^ g_c1[(int)(state[(n + 7) % 8] >> 48u) & 0xff]
			^ g_c2[(int)(state[(n + 6) % 8] >> 40u) & 0xff]
			^ g_c3[(int)(state[(n + 5) % 8] >> 32u) & 0xff]
			^ g_c4[(int)(state[(n + 4) % 8] >> 24u) & 0xff]
			^ g_c5[(int)(state[(n + 3) % 8] >> 16u) & 0xff]
			^ g_c6[(int)(state[(n + 2) % 8] >> 8u) & 0xff]
			^ g_c7[(int)(state[(n + 1) % 8]) & 0xff] ^ k;
}

static void			ft_whirlpool_process_loop(uint64_t (*state)[8],
												uint64_t k[8], int r)
{
	uint64_t		l[8];
	int				n;

	ft_whirlpool_process_buffer(&l, k, g_rc[r], 0);
	n = 0;
	while (++n < 8)
		ft_whirlpool_process_buffer(&l, k, 0, n);
	n = -1;
	while (++n < 8)
		k[n] = l[n];
	n = -1;
	while (++n < 8)
		ft_whirlpool_process_buffer(&l, *state, k[n], n);
	n = -1;
	while (++n < 8)
		(*state)[n] = l[n];
}

static void			ft_whirlpool_process_block(t_whirlpool *out_whirlpool,
												uint64_t (*block)[8])
{
	uint8_t			*buffer;
	int				i;

	i = 0;
	buffer = out_whirlpool->buffer;
	while (i < 8)
	{
		(*block)[i] = (((uint64_t)buffer[0]) << 56u)
				^ (((uint64_t)buffer[1] & 0xffLLU) << 48u)
				^ (((uint64_t)buffer[2] & 0xffLLU) << 40u)
				^ (((uint64_t)buffer[3] & 0xffLLU) << 32u)
				^ (((uint64_t)buffer[4] & 0xffLLU) << 24u)
				^ (((uint64_t)buffer[5] & 0xffLLU) << 16u)
				^ (((uint64_t)buffer[6] & 0xffLLU) << 8u)
				^ (((uint64_t)buffer[7] & 0xffLLU));
		buffer = buffer + 8;
		i = i + 1;
	}
}

extern void			ft_whirlpool_process(t_whirlpool *out_whirlpool)
{
	uint64_t		k[8];
	uint64_t		block[8];
	uint64_t		state[8];
	int				i;

	ft_whirlpool_process_block(out_whirlpool, &block);
	i = 0;
	while (i < 8)
	{
		k[i] = out_whirlpool->hash[i];
		state[i] = block[i] ^ k[i];
		i = i + 1;
	}
	i = 1;
	while (i <= R)
		ft_whirlpool_process_loop(&state, k, i++);
	i = 0;
	while (i < 8)
	{
		out_whirlpool->hash[i] ^= state[i] ^ block[i];
		i = i + 1;
	}
}
