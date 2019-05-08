/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:12 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/08 13:29:12 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal.h"

int			main(int ac, char **av)
{
	if (!ft_ssl(ac, av))
		return (1);
	return (0);
}
