/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:56 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 11:29:01 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal/md5.h"

extern t_bool		ft_md5_padding(t_md5 *md5, t_pchar string)
{
	t_puchar	block;
	size_t		block_size;
	size_t		string_len;
	size_t		string_len_bit;

	if (!string)
		return (FALSE);
	string_len = ft_strlen(string);
	block_size = string_len * 8 + 1;
	while (block_size % 512 != 448)
		block_size = block_size + 1;
	block_size = block_size / 8;
	if ((block = malloc(block_size + 64)) == NULL)
		return (FALSE);
	ft_memset(block, 0, block_size + 64);
	ft_memcpy(block, string, string_len);
	block[string_len] = 128;
	string_len_bit = string_len * 8;
	ft_memcpy(block + block_size, &string_len_bit, 4);
	if (!ft_md5_loop(md5, block, block_size))
		return (FALSE);
	free(block);
	return (TRUE);
}
