/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:48 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/25 12:15:49 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "error.h"
#include "internal/md5.h"

static void			ft_md5_init_set_r(t_md5 *md5, t_uint n,
										const int32_t tab[4])
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
	t_uint			n;
	const uint32_t	k[] = {
			0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
			0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
			0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
			0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
			0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
			0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
			0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
			0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
			0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
			0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
			0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
			0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
			0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
			0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
			0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
			0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

	n = 0;
	while (n < 64)
	{
		(*md5).k[n] = k[n];
		n = n + 1;
	}
}

extern t_bool		ft_md5_init(t_md5 *md5)
{
	const int32_t		t0[4] = {7, 12, 17, 22};
	const int32_t		t1[4] = {5, 9, 14, 20};
	const int32_t		t2[4] = {4, 11, 16, 23};
	const int32_t		t3[4] = {6, 10, 15, 21};

	if (!md5)
		return (FALSE);
	ft_md5_init_set_r(md5, 0, t0);
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
