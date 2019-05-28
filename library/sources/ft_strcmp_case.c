/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:36:15 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/25 12:15:49 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_reverse_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	if (c >= 'A' && c <= 'Z')
		return (c - 'Z' + 'a');
	return (c);
}

int			ft_strcmp_case(const char *s1, const char *s2)
{
	int	n;

	n = 0;
	if (!s1 || !s2)
		return (-1);
	while ((s1[n] == s2[n] || s1[n] == ft_reverse_char(s2[n])) && s1[n] &&
			s2[n])
		n = n + 1;
	return ((unsigned char)s1[n] - (unsigned char)s2[n]);
}
