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

#ifndef INTERNAL_H
# define INTERNAL_H

typedef struct		s_md5
{
	int32_t			r[64];
	double			k[64];

	int32_t			h0;
	int32_t			h1;
	int32_t			h2;
	int32_t			h3;
}					t_md5;

extern t_bool		ft_ssl(int ac, char **av);

extern void			ft_ssl_usage(void);
extern void			ft_ssl_usage_command(void);
extern void			ft_ssl_error_command(t_pchar cmd);

extern t_bool		ft_md5_init(t_md5 *md5);
extern t_bool		ft_md5_padding(t_pchar string);

#endif
