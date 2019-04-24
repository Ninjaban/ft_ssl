//
// Created by Jonathan CARRA on 2019-04-15.
//

#include "libft.h"
#include "get_next_line.h"
#include "types.h"
#include "error.h"
#include "internal.h"


extern t_bool		ft_ssl(int ac, char **av)
{
	t_settings		settings;

	if (ac < 2)
	{
		FT_ERROR("ac == %d", ac);
		ft_ssl_usage();
		return (FALSE);
	}
	if (ft_strcmp(av[1], "md5") && ft_strcmp(av[1], "sha256") && ft_strcmp(av[1], "whirlpool"))
	{
		FT_ERROR("Command Opts: %s", av[1]);
		ft_ssl_error_command(av[1]);
		return (FALSE);
	}

	if (!ft_ssl_settings(ac - 2, av + 2, &settings))
	{
		FT_WARNING("ft_ssl_args() failed%s", "");
		return (FALSE);
	}

	if (!ft_ssl_launch(av[1], settings))
	{
		FT_WARNING("ft_ssl_launch() failed %s", "");
		return (FALSE);
	}

	return (TRUE);
}
