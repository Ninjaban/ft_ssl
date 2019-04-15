//
// Created by Jonathan CARRA on 2019-04-15.
//

#include <stdlib.h>
#include <libft.h>

#include "types.h"
#include "error.h"
#include "internal.h"

static t_bool		ft_md5_loop_init(int **w, t_pchar string)
{
	t_uint		n;
	int			tmp;

	if ((*w = malloc(sizeof(int) * 16)) == NULL)
	{
		FT_ERROR("malloc() failed size %zu", sizeof(int) * 16);
		return (FALSE);
	}
	ft_memset(*w, 0, sizeof(int) * 16);

	n = 0;
	while (n < 64)
	{
		tmp = string[n] << ((3 - n % 4) * 8);
		(*w)[n / 4] = (*w)[n / 4]|tmp;
		n = n + 1;
	}

	return (TRUE);
}

static int32_t		leftRotate(int n, unsigned int d)
{
	/* In n<<d, last d bits are 0. To put first 3 bits of n at
	  last, do bitwise or of n<<d with n >>(INT_BITS - d) */
	return (n << d)|(n >> (32 - d));
}

static void			ft_md5_loop_main(t_md5 md5, const int *w, t_md5_var *var)
{
	int32_t		f;
	int32_t		g;
	int32_t		tmp;
	t_uint		i;

	i = 0;
	while (i < 64)
	{
		if (i < 16)
		{
			f = ((*var).b&(*var).c)|((~(*var).b)&(*var).d);
			g = i;
		}
		else if (i < 32)
		{
			f = ((*var).d&(*var).b)|((~(*var).d)&(*var).c);
			g = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			f = (*var).b^(*var).c^(*var).d;
			g = (3 * i + 5) % 16;
		}
		else
		{
			f = (*var).c^((*var).b|(~(*var).d));
			g = (7 * i) % 16;
		}
		tmp = (*var).d;
		(*var).d = (*var).c;
		(*var).c = (*var).b;
		(*var).b = (((*var).a + f + md5.k[i] + w[g]) * leftRotate(md5.r[i], 25)) + (*var).b;
		(*var).a = tmp;

		i = i + 1;
	}
}

extern t_bool		ft_md5_loop(t_md5 *md5, t_pchar *block, t_uint size)
{
	int			*w;
	t_md5_var	var;

	if (size == 0)
		return (TRUE);

	if (!ft_md5_loop_init(&w, *block))
	{
		FT_WARNING("ft_md5_loop_init() failed %s", "");
		return (FALSE);
	}

	var.a = (*md5).h0;
	var.b = (*md5).h1;
	var.c = (*md5).h2;
	var.d = (*md5).h3;

	// LOOP
	ft_md5_loop_main(*md5, w, &var);

	(*md5).h0 += var.a;
	(*md5).h1 += var.b;
	(*md5).h2 += var.c;
	(*md5).h3 += var.d;

	ft_md5_loop(md5, block + 1, size - 1);
	return (TRUE);
}