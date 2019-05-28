/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:37:35 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/25 12:15:49 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char s, const char *c)
{
	int		n;

	n = 0;
	while (c[n] && c[n] != s)
		n = n + 1;
	return ((c[n]) ? 1 : 0);
}

int			ft_strlchr(const char *s, const char *c)
{
	int		n;

	n = 0;
	if (!s || !c)
		return (-1);
	while (s[n] && ft_check(s[n], c) == 0)
		n = n + 1;
	if (ft_check(s[n], c) == 1)
		return (n);
	return (-1);
}
