/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:31:19 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 11:29:01 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item,
							int (*cmpf)(void *, void *))
{
	t_btree	*tree;
	int		exit;

	exit = 0;
	tree = *root;
	if (tree && cmpf)
		while (exit == 0)
		{
			if (cmpf(tree->item, item) < 0)
			{
				if (tree->left != NULL)
					tree = tree->left;
				else
					tree->left = btree_create_node(item);
			}
			else
			{
				if (tree->right != NULL)
					tree = tree->right;
				else
					tree->right = btree_create_node(item);
			}
		}
}
