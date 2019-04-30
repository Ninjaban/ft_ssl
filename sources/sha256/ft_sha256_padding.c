#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal/sha256.h"

extern t_bool	ft_sha256_padding(t_sha256_var *sha256_var, t_pchar string)
{
	uint32_t 		i;

	i = 0;
	(*sha256_var).new_len = ft_strlen(string) * 8;
	(*sha256_var).offset = 1 + (((*sha256_var).new_len + 16 + 64) / 512);
	if (!((*sha256_var).msg_32 = malloc(16 * (*sha256_var).offset * 4)))
		return (-1);
	ft_bzero((*sha256_var).msg_32, 16 * (*sha256_var).offset * 4);
	ft_strcpy((char *)(*sha256_var).msg_32, string);
	((char*)(*sha256_var).msg_32)[ft_strlen(string)] = 0x80;
	while (i < ((*sha256_var).offset * 16) - 1)
	{
		(*sha256_var).msg_32[i] = revers_uint32((*sha256_var).msg_32[i]);
		i++;
	}
	(*sha256_var).msg_32[(((*sha256_var).offset * 512 - 64) / 32) + 1] = (*sha256_var).new_len;
	return (TRUE);
}