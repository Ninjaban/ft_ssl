/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:33:07 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 13:15:54 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_list_at(t_lst *begin_list, unsigned int nbr)
{
	t_lst			*elem;
	unsigned int	n;

	n = 0;
	if ((elem = begin_list) == NULL)
		return (NULL);
	while (n < nbr && elem->next != NULL)
	{
		elem = elem->next;
		n = n + 1;
	}
	if (n < nbr)
		return (NULL);
	return (elem);
}
