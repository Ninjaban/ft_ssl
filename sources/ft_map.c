/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:15 by nsikora           #+#    #+#             */
/*   Updated: 2019/05/25 12:15:48 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

#include "error.h"
#include "types.h"

extern t_bool		ft_map_file(const char *path, t_buffer *file)
{
	t_pchar		line;
	t_pchar		p;
	t_pchar		tmp;
	int			fd;
	int			nbr;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (FALSE);
	if ((p = ft_strdup("")) == NULL)
		return (FALSE);
	if ((line = malloc(4096 + 1)) == NULL)
		return (FALSE);
	while ((nbr = read(fd, line, 4096)) > 0)
	{
		line[nbr] = '\0';
		if ((tmp = ft_strjoin(p, line)) == NULL)
			return (FALSE);
		free(p);
		p = tmp;
	}
	free(line);
	close(fd);
	(*file).bytes = p;
	(*file).size = ft_strlen(p);
//	ft_putstr(p);
	return (TRUE);
}

extern t_bool		ft_unmap_file(t_buffer *file)
{
	if (file == NULL)
		return (FALSE);
	if ((*file).bytes == NULL)
		return (FALSE);
	free((*file).bytes);
	(*file).bytes = NULL;
	(*file).size = 0;
	return (TRUE);
}
