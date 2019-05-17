/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:31:43 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/16 14:14:54 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_lst		*ft_create_elem(void *data)
{
	t_lst	*new_elem;

	if ((new_elem = malloc(sizeof(t_lst))) == NULL)
		return (NULL);
	new_elem->next = NULL;
	new_elem->data = data;
	return (new_elem);
}
