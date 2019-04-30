#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal/sha256.h"

static void		ft_sha256_loop_init(t_sha256 *sha256, t_sha256_var *sha256_var, int i)
{
	int j;

	(*sha256_var).w = malloc(512);
	ft_bzero((*sha256_var).w, 512);
	ft_memcpy((*sha256_var).w, &(*sha256_var).msg_32[i * 16], 16 * 32);
	j = 16;
	while (j < 64)
	{
		(*sha256_var).e0 = rightRotate((*sha256_var).w[j - 15], 7) ^
		rightRotate((*sha256_var).w[j - 15], 18) ^ ((*sha256_var).w[j - 15] >> 3);
		(*sha256_var).e1 = rightRotate((*sha256_var).w[j - 2], 17) ^
		rightRotate((*sha256_var).w[j - 2], 19) ^ ((*sha256_var).w[j - 2] >> 10);
		(*sha256_var).w[j] = (*sha256_var).w[j - 16] + (*sha256_var).e0
        + (*sha256_var).w[j - 7] + (*sha256_var).e1;
		j++;
	}
	(*sha256_var).a = (*sha256).h0;
	(*sha256_var).b = (*sha256).h1;
	(*sha256_var).c = (*sha256).h2;
	(*sha256_var).d = (*sha256).h3;
	(*sha256_var).e = (*sha256).h4;
	(*sha256_var).f = (*sha256).h5;
	(*sha256_var).g = (*sha256).h6;
	(*sha256_var).h = (*sha256).h7;
}

static void		sha256_algo(t_sha256 *sha256, t_sha256_var *sha256_var, int j)
{
	(*sha256_var).e1 = rightRotate((*sha256_var).e, 6) ^ rightRotate((*sha256_var).e, 11) ^ rightRotate((*sha256_var).e, 25);
	(*sha256_var).ch = ((*sha256_var).e & (*sha256_var).f) ^ ((~(*sha256_var).e) & (*sha256_var).g);
	(*sha256).t1 = (*sha256_var).h + (*sha256_var).e1 + (*sha256_var).ch + (*sha256).k[j] + (*sha256_var).w[j];
	(*sha256_var).e0 = rightRotate((*sha256_var).a, 2) ^ rightRotate((*sha256_var).a, 13) ^ rightRotate((*sha256_var).a, 22);
	(*sha256_var).maj = ((*sha256_var).a & (*sha256_var).b) ^ ((*sha256_var).a & (*sha256_var).c) ^ ((*sha256_var).b & (*sha256_var).c);
	(*sha256).t2 = (*sha256_var).e0 + (*sha256_var).maj;
	(*sha256_var).h = (*sha256_var).g;
	(*sha256_var).g = (*sha256_var).f;
	(*sha256_var).f = (*sha256_var).e;
	(*sha256_var).e = (*sha256_var).d + (*sha256).t1;
	(*sha256_var).d = (*sha256_var).c;
	(*sha256_var).c = (*sha256_var).b;
	(*sha256_var).b = (*sha256_var).a;
	(*sha256_var).a = (*sha256).t1 + (*sha256).t2;
}

extern t_bool       ft_sha256_loop_main(t_sha256 *sha256, t_sha256_var *sha256_var)
{
    size_t             i;
    size_t             j;

    i = 0;
    j = 0;
	while (i < (*sha256_var).offset)
	{
		ft_sha256_loop_init(sha256, sha256_var, i);
		j = -1;
		while (++j < 64)
			sha256_algo(sha256, sha256_var, j);
        (*sha256).h0 += (*sha256_var).a;
		(*sha256).h1 += (*sha256_var).b;
		(*sha256).h2 += (*sha256_var).c;
		(*sha256).h3 += (*sha256_var).d;
		(*sha256).h4 += (*sha256_var).e;
		(*sha256).h5 += (*sha256_var).f;
		(*sha256).h6 += (*sha256_var).g;
		(*sha256).h7 += (*sha256_var).h;
		free((*sha256_var).w);
		i++;
	}
    free((*sha256_var).msg_32);
    return(TRUE);
}
