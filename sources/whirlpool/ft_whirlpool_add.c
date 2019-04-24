
#include "types.h"
#include "internal/whirlpool.h"

static void			ft_whirlpool_add_length(uint64_t source_bits,
											t_whirlpool *out_whirlpool)
{
	int			i;
	uint32_t	carry;
	uint8_t		*bit_length;
	uint64_t	value;

	i = 31;
	carry = 0;
	bit_length = out_whirlpool->bitLength;
	value = source_bits;
	while (i >= 0 && (carry != 0 || value != LL(0)))
	{
		carry += bit_length[i] + ((uint32_t)value & 0xff);
		bit_length[i] = (uint8_t)carry;
		carry >>= 8;
		value >>= 8;
		i = i - 1;
	}
}

static void			ft_whirlpool_add_bits_digest(t_whirlpool *out_whirlpool,
													uint32_t *b)
{
	int		buffer_rem;

	buffer_rem = out_whirlpool->bufferBits & 7;
	out_whirlpool->buffer[out_whirlpool->bufferPos++] |=
			(uint8_t)(*b >> buffer_rem);
	out_whirlpool->bufferBits += 8 - buffer_rem;
	if (out_whirlpool->bufferBits == DIGESTBITS)
	{
		ft_whirlpool_process(out_whirlpool);
		out_whirlpool->bufferBits = 0;
		out_whirlpool->bufferPos = 0;
	}
	out_whirlpool->buffer[out_whirlpool->bufferPos] = *b << (8 - buffer_rem);
	out_whirlpool->bufferBits += buffer_rem;
}

static void			ft_whirlpool_add_bits(t_puchar source, uint64_t source_bits,
									t_whirlpool *out_whirlpool, uint32_t *b)
{
	int		buffer_rem;
	int		source_pos;
	int		source_gap;

	buffer_rem = out_whirlpool->bufferBits & 7;
	source_pos = 0;
	source_gap = (8 - ((int)source_bits & 7)) & 7;
	while (source_bits > 8)
	{
		*b = ((source[source_pos] << source_gap) & 0xff) |
			((source[source_pos + 1] & 0xff) >> (8 - source_gap));
		ft_whirlpool_add_bits_digest(out_whirlpool, b);
		source_bits -= 8;
		source_pos++;
	}
	if (source_bits > 0)
	{
		*b = (source[source_pos] << source_gap) & 0xff;
		out_whirlpool->buffer[out_whirlpool->bufferPos] |= *b >> buffer_rem;
	}
	else
		*b = 0;
}

static void			ft_whirlpool_add_buffer(uint64_t source_bits,
										t_whirlpool *out_whirlpool, uint32_t b)
{
	int		buffer_rem;

	buffer_rem = out_whirlpool->bufferBits & 7;
	if (buffer_rem + source_bits < 8)
		out_whirlpool->bufferBits += source_bits;
	else
	{
		out_whirlpool->bufferPos++;
		out_whirlpool->bufferBits += 8 - buffer_rem;
		source_bits -= 8 - buffer_rem;
		if (out_whirlpool->bufferBits == DIGESTBITS)
		{
			ft_whirlpool_process(out_whirlpool);
			out_whirlpool->bufferBits = 0;
			out_whirlpool->bufferPos = 0;
		}
		out_whirlpool->buffer[out_whirlpool->bufferPos] = b << (8 - buffer_rem);
		out_whirlpool->bufferBits += (int)source_bits;
	}
}

extern void			ft_whirlpool_add(t_puchar source, uint64_t source_bits,
										t_whirlpool *out_whirlpool)
{
	uint32_t		b;

	ft_whirlpool_add_length(source_bits, out_whirlpool);
	ft_whirlpool_add_bits(source, source_bits, out_whirlpool, &b);
	ft_whirlpool_add_buffer(source_bits, out_whirlpool, b);
}