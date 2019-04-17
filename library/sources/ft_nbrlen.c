//
// Created by Jonathan CARRA on 2019-04-15.
//

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