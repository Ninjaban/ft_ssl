/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:33:00 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/25 12:15:48 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			ft_itohex(long int nbr, char *bytes, unsigned int size)
{
	long int		res;
	unsigned int	n;

	if (!size || !bytes)
		return (0);
	n = 0;
	while (n < size)
		bytes[n++] = (nbr >= 0) ? '0' : 'f';
	n = size - 1;
	while (nbr)
	{
		res = (nbr > 0) ? nbr % 16 : 15 + (nbr % 16);
		if (n == size - 1 && nbr < 0)
			res += 1;
		bytes[n] = (res < 10) ? res + '0' : res - 10 + 'a';
		nbr = nbr / 16;
		if (n == 0)
			break ;
		n = n - 1;
	}
	return (size);
}
