/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:30:11 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 11:29:01 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "internal/md5.h"
# include "internal/sha256.h"
# include "internal/whirlpool.h"
# include "internal/base64.h"

typedef struct		s_file
{
	t_pchar			name;
	t_buffer		content;
}					t_file;

typedef struct		s_default
{
	t_bool			is_default;
	t_pchar			*list;
}					t_default;

typedef struct		s_command
{
	t_pchar			name;
	t_bool			active;
	void			(*function);
	t_pvoid			param;
	t_uint			param_offset;
	t_bool			end_flags;
	t_pchar			*exclusif;
	t_default		defaut;
}					t_command;

typedef struct		s_ninit
{
	t_uint			param_offset;
	t_bool			end_flags;
	t_pchar			*exclusif;
}					t_ninit;

extern t_bool		ft_ssl(int ac, char **av);

extern void			ft_ssl_usage(void);
extern void			ft_ssl_usage_command(void);
extern void			ft_ssl_error_command(t_pchar cmd);

extern t_ninit		ninit(t_uint param_offset, t_bool end_flags, t_pchar *exclusif);
extern void			ft_ssl_init_add_default(t_pchar *list, t_command *command);
extern void			ft_ssl_init_add_launch(void (*function),
											t_command *command);
extern void			ft_ssl_init_add_cmd(t_pchar name, void (*function),
											t_ninit ninit, t_command *command);

extern t_bool		ft_ssl_init(t_command **command, t_pchar type);
extern t_bool		ft_ssl_flags(int ac, char **av, t_command **command);

extern t_bool		ft_ssl_launch(t_pchar type, t_command *command);

extern void			ft_ssl_print(t_pchar hash, t_file file, t_pchar type,
									t_command *command);
extern t_bool		ft_ssl_print_file(t_pchar hash, t_file file, t_pchar type,
									t_command *command);

extern t_bool		ft_ssl_tools_get_cmd_active(t_command *command,
												t_pchar name);
extern t_pvoid		ft_ssl_tools_get_cmd_param(t_command *command,
												t_pchar name);
extern t_pvoid		ft_ssl_tools_get_cmd_function(t_command *command,
												t_pchar name);
extern t_bool		ft_ssl_tools_stdin(t_pvoid args);
extern t_bool		ft_ssl_tools_file(t_pvoid args);

extern t_bool		ft_map_file(const char *path, t_buffer *file);
extern t_bool		ft_unmap_file(t_buffer *file);

#endif
