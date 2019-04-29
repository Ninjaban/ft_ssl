#include "libft.h"
#include "types.h"
#include "internal.h"

static t_bool		ft_ssl_flags_push_back(t_pchar name, t_pvoid function, t_pvoid param, t_lst **flags)
{
	t_flag		*flag;

	if (!flags)
		return (FALSE);

	if ((flag = malloc(sizeof(t_flag))) == NULL)
		return (FALSE);
	flag->name = name;
	flag->function = function;
	flag->param = param;
	ft_list_push_back(flags, flag);

	return (TRUE);
}

static t_bool		ft_ssl_flags_file(int ac, char **av, t_lst **flags)
{
	t_pchar		*args;
	int			i;

	if (ac <= 0)
		return (TRUE);

	i = 0;
	if ((args = malloc(sizeof(t_buffer) * (ac + 1))) == NULL)
		return (FALSE);
	while (i < ac)
	{
		args[i] = av[i];
		i = i + 1;
	}
	args[i] = NULL;
	ft_ssl_flags_push_back("ARGS", NULL, args, flags);

	return (TRUE);
}

extern t_bool		ft_ssl_flags(int ac, char **av, t_command *command, t_lst **flags)
{
	int		n;
	int		i;

	if (!flags)
		return (FALSE);

	n = 0;
	while (n < ac && *(av[n]) == '-')
	{
		i = 0;
		while (command[i].name != NULL && !ft_strcmp(av[n], command[i].name))
			i = i + 1;
		if (command[i].name == NULL)
			return (FALSE);
		ft_ssl_flags_push_back(command[i].name, command[i].function, ((command[i].param) ? av[n] + command[i].param : NULL), flags);

		n = n + (command[i].param + 1);
	}

	if (!ft_ssl_flags_file(ac + n, av + n, flags))
		return (FALSE);

	return (TRUE);
}
