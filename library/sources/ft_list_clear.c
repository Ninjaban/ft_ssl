/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:33:11 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 11:29:01 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_lst **begin_list, void (*f)(void *))
{
	t_lst	*elem;
	t_lst	*next;

	if (!begin_list || !(*begin_list))
		return ;
	elem = *begin_list;
	while (elem != NULL)
	{
		next = elem->next;
		ft_list_del(elem, f);
		elem = next;
	}
	*begin_list = NULL;
}
