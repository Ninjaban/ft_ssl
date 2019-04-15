//
// Created by Jonathan CARRA on 2019-04-15.
//

#include "types.h"
#include "error.h"
#include "internal.h"

int			main(int ac, char **av)
{
	if (!ft_ssl(ac, av))
	{
		FT_WARNING("ft_ssl() failed ac %d av %p", ac, av);
		return (1);
	}
	return (0);
}