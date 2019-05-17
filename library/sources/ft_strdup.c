/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:36:26 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/16 14:14:53 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *src)
{
	char	*str;
	size_t	n;
	size_t	len;

	n = 0;
	if (!src)
		return (NULL);
	len = ft_strlen(src);
	if ((str = malloc(len + 1)) == NULL)
		return (NULL);
	while (n < len)
	{
		str[n] = src[n];
		n = n + 1;
	}
	str[n] = '\0';
	return (str);
}
