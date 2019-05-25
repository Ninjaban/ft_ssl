/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:30:21 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/25 12:15:48 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdint.h>

# define TRUE		1
# define FALSE		0

typedef char						t_bool;
typedef void *						t_pvoid;
typedef char *						t_pchar;
typedef const char *				t_cpchar;
typedef unsigned char *				t_puchar;
typedef const unsigned char *		t_cpuchar;
typedef unsigned int				t_uint;
typedef long long					t_long;

typedef struct		s_buffer
{
	t_uint			size;
	t_pvoid			bytes;
}					t_buffer;

#endif
