/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:04:27 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/15 12:51:07 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# define RIGHTROTATE(x, c)	(((x) >> (c)) | ((x) << (32 - (c))))

extern t_bool	ft_sha256_main(t_pchar string, t_pchar *out);

typedef struct	s_sha256_var
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
	uint32_t	maj;
	uint32_t	ch;
	uint32_t	e0;
	uint32_t	e1;
	uint32_t	o0;
	uint32_t	o1;
	uint32_t	m[64];
	uint32_t	*msg_32;
	uint32_t	*w;
	size_t		new_len;
	size_t		offset;
}				t_sha256_var;

typedef struct	s_sha256
{
	uint32_t	k[64];
	uint32_t	t1;
	uint32_t	t2;
	uint32_t	h0;
	uint32_t	h1;
	uint32_t	h2;
	uint32_t	h3;
	uint32_t	h4;
	uint32_t	h5;
	uint32_t	h6;
	uint32_t	h7;
}				t_sha256;

extern t_bool	ft_sha256_main(t_pchar string, t_pchar *out);
extern t_bool	ft_sha256_init(t_sha256 *sha256);
extern t_bool	ft_sha256_padding(t_sha256_var *var, t_pchar string);
extern t_bool	ft_sha256_loop_main(t_sha256 *sha256, t_sha256_var *var);

#endif
