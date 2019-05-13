/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:04 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/08 13:55:54 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "types.h"
#include "error.h"
#include "internal.h"

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
	return (TRUE);
}
