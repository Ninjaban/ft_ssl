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

# include "internal/md5.h"
# include "internal/sha256.h"
# include "internal/whirlpool.h"

typedef struct		s_file
{
	t_pchar			name;
	t_buffer		content;
}					t_file;

typedef struct		s_args
{
	t_pchar			p;
	t_pchar			s;

	t_pchar			*f;
}					t_args;

typedef struct		s_settings
{
	t_bool			p;
	t_bool			q;
	t_bool			r;
	t_bool			s;

	t_args			args;
}					t_settings;

typedef struct		s_flag
{
	t_pchar			name;
	void			(*function);
	t_pvoid			param;
}					t_flag;

typedef struct		s_command
{
	t_pchar			name;
	void			(*function);
	t_uint			param;
}					t_command;

extern t_bool		ft_ssl(int ac, char **av);

extern void			ft_ssl_usage(void);
extern void			ft_ssl_usage_command(void);
extern void			ft_ssl_error_command(t_pchar cmd);

extern t_bool		ft_ssl_init(t_command **command, t_pchar type);
extern t_bool		ft_ssl_flags(int ac, char **av, t_command *command, t_lst **flags);

extern t_bool		ft_ssl_settings(int ac, char **av, t_settings *settings);

extern t_bool		ft_ssl_launch(t_pchar type, t_lst *flags);

extern void			ft_ssl_print(t_pchar hash, t_pchar text, t_pchar name, t_lst *flags);

extern t_bool		ft_ssl_tools_check_flag_name(t_lst *flags, t_pchar name);
extern t_pvoid		ft_ssl_tools_get_flag_param(t_lst *flags, t_pchar name);

extern t_bool		ft_map_file(const char *path, t_buffer *file);
extern t_bool		ft_unmap_file(t_buffer *file);

#endif
