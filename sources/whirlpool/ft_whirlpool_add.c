//
// Created by Jonathan CARRA on 2019-04-24.
//

#include "types.h"
#include "internal/whirlpool.h"

static void			ft_whirlpool_add_length(uint64_t sourceBits, t_whirlpool *out_whirlpool)
{
	int			i;
	uint32_t	carry;
	uint8_t		*bitLength;
	uint64_t	value;

	i = 31;
	carry = 0;
	bitLength = out_whirlpool->bitLength;
	value = sourceBits;
	while (i >= 0 && (carry != 0 || value != LL(0)))
	{
		carry += bitLength[i] + ((uint32_t)value & 0xff);
		bitLength[i] = (uint8_t)carry;
		carry >>= 8;
		value >>= 8;

		i = i - 1;
	}
}

static void			ft_whirlpool_add_bits_digest(t_whirlpool *out_whirlpool, uint32_t *b)
{
	int bufferRem;

	bufferRem = out_whirlpool->bufferBits & 7;
	out_whirlpool->buffer[out_whirlpool->bufferPos++] |= (uint8_t)(*b >> bufferRem);
	out_whirlpool->bufferBits += 8 - bufferRem;

	if (out_whirlpool->bufferBits == DIGESTBITS)
	{
		ft_whirlpool_process(out_whirlpool);
		out_whirlpool->bufferBits = 0;
		out_whirlpool->bufferPos = 0;
	}

	out_whirlpool->buffer[out_whirlpool->bufferPos] = *b << (8 - bufferRem);
	out_whirlpool->bufferBits += bufferRem;
}

static void			ft_whirlpool_add_bits(t_puchar source, uint64_t sourceBits, t_whirlpool *out_whirlpool, uint32_t *b)
{
	int bufferRem;
	int sourcePos;
	int sourceGap;

	bufferRem = out_whirlpool->bufferBits & 7;
	sourcePos = 0;
	sourceGap = (8 - ((int)sourceBits & 7)) & 7;
	while (sourceBits > 8)
	{
		*b = ((source[sourcePos] << sourceGap) & 0xff) |
			 ((source[sourcePos + 1] & 0xff) >> (8 - sourceGap));

		ft_whirlpool_add_bits_digest(out_whirlpool, b);

		sourceBits -= 8;
		sourcePos++;
	}

	if (sourceBits > 0)
	{
		*b = (source[sourcePos] << sourceGap) & 0xff;
		out_whirlpool->buffer[out_whirlpool->bufferPos] |= *b >> bufferRem;
	}
	else
		*b = 0;
}

static void			ft_whirlpool_add_buffer(uint64_t sourceBits, t_whirlpool *out_whirlpool, uint32_t b)
{
	int bufferRem;

	bufferRem = out_whirlpool->bufferBits & 7;
	if (bufferRem + sourceBits < 8)
		out_whirlpool->bufferBits += sourceBits;
	else
	{
		out_whirlpool->bufferPos++;
		out_whirlpool->bufferBits += 8 - bufferRem;
		sourceBits -= 8 - bufferRem;
		if (out_whirlpool->bufferBits == DIGESTBITS)
		{
			ft_whirlpool_process(out_whirlpool);
			out_whirlpool->bufferBits = out_whirlpool->bufferPos = 0;
		}
		out_whirlpool->buffer[out_whirlpool->bufferPos] = b << (8 - bufferRem);
		out_whirlpool->bufferBits += (int)sourceBits;
	}
}

extern void         ft_whirlpool_add(t_puchar source, uint64_t sourceBits, t_whirlpool *out_whirlpool)
{
	uint32_t		b;

	ft_whirlpool_add_length(sourceBits, out_whirlpool);
	ft_whirlpool_add_bits(source, sourceBits, out_whirlpool, &b);
	ft_whirlpool_add_buffer(sourceBits, out_whirlpool, b);
}

