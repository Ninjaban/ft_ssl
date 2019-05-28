/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:34:32 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/25 12:15:49 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_list_size(t_lst *begin_list)
{
	t_lst	*elem;
	int		n;

	n = 1;
	if (begin_list == NULL)
		return (0);
	elem = begin_list;
	while (elem->next != NULL)
	{
		n = n + 1;
		elem = elem->next;
	}
	return (n);
}
