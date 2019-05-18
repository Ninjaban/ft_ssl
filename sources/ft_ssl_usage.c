/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <jcarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:29:10 by jcarra            #+#    #+#             */
/*   Updated: 2019/05/18 11:29:01 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"

extern void			ft_ssl_usage_command(void)
{
	ft_putendl_fd("Standard commands:", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Message Digest commands:", 2);
	ft_putendl_fd("md5", 2);
	ft_putendl_fd("sha256", 2);
	ft_putendl_fd("whirlpool", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Cipher commands:", 2);
}

extern void			ft_ssl_usage(void)
{
	ft_putendl_fd("usage: ft_ssl command [command opts] [command args]", 2);
}

extern void			ft_ssl_error_command(t_pchar cmd)
{
	ft_putstr_fd("ft_ssl: Error:'", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd("'is an invalid command.", 2);
	ft_putendl_fd("", 2);
	ft_ssl_usage_command();
}
