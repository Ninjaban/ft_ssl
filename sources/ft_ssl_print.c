
#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal.h"

static void			ft_ssl_print_reverse(t_pchar hash, t_pchar text,
											t_pchar name, t_lst *flags)
{
	ft_putstr(hash);
	ft_putstr("  ");
	if (!ft_ssl_tools_check_flag_name(flags, "-q"))
	{
		if (name)
		{
			ft_putstr("MD5 (");
			ft_putstr(name);
			ft_putstr(")\n");
		}
		else if (ft_ssl_tools_check_flag_name(flags, "-p") && !ft_strcmp(text, ft_ssl_tools_get_flag_param(flags, "-p")))
		{
			ft_putendl(text);
		}
		else if (!ft_strcmp(text, ft_ssl_tools_get_flag_param(flags, "-s")))
		{
			ft_putstr("MD5 ('");
			ft_putstr(text);
			ft_putstr("')\n");
		}
	}
}

static void			ft_ssl_print_normal(t_pchar hash, t_pchar text,
										t_pchar name, t_lst *flags)
{
	if (!ft_ssl_tools_check_flag_name(flags, "-q"))
	{
		if (name)
		{
			ft_putstr("MD5 (");
			ft_putstr(name);
			ft_putstr(") = ");
		}
		else if (ft_ssl_tools_check_flag_name(flags, "-p") && !ft_strcmp(text, ft_ssl_tools_get_flag_param(flags, "-p")))
		{
			ft_putendl(text);
		}
		else if (!ft_strcmp(text, ft_ssl_tools_get_flag_param(flags, "-s")))
		{
			ft_putstr("MD5 ('");
			ft_putstr(text);
			ft_putstr("') = ");
		}
	}
	ft_putendl(hash);
}

extern void			ft_ssl_print(t_pchar hash, t_pchar text, t_pchar name,
									t_lst *flags)
{
	if (!ft_ssl_tools_check_flag_name(flags, "-r"))
		ft_ssl_print_normal(hash, text, name, flags);
	else
		ft_ssl_print_reverse(hash, text, name, flags);
}
