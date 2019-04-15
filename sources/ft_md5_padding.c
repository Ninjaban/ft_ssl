//
// Created by Jonathan CARRA on 2019-04-15.
//

#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal.h"

static void			ft_md5_padding_set_block(t_pchar **block, t_pchar string, t_uint n, t_uint i)
{
	int		j;

	j = 0;
	while (i < 64 && string[j])
	{
		(*block)[n][i] = string[j];
		i = i + 1;
		j = j + 1;
	}
	if (i < 64)
	{
		while (i < 63)
		{
			(*block)[n][i] = 0;
			i = i + 1;
		}
		(*block)[n][i] = 1;
	}
}

static void			ft_md5_padding_set_size(t_pchar **block, size_t size)
{
	int		n;
	int		i;

	i = 0;
	n = 7;
	while (n >= 0)
	{
		(*block)[0][n] = (size>>(i*8))&0xFF;

		i = i + 1;
		n = n - 1;
	}
}

extern t_bool		ft_md5_padding(t_md5 *md5, t_pchar string)
{
	t_pchar		*block;
	size_t		size;
	t_uint		n;

	if (!string)
	{
		FT_ERROR("string %p", (void *)string);
		return (FALSE);
	}

	FT_DEBUG("sizeof size_t %zu", sizeof(size_t));
	size = ((ft_strlen(string) + ft_nbrlen(ft_strlen(string))) / 64 + 1);
	if ((block = malloc(sizeof(t_pchar) * size)) == NULL)
	{
		FT_ERROR("malloc() failed size %zu", sizeof(t_pchar) * size);
		return (FALSE);
	}
	n = 0;
	while (n < size)
		if ((block[n++] = malloc(64)) == NULL)
		{
			FT_ERROR("malloc() failed size %d", 64);
			return (FALSE);
		}

	ft_md5_padding_set_size(&block, ft_strlen(string));
	ft_md5_padding_set_block(&block, string, 0, 8);
	for (t_uint i = 0 ; i < 64 ; ++ i)
		FT_DEBUG("%d\t%c", block[0][i], block[0][i]);
	n = 1;
	while (n < size)
	{
		ft_md5_padding_set_block(&block, string + (n * 64), n, 0);
		FT_DEBUG("block {%.*s} n %u", 64, block[n], n);
		n = n + 1;
	}

	if (!ft_md5_loop(md5, block, (t_uint)size))
	{
		FT_WARNING("ft_md5_loop() failed %s", "");
		return (FALSE);
	}


	return (TRUE);
}