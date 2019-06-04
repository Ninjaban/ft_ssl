/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:40:31 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/25 12:15:48 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

typedef struct		s_base64_var
{
    uint32_t		len;
    uint32_t        padCount;
    size_t          resultIndex;
}					t_base64_var;

typedef struct		s_base64
{
    uint8_t         n0;
    uint8_t         n1;
    uint8_t         n2;
    uint8_t         n3;
    size_t          resultLen;
    t_pchar         result;
}					t_base64;

extern t_bool		ft_ssl_base64_mode(t_pvoid args);
extern t_bool		ft_base64_encode(t_pchar string, t_pchar *out);
extern t_bool		ft_base64_decode(t_pchar string, t_pchar *out);

#endif
