/* ----------------------------------------------------------------------------+
                                                                               |
    .------..------..------..------..------..------..------..------..------.   |
    |P.--. ||R.--. ||E.--. ||V.--. ||I.--. ||S.--. ||I.--. ||O.--. ||N.--. |   |
    | :/\: || :(): || (\/) || :(): || (\/) || :/\: || (\/) || :/\: || :(): |   :
    | (__) || ()() || :\/: || ()() || :\/: || :\/: || :\/: || :\/: || ()() |
    | '--'P|| '--'R|| '--'E|| '--'V|| '--'I|| '--'S|| '--'I|| '--'O|| '--'N|
:   `------'`------'`------'`------'`------'`------'`------'`------'`------'
|
|    Created by Jonathan Carra.
|    Copyright (c) 2019 Prévision. All rights reserved.
+---------------------------------------------------------------------------- */

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
