
#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal.h"

extern t_bool		ft_sha256_padding(t_sha256 *sha256, t_pchar string)
{
    t_puchar	block;
	size_t		block_size;
	size_t		string_len;
	size_t		string_len_bit;

	(*sha256).h0 = 0x6a09e667;
	(*sha256).h1 = 0xbb67ae85;
	(*sha256).h2 = 0x3c6ef372;
	(*sha256).h3 = 0xa54ff53a;
	(*sha256).h4 = 0x510e527f;
	(*sha256).h5 = 0x9b05688c;
	(*sha256).h6 = 0x1f83d9ab;
    (*sha256).h7 = 0x5be0cd19;

    if (!string)
		return (FALSE);
	string_len = ft_strlen(string);
	block_size = string_len * 8 + 1;
	while (block_size % 512 != 448)
		block_size = block_size + 1;
	block_size = block_size / 8;
	if ((block = malloc(block_size + 64)) == NULL)
		return (FALSE);
	ft_memset(block, 0, block_size + 64);
	ft_memcpy(block, string, string_len);
	block[string_len] = 128;
	string_len_bit = string_len * 8;
	ft_memcpy(block + block_size, &string_len_bit, 4);
	if (!ft_sha256_loop(sha256, block, block_size))
		return (FALSE);
	free(block);
	return (TRUE);
}