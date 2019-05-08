/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:37:51 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/08 13:37:51 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	n;

	n = -1;
	if (s == NULL)
		return (NULL);
	if ((str = malloc(ft_strlen((char *)s) + 1)) == NULL)
		return (NULL);
	while (s[++n])
		str[n] = f(n, s[n]);
	str[n] = '\0';
	return (str);
}
