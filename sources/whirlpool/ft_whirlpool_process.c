
#include "types.h"
#include "internal/whirlpool.h"

static void			ft_whirlpool_process_buffer(uint64_t (*L)[8],
							const uint64_t state[8], const uint64_t K, int n)
{
	(*L)[n] = C0[(int)(state[n] >> 56)] ^
			C1[(int)(state[(n+7)%8] >> 48) & 0xff] ^
			C2[(int)(state[(n+6)%8] >> 40) & 0xff] ^
			C3[(int)(state[(n+5)%8] >> 32) & 0xff] ^
			C4[(int)(state[(n+4)%8] >> 24) & 0xff] ^
			C5[(int)(state[(n+3)%8] >> 16) & 0xff] ^
			C6[(int)(state[(n+2)%8] >> 8) & 0xff] ^
			C7[(int)(state[(n+1)%8]) & 0xff] ^ K;
}

static void			ft_whirlpool_process_loop(uint64_t (*state)[8],
												uint64_t K[8], int r)
{
	uint64_t		L[8];

	ft_whirlpool_process_buffer(&L, K, rc[r], 0);
	for (int n = 1 ; n < 8 ; ++ n)
		ft_whirlpool_process_buffer(&L, K, 0, n);

	for (int n = 0 ; n < 8 ; ++ n)
		K[n] = L[n];

	for (int n = 0 ; n < 8 ; ++ n)
		ft_whirlpool_process_buffer(&L, *state, K[n], n);

	for (int n = 0 ; n < 8 ; ++ n)
		(*state)[n] = L[n];
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
		(*block)[i] = (((uint64_t)buffer[0]) << 56) ^
				(((uint64_t)buffer[1] & 0xffL) << 48) ^
				(((uint64_t)buffer[2] & 0xffL) << 40) ^
				(((uint64_t)buffer[3] & 0xffL) << 32) ^
				(((uint64_t)buffer[4] & 0xffL) << 24) ^
				(((uint64_t)buffer[5] & 0xffL) << 16) ^
				(((uint64_t)buffer[6] & 0xffL) << 8) ^
				(((uint64_t)buffer[7] & 0xffL));
		buffer = buffer + 8;
		i = i + 1;
	}
}

extern void			ft_whirlpool_process(t_whirlpool *out_whirlpool)
{
	uint64_t		K[8];
	uint64_t		block[8];
	uint64_t		state[8];
	int				i;

	ft_whirlpool_process_block(out_whirlpool, &block);
	i = 0;
	while (i < 8)
	{
		state[i] = block[i] ^ (K[i] = out_whirlpool->hash[i]);
		i = i + 1;
	}
	i = 1;
	while (i <= R)
		ft_whirlpool_process_loop(&state, K, i++);
	i = 0;
	while (i < 8)
	{
		out_whirlpool->hash[i] ^= state[i] ^ block[i];
		i = i + 1;
	}
}
