/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:35:46 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/08 13:35:46 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int		ft_revnbr(unsigned long int nbr)
{
	unsigned long int	rev;

	rev = 1;
	while (nbr > 0)
	{
		rev = rev * 10 + (nbr % 10);
		nbr = nbr / 10;
	}
	return (rev);
}
