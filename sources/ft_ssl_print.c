
#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal.h"

static void			ft_ssl_print_reverse(t_pchar hash, t_pchar text,
											t_pchar name, t_settings settings)
{
	ft_putstr(hash);
	ft_putstr("  ");
	if (settings.q == FALSE)
	{
		if (name)
		{
			ft_putstr("MD5 (");
			ft_putstr(name);
			ft_putstr(")\n");
		}
		else if (settings.p == TRUE && !ft_strcmp(text, settings.args.p))
		{
			ft_putendl(text);
		}
		else if (!ft_strcmp(text, settings.args.s))
		{
			ft_putstr("MD5 ('");
			ft_putstr(text);
			ft_putstr("')\n");
		}
	}
}

static void			ft_ssl_print_normal(t_pchar hash, t_pchar text,
										t_pchar name, t_settings settings)
{
	if (settings.q == FALSE)
	{
		if (name)
		{
			ft_putstr("MD5 (");
			ft_putstr(name);
			ft_putstr(") = ");
		}
		else if (settings.p == TRUE && !ft_strcmp(text, settings.args.p))
		{
			ft_putendl(text);
		}
		else if (!ft_strcmp(text, settings.args.s))
		{
			ft_putstr("MD5 ('");
			ft_putstr(text);
			ft_putstr("') = ");
		}
	}
	ft_putendl(hash);
}

extern void			ft_ssl_print(t_pchar hash, t_pchar text, t_pchar name,
									t_settings settings)
{
	if (!settings.r)
		ft_ssl_print_normal(hash, text, name, settings);
	else
		ft_ssl_print_reverse(hash, text, name, settings);
}
