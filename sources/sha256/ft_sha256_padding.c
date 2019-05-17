/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:48:13 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/16 14:14:54 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal/sha256.h"

static uint32_t	reverse_uint32(uint32_t n)
{
	return ((n >> 24) | ((n & 0xff0000) >> 8)
	| ((n & 0xff00) << 8) | (n << 24));
}

extern t_bool	ft_sha256_padding(t_sha256_var *var, t_pchar string)
{
	uint32_t	i;

	i = 0;
	(*var).new_len = ft_strlen(string) * 8;
	(*var).offset = 1 + (((*var).new_len) / 448);
	if (!((*var).msg_32 = malloc(32 * (*var).offset * 2)))
		return (-1);
	ft_bzero((*var).msg_32, 32 * (*var).offset * 2);
	ft_strcpy((char *)(*var).msg_32, string);
	((char*)(*var).msg_32)[ft_strlen(string)] = 0x80;
	while (i < ((*var).offset * 16) - 1)
	{
		(*var).msg_32[i] = reverse_uint32((*var).msg_32[i]);
		i++;
	}
	(*var).msg_32[(((*var).offset * 512 - 64) / 32)
	+ 1] = (*var).new_len;
	return (TRUE);
}
