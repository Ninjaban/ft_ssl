//
// Created by Jonathan CARRA on 2019-04-15.
//

#include "types.h"
#include "error.h"
#include "internal.h"
#include <math.h>

static void			ft_md5_init_set_r(t_md5 *md5, t_uint n, const int32_t tab[4])
{
	t_uint		i;

	i = n;
	while (i - n < 16)
	{
		(*md5).r[i] = tab[(i - n) % 4];
		i = i + 1;
	}
}

static void			ft_md5_init_set_k(t_md5 *md5)
{
	t_uint		n;

	n = 0;
	while (n <= 63)
	{
		(*md5).k[n] = floor(fabs(sin(n + 1)) * pow(2, 32));
		n = n + 1;
	}
}

extern t_bool		ft_md5_init(t_md5 *md5)
{
	const int32_t		t0[4] = {7, 12, 17, 22};
	const int32_t		t1[4] = {5,  9, 14, 20};
	const int32_t		t2[4] = {4, 11, 16, 23};
	const int32_t		t3[4] = {6, 10, 15, 21};

	if (!md5)
	{
		FT_ERROR("md5 %p", md5);
		return (FALSE);
	}
	ft_md5_init_set_r(md5,  0, t0);
	ft_md5_init_set_r(md5, 16, t1);
	ft_md5_init_set_r(md5, 32, t2);
	ft_md5_init_set_r(md5, 48, t3);
	ft_md5_init_set_k(md5);
	(*md5).h0 = 0x67452301;
	(*md5).h1 = 0xEFCDAB89;
	(*md5).h2 = 0x98BADCFE;
	(*md5).h3 = 0x10325476;
	return (TRUE);
}