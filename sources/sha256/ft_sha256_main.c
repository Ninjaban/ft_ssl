/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:47:48 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/15 12:51:07 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal/sha256.h"

static void			ft_sha256_main_result(t_sha256 sha256, t_pchar *out)
{
	uint32_t		p[8];
	t_uint			n;

	p[0] = sha256.h0;
	p[1] = sha256.h1;
	p[2] = sha256.h2;
	p[3] = sha256.h3;
	p[4] = sha256.h4;
	p[5] = sha256.h5;
	p[6] = sha256.h6;
	p[7] = sha256.h7;
	n = 0;
	while (n < 8)
	{
		ft_itohex(p[n], *out + (n * 8), 8);
		n++;
	}
	(*out)[64] = '\0';
}

extern t_bool		ft_sha256_main(t_pchar string, t_pchar *out)
{
	t_sha256		sha256;
	t_sha256_var	var;

	if (!out)
		return (FALSE);
	if (!ft_sha256_init(&sha256))
		return (FALSE);
	if (!ft_sha256_padding(&var, (string) ? string : ""))
		return (FALSE);
	if (!ft_sha256_loop_main(&sha256, &var))
		return (FALSE);
	if ((*out = malloc(64 + 1)) == NULL)
		return (FALSE);
	ft_sha256_main_result(sha256, out);
	return (TRUE);
}
