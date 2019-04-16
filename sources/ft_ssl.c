//
// Created by Jonathan CARRA on 2019-04-15.
//

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal.h"

extern t_bool		ft_ssl(int ac, char **av)
{
	t_pchar hash = NULL;

	if (ac < 2)
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

	if (!ft_strcmp(av[1], "md5") && !ft_md5_main(av[2], &hash))
	{
		FT_WARNING("ft_md5_main() failed {%.*s}", (int)ft_strlen(av[2]), av[2]);
		return (FALSE);
	}

	FT_DEBUG("%.*s", 32 + 1, hash);
	return (TRUE);
}