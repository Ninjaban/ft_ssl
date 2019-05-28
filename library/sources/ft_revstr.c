/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:35:51 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/25 12:15:48 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_revstr(char *str)
{
	char	*rev;
	int		n;
	int		i;

	n = 0;
	i = ft_strlen(str) - 1;
	if ((rev = malloc(ft_strlen(str) + 1)) == NULL)
		return (NULL);
	while (i >= 0)
		rev[n++] = str[i--];
	rev[n] = '\0';
	free(str);
	return (rev);
}
