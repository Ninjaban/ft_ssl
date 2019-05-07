/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:47:48 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/07 11:54:32 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal/sha256.h"

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
	snprintf(*out, 64 + 1, "%08x%08x%08x%08x%08x%08x%08x%08x",
	sha256.h0, sha256.h1, sha256.h2, sha256.h3,
	sha256.h4, sha256.h5, sha256.h6, sha256.h7);
	return (TRUE);
}
