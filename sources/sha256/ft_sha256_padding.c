/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:48:13 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/07 11:57:39 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal/sha256.h"

extern t_bool	ft_sha256_padding(t_sha256_var *var, t_pchar string)
{
	uint32_t	i;

	i = 0;
	(*var).new_len = ft_strlen(string) * 8;
	(*var).offset = 1 + (((*var).new_len + 16 + 64) / 512);
	if (!((*var).msg_32 = malloc(16 * (*var).offset * 4)))
		return (-1);
	ft_bzero((*var).msg_32, 16 * (*var).offset * 4);
	ft_strcpy((char *)(*var).msg_32, string);
	((char*)(*var).msg_32)[ft_strlen(string)] = 0x80;
	while (i < ((*var).offset * 16) - 1)
	{
		(*var).msg_32[i] = REVERSEUINT32((*var).msg_32[i]);
		i++;
	}
	(*var).msg_32[(((*var).offset * 512 - 64) / 32)
	+ 1] = (*var).new_len;
	return (TRUE);
}
