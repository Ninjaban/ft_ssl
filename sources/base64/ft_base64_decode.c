/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_decode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:46:43 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 13:15:54 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"

extern t_bool		ft_base64_decode(t_pchar string, t_pchar *out)
{
	*out = ft_strdup("abcd");

	ft_putendl("decode...");
	ft_putendl(string);
	return (TRUE);
}
