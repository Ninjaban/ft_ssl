
#include <stdio.h>
#include "libft.h"
#include "types.h"
#include "internal/whirlpool.h"

static void				ft_whirlpool_print(const uint8_t *array, int length,
											t_pchar *out)
{
	int		i;

	i = 0;
	while (i < length)
	{
		ft_itohex(array[i], (*out) + (i * 2), 2);
		i = i + 1;
	}
	(*out)[DIGESTBYTES * 2] = '\0';
}

extern t_bool			ft_whirlpool_main(t_pchar string, t_pchar *out)
{
	t_whirlpool		w;
	uint8_t			digest[DIGESTBYTES];

	ft_whirlpool_init(&w);
	ft_whirlpool_add((t_puchar)string, 8 * ft_strlen(string), &w);
	ft_whirlpool_finalize(&w, digest);
	if ((*out = malloc(DIGESTBYTES * 2 + 1)) == NULL)
		return (FALSE);
	ft_whirlpool_print(digest, DIGESTBYTES, out);
	return (TRUE);
}