/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:39:19 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 11:29:01 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;

	n = 0;
	if (s == NULL)
		return (NULL);
	if ((str = malloc(len + 1)) == NULL)
		return (NULL);
	while (n < len)
	{
		str[n] = s[start + n];
		n = n + 1;
	}
	str[n] = '\0';
	return (str);
}
