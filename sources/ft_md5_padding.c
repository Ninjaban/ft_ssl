//
// Created by Jonathan CARRA on 2019-04-15.
//

#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal.h"

extern t_bool		ft_md5_padding(t_md5 *md5, t_pchar string)
{
	t_pchar		block;
	size_t		block_size;
	size_t		string_len;
	t_uint		add1;

	if (!string)
	{
		FT_ERROR("string %p", (void *)string);
		return (FALSE);
	}

	string_len = ft_strlen(string);
	block_size = string_len * 8 + 1;
	while (block_size % 512 != 448)
		block_size = block_size + 1;
	block_size = block_size / 8;
	if ((block = malloc(block_size + 64)) == NULL)
	{
		FT_ERROR("malloc() failed block_size %zu", block_size);
		return (FALSE);
	}

	ft_memcpy(block, string, string_len);
	block[string_len] = 128;
	ft_memcpy(block+string_len, &add1, 1);
	ft_memcpy(block+56*block_size, &string_len, 8);
	for (t_uint i = 0 ; i < (56*block_size)+8 ; ++ i)
		FT_DEBUG("%d\t%c", block[i], block[i]);

	if (!ft_md5_loop(md5, block, block_size))
	{
		FT_WARNING("ft_md5_loop() failed %s", "");
		return (FALSE);
	}


	return (TRUE);
}