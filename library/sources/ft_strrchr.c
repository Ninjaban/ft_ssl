/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:38:55 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/08 13:38:55 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		n;

	if (!s)
		return (NULL);
	n = ft_strlen((char *)s);
	while (n >= 0 && s[n] != c)
		n = n - 1;
	if (n >= 0)
		return ((char *)(s + n));
	return (NULL);
}
