
#include "libft.h"
#include "get_next_line.h"
#include "types.h"
#include "error.h"
#include "internal.h"

extern t_bool		ft_ssl(int ac, char **av)
{
//	t_settings		settings;
	t_command		*command;
	t_lst			*flags;

	if (ac < 2)
	{
		ft_ssl_usage();
		return (FALSE);
	}

	if (!ft_ssl_init(&command, av[1]))
	{
		ft_ssl_error_command(av[1]);
		return (FALSE);
	}

	flags = NULL;
	if (!ft_ssl_flags(ac - 2, av + 2, command, &flags))
		return (FALSE);
//	if (!ft_ssl_settings(ac - 2, av + 2, &settings))
//		return (FALSE);
	if (!ft_ssl_launch(av[1], flags))
		return (FALSE);
	return (TRUE);
}
