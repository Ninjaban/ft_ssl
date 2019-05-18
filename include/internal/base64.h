/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:40:31 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 13:15:54 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

extern t_bool		ft_ssl_base64_mode(t_pvoid args);

extern t_bool		ft_base64_encode(t_pchar string, t_pchar *out);
extern t_bool		ft_base64_decode(t_pchar string, t_pchar *out);

#endif
