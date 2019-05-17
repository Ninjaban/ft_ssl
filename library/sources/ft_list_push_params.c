/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:34:05 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/17 09:04:10 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_list_push_params(int ac, char **av)
{
	int		n;
	t_lst	*new;

	n = 1;
	new = NULL;
	if (ac > 1)
		new = ft_create_elem(av[n++]);
	while (n < ac)
	{
		new->next = ft_create_elem(av[n++]);
		new = new->next;
	}
	if (new != NULL)
		new->next = ft_create_elem(av[0]);
	else
		new = ft_create_elem(av[0]);
	return (new);
}
