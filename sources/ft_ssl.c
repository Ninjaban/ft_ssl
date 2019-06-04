/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:04 by nsikora           #+#    #+#             */
/*   Updated: 2019/06/04 09:56:56 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "types.h"
#include "error.h"
#include "internal.h"

static void			ft_ssl_free_tab(t_pchar *tab)
{
	int		n;

	n = 0;
	while (tab[n])
		free(tab[n++]);
	free(tab);

}

static void			ft_ssl_free(t_command *command)
{
	int		n;

	n = 0;
	while (command[n].name != NULL)
	{
		if (command[n].defaut.list)
			ft_ssl_free_tab(command[n].defaut.list);
		if (command[n].exclusif)
			ft_ssl_free_tab(command[n].exclusif);
		if (command[n].param)
			free(command[n].param);
		n = n + 1;
	}
	free(command);
}

extern t_bool		ft_ssl(int ac, char **av)
{
	t_command		*command;

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
	if (!ft_ssl_flags(ac - 2, av + 2, &command))
		return (FALSE);
	if (!ft_ssl_launch(av[1], command))
		return (FALSE);
	ft_ssl_free(command);
	return (TRUE);
}
