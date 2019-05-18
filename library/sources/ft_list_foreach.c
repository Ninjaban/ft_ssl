/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:33:20 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 11:29:01 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_foreach(t_lst *begin_list, void (*f)(void *))
{
	t_lst	*elem;

	elem = begin_list;
	while (elem != NULL)
	{
		(*f)(elem->data);
		elem = elem->next;
	}
}
