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

static				t_bool	ft_base64_padding(t_pchar string, t_base64 *base64, t_base64_var *base64_var)
{
	(*base64_var).len = ft_strlen(string);
	(*base64_var).padCount = (*base64_var).len % 3;
	(*base64).resultLen = ((*base64_var).len * 4 / 3) + (*base64_var).padCount;
	if (!((*base64).result = malloc(sizeof(char) * (*base64).resultLen)))
		return (FALSE);
	return (TRUE);
}

static				t_bool	ft_base64_algo(t_pchar string, t_base64 *base64, t_base64_var *base64_var)
{
	const char		base64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	uint32_t		x;
	uint32_t		n;

	(*base64_var).resultIndex = 0;
	x = 0;
	n = 0;
	while (x < ft_strlen(string))
	{
		n = ((uint32_t)string[x]) << 16;
		if((x + 1) < (*base64_var).len)
			n += ((uint32_t)string[x+1]) << 8;
		if ((x + 2) < (*base64_var).len)
        	n += string[x+2];
		(*base64).n0 = (uint8_t)(n >> 18) & 63;
      	(*base64).n1 = (uint8_t)(n >> 12) & 63;
      	(*base64).n2 = (uint8_t)(n >> 6) & 63;
      	(*base64).n3 = (uint8_t)n & 63;

		if ((*base64_var).resultIndex >= (*base64).resultLen)
			return (FALSE);
		(*base64).result[(*base64_var).resultIndex++] = base64chars[(*base64).n0];
		if ((*base64_var).resultIndex >= (*base64).resultLen)
			return (FALSE);
		(*base64).result[(*base64_var).resultIndex++] = base64chars[(*base64).n1];
		if ((x+1) < (*base64_var).len)
		{
			if((*base64_var).resultIndex >= (*base64).resultLen)
				return (FALSE);
			(*base64).result[(*base64_var).resultIndex++] = base64chars[(*base64).n2];
		}
		if ((x+2) < (*base64_var).len)
		{
			if ((*base64_var).resultIndex >= (*base64).resultLen)
				return (FALSE);
			(*base64).result[(*base64_var).resultIndex++] = base64chars[(*base64).n3];
		}
		x = x + 3;
	}
	while ((*base64_var).padCount < 3)
	{
		(*base64).result[(*base64_var).resultIndex++] = '=';
		(*base64_var).padCount++;
	}
	return (TRUE);
}

extern 				t_bool	ft_base64_encode(t_pchar string, t_pchar *out)
{
	t_base64		base64;
	t_base64_var	base64_var;

	if (!ft_base64_padding(string, &base64, &base64_var))
		return (FALSE);
	if (!ft_base64_algo(string, &base64, &base64_var))
		return (FALSE);

	ft_putendl((base64).result);
	*out = ft_strdup("abcd");

	ft_putendl("encode...");
	ft_putendl(string);
	return (TRUE);
}
