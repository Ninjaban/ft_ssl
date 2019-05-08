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
