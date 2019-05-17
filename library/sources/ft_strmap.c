/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:37:47 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/17 09:04:10 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		n;

	n = -1;
	if (s == NULL)
		return (NULL);
	if ((str = malloc(ft_strlen((char *)s) + 1)) == NULL)
		return (NULL);
	while (s[++n])
		str[n] = f(s[n]);
	str[n] = '\0';
	return (str);
}
