/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:28:51 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/08 13:28:51 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal.h"

static t_bool		ft_ssl_flags_file(int ac, char **av, t_command *command)
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
	(*command).param = args;
	(*command).active = TRUE;
	return (TRUE);
}

static void			ft_ssl_flags_end(int ac, char **av, t_command **command,
										int n)
{
	int		i;

	i = 0;
	while ((*command)[i].name != NULL)
	{
		if (!ft_strcmp((*command)[i].name, "ARGS"))
			ft_ssl_flags_file(ac - n, av + n, &((*command)[i]));
		if (!ft_strcmp((*command)[i].name, "LAUNCH"))
			(*command)[i].active = (*command)[i - 1].active;
		i = i + 1;
	}
}

extern t_bool		ft_ssl_flags(int ac, char **av, t_command **command)
{
	int		n;
	int		i;

	n = 0;
	while (n < ac && *(av[n]) == '-')
	{
		i = 0;
		while ((*command)[i].name != NULL &&
				ft_strcmp(av[n], (*command)[i].name))
			i = i + 1;
		if ((*command)[i].name == NULL)
			return (FALSE);
		(*command)[i].active = TRUE;
		if ((*command)[i].param_offset)
			(*command)[i].param = ft_strdup(av[n + (*command)[i].param_offset]);
		n = n + ((*command)[i].param_offset + 1);
		if ((*command)[i].end_flags)
			break ;
	}
	ft_ssl_flags_end(ac, av, command, n);
	return (TRUE);
}
