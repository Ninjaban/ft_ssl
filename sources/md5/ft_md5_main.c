/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:53 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/16 14:14:54 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal/md5.h"

static void			ft_md5_main_result(t_md5 md5, t_pchar *out)
{
	uint8_t		*(p[4]);
	t_uint		n;
	t_uint		i;

	p[0] = (uint8_t *)&md5.h0;
	p[1] = (uint8_t *)&md5.h1;
	p[2] = (uint8_t *)&md5.h2;
	p[3] = (uint8_t *)&md5.h3;
	n = 0;
	i = 0;
	while (n < 4)
	{
		ft_itohex(p[n][i], *out + (n * 8) + (i * 2), 2);
		i = i + 1;
		if (i == 4)
		{
			i = 0;
			n = n + 1;
		}
	}
	(*out)[32] = '\0';
}

extern t_bool		ft_md5_main(t_pchar string, t_pchar *out)
{
	t_md5		md5;

	if (!out)
		return (FALSE);
	if (!ft_md5_init(&md5))
		return (FALSE);
	if (!ft_md5_padding(&md5, (string) ? string : ""))
		return (FALSE);
	if ((*out = malloc(32 + 1)) == NULL)
		return (FALSE);
	ft_md5_main_result(md5, out);
	return (TRUE);
}
