#include "libft.h"

int			ft_nbrlen(size_t nbr)
{
	int		size;

	size = 0;
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}
