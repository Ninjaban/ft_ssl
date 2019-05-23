/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_print_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:49:24 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 13:15:53 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "types.h"
#include "internal.h"

extern t_bool		ft_ssl_print_file(t_pchar hash, t_file file, t_pchar type,
									t_command *command)
{
	int		fd;

	(void)file;
	(void)type;
	ft_putendl("print in file...");
	ft_putendl(ft_ssl_tools_get_cmd_param(command, "PRINT"));
	if ((fd = open(ft_ssl_tools_get_cmd_param(command, "PRINT"), O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IROTH)) == -1)
		return (FALSE);
	ft_putstr_fd(hash, fd);
	close(fd);
	free(hash);
	return (TRUE);
}
