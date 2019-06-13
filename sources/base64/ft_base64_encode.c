/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_encode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:45:35 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/25 12:15:49 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "internal/base64.h"
#include <stdio.h>

static t_bool		ft_b64_pad(t_pchar string, t_b64 *b64, t_b64_var *b64_var)
{
	(*b64_var).len = ft_strlen(string);
	(*b64_var).padCount = (*b64_var).len % 3;
	(*b64).resultLen = ((*b64_var).len * 4 / 3) + (*b64_var).padCount;
	if (!((*b64).result = malloc(sizeof(char) * (*b64).resultLen)))
		return (FALSE);
	return (TRUE);
}

static t_bool		ft_b64_attribution(t_b64 *b64, t_b64_var *b64_var)
{
	if ((*b64_var).resultInd >= (*b64).resultLen)
		return (FALSE);
	(*b64).result[(*b64_var).resultInd++] = (*b64_var).b64chars[(*b64).n0];
	if ((*b64_var).resultInd >= (*b64).resultLen)
		return (FALSE);
	(*b64).result[(*b64_var).resultInd++] = (*b64_var).b64chars[(*b64).n1];
	if (((*b64_var).x + 1) < (*b64_var).len)
	{
		if ((*b64_var).resultInd >= (*b64).resultLen)
			return (FALSE);
		(*b64).result[(*b64_var).resultInd++] = (*b64_var).b64chars[(*b64).n2];
	}
	if (((*b64_var).x + 2) < (*b64_var).len)
	{
		if ((*b64_var).resultInd >= (*b64).resultLen)
			return (FALSE);
		(*b64).result[(*b64_var).resultInd++] = (*b64_var).b64chars[(*b64).n3];
	}
	return (TRUE);
}

static t_bool		ft_b64_algo(t_pchar string, t_b64 *b64, t_b64_var *b64_var)
{
	(*b64_var).resultInd = 0;
	(*b64_var).x = 0;
	(*b64_var).n = 0;
	while ((*b64_var).x < ft_strlen(string))
	{
		(*b64_var).n = ((uint32_t)string[(*b64_var).x]) << 16;
		if (((*b64_var).x + 1) < (*b64_var).len)
			(*b64_var).n += ((uint32_t)string[(*b64_var).x + 1]) << 8;
		if (((*b64_var).x + 2) < (*b64_var).len)
			(*b64_var).n += string[(*b64_var).x + 2];
		(*b64).n0 = (uint8_t)((*b64_var).n >> 18) & 63;
		(*b64).n1 = (uint8_t)((*b64_var).n >> 12) & 63;
		(*b64).n2 = (uint8_t)((*b64_var).n >> 6) & 63;
		(*b64).n3 = (uint8_t)(*b64_var).n & 63;
		if (!ft_b64_attribution(b64, b64_var))
			return (FALSE);
		(*b64_var).x = (*b64_var).x + 3;
	}
	while ((*b64_var).padCount < 3)
	{
		(*b64).result[(*b64_var).resultInd++] = '=';
		(*b64_var).padCount++;
	}
	return (TRUE);
}

static t_bool		ft_b64_init(t_b64_var *base64_var)
{
	t_uint			n;
	const char		b64chars[] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
		'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b',
		'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
		'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3',
		'4', '5', '6', '7', '8', '9', '+', '/'};

	n = 0;
	while (n < 64)
	{
		(*base64_var).b64chars[n] = b64chars[n];
		n = n + 1;
	}
	return (TRUE);
}

extern t_bool		ft_b64_encode(t_pchar string, t_pchar *out)
{
	t_b64			b64;
	t_b64_var		b64_var;

	if (!ft_b64_init(&b64_var))
		return (FALSE);
	if (!ft_b64_pad(string, &b64, &b64_var))
		return (FALSE);
	if (!ft_b64_algo(string, &b64, &b64_var))
		return (FALSE);
	*out = (b64).result;
	return (TRUE);
}
