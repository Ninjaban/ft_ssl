//
// Created by Jonathan CARRA on 2019-04-15.
//

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal.h"

extern t_bool		ft_ssl(int ac, char **av)
{
	if (ac <= 2)
	{
		FT_ERROR("ac == %d", ac);
		ft_ssl_usage();
		return (FALSE);
	}
	if (ft_strcmp(av[1], "md5") && ft_strcmp(av[1], "sha256"))
	{
		FT_ERROR("Command Opts: %s", av[1]);
		ft_ssl_error_command(av[1]);
		return (FALSE);
	}
	return (TRUE);
}