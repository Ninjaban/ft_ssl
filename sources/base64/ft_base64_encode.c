/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_encode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:45:35 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/17 15:19:09 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"

extern t_bool		ft_base64_encode(t_pchar string, t_pchar *out)
{
	*out = ft_strdup("abcd");

	ft_putendl("encode...");
	ft_putendl(string);
	return (TRUE);
}