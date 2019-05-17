/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whirlpool_finalize.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:22 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/17 09:04:10 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "internal/whirlpool.h"

static void			ft_whirlpool_finalize_digest(t_whirlpool *out_whirlpool,
													uint8_t *digest)
{
	int			i;

	i = 0;
	while (i < DIGESTBYTES / 8)
	{
		digest[0] = (uint8_t)(out_whirlpool->hash[i] >> 56);
		digest[1] = (uint8_t)(out_whirlpool->hash[i] >> 48);
		digest[2] = (uint8_t)(out_whirlpool->hash[i] >> 40);
		digest[3] = (uint8_t)(out_whirlpool->hash[i] >> 32);
		digest[4] = (uint8_t)(out_whirlpool->hash[i] >> 24);
		digest[5] = (uint8_t)(out_whirlpool->hash[i] >> 16);
		digest[6] = (uint8_t)(out_whirlpool->hash[i] >> 8);
		digest[7] = (uint8_t)(out_whirlpool->hash[i]);
		digest += 8;
		i = i + 1;
	}
}

extern void			ft_whirlpool_finalize(t_whirlpool *out_whirlpool,
											uint8_t *digest)
{
	uint8_t		*buffer;
	int			buffer_bits;
	int			buffer_pos;

	buffer = out_whirlpool->buffer;
	buffer_bits = out_whirlpool->buffer_bits;
	buffer_pos = out_whirlpool->buffer_pos;
	buffer[buffer_pos++] |= 0x80U >> (buffer_bits & 7);
	if (buffer_pos > WBLOCKBYTES - LENGTHBYTES)
	{
		if (buffer_pos < WBLOCKBYTES)
			ft_memset(&buffer[buffer_pos], 0, WBLOCKBYTES - buffer_pos);
		ft_whirlpool_process(out_whirlpool);
		buffer_pos = 0;
	}
	if (buffer_pos < WBLOCKBYTES - LENGTHBYTES)
		ft_memset(&buffer[buffer_pos], 0,
				(WBLOCKBYTES - LENGTHBYTES) - buffer_pos);
	buffer_pos = WBLOCKBYTES - LENGTHBYTES;
	ft_memcpy(&buffer[WBLOCKBYTES - LENGTHBYTES], out_whirlpool->bit_length,
			LENGTHBYTES);
	ft_whirlpool_process(out_whirlpool);
	ft_whirlpool_finalize_digest(out_whirlpool, digest);
	out_whirlpool->buffer_bits = buffer_bits;
	out_whirlpool->buffer_pos = buffer_pos;
}
