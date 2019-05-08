/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:30:11 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/08 13:30:11 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct		s_command
{
	t_pchar			name;
	t_bool			active;
	void			(*function);
	t_pvoid			param;
	t_uint			param_offset;
	t_bool			end_flags;
}					t_command;

typedef struct		s_ninit
{
	t_uint			param_offset;
	t_bool			end_flags;
}					t_ninit;

extern t_bool		ft_ssl(int ac, char **av);

extern void			ft_ssl_usage(void);
extern void			ft_ssl_usage_command(void);
extern void			ft_ssl_error_command(t_pchar cmd);

extern t_bool		ft_ssl_init(t_command **command, t_pchar type);
extern t_bool		ft_ssl_flags(int ac, char **av, t_command **command);

extern t_bool		ft_ssl_launch(t_pchar type, t_command *command);

extern void			ft_ssl_print(t_pchar hash, t_file file, t_pchar type,
									t_command *command);

extern t_bool		ft_ssl_tools_get_cmd_active(t_command *command,
												t_pchar name);
extern t_pvoid		ft_ssl_tools_get_cmd_param(t_command *command,
												t_pchar name);
extern t_pvoid		ft_ssl_tools_get_cmd_function(t_command *command,
												t_pchar name);
extern t_bool		ft_ssl_tools_stdin(t_pvoid args);

extern t_bool		ft_map_file(const char *path, t_buffer *file);
extern t_bool		ft_unmap_file(t_buffer *file);

#endif
