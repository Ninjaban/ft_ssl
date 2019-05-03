/* ----------------------------------------------------------------------------+
                                                                               |
    .------..------..------..------..------..------..------..------..------.   |
    |P.--. ||R.--. ||E.--. ||V.--. ||I.--. ||S.--. ||I.--. ||O.--. ||N.--. |   |
    | :/\: || :(): || (\/) || :(): || (\/) || :/\: || (\/) || :/\: || :(): |   :
    | (__) || ()() || :\/: || ()() || :\/: || :\/: || :\/: || :\/: || ()() |
    | '--'P|| '--'R|| '--'E|| '--'V|| '--'I|| '--'S|| '--'I|| '--'O|| '--'N|
:   `------'`------'`------'`------'`------'`------'`------'`------'`------'
|
|    Created by Jonathan Carra.
|    Copyright (c) 2019 Prévision. All rights reserved.
+---------------------------------------------------------------------------- */

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
