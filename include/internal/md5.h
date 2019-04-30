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

#ifndef MD5_H
# define MD5_H

# define leftRotate(x, c)		(((x) << (c)) | ((x) >> (32 - (c))))

typedef struct		s_md5_var
{
	int32_t			a;
	int32_t			b;
	int32_t			c;
	int32_t			d;
}					t_md5_var;

typedef struct		s_md5
{
	int32_t			r[64];
	int32_t			k[64];

	int32_t			h0;
	int32_t			h1;
	int32_t			h2;
	int32_t			h3;
}					t_md5;

extern t_bool		ft_md5_main(t_pchar string, t_pchar *out);
extern t_bool		ft_md5_init(t_md5 *md5);
extern t_bool		ft_md5_padding(t_md5 *md5, t_pchar string);
extern t_bool		ft_md5_loop(t_md5 *md5, t_puchar block, size_t size);

#endif
