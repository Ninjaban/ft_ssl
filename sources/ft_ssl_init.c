#include <stdlib.h>

#include "libft.h"
#include "types.h"
#include "internal.h"

static void			ft_ssl_init_add_cmd(t_pchar name, void (*function), t_uint param, t_command *command)
{
	(*command).name = name;
	(*command).function = function;
	(*command).param = param;
}

static t_bool		ft_ssl_init_md5(t_command **command)
{
	int		n;

	if ((*command = malloc(sizeof(t_command) * 5)) == NULL)
		return (FALSE);

	n = 0;
	ft_ssl_init_add_cmd("-p", NULL, 0, &((*command)[n++]));
	ft_ssl_init_add_cmd("-q", NULL, 0, &((*command)[n++]));
	ft_ssl_init_add_cmd("-r", NULL, 0, &((*command)[n++]));
	ft_ssl_init_add_cmd("-s", NULL, 1, &((*command)[n++]));
	ft_ssl_init_add_cmd(NULL, NULL, 0, &((*command)[n++]));

	return (TRUE);
}

static t_bool		ft_ssl_init_base64(t_command **command)
{
	int		n;

	if ((*command = malloc(sizeof(t_command) * 5)) == NULL)
		return (FALSE);

	n = 0;
	ft_ssl_init_add_cmd("-d", NULL, 0, &((*command)[n++]));
	ft_ssl_init_add_cmd("-e", NULL, 0, &((*command)[n++]));
	ft_ssl_init_add_cmd("-i", NULL, 1, &((*command)[n++]));
	ft_ssl_init_add_cmd("-o", NULL, 1, &((*command)[n++]));
	ft_ssl_init_add_cmd(NULL, NULL, 0, &((*command)[n++]));

	return (TRUE);
}

static t_bool		ft_ssl_init_des(t_command **command)
{
	int		n;

	if ((*command = malloc(sizeof(t_command) * 10)) == NULL)
		return (FALSE);

	n = 0;
	ft_ssl_init_add_cmd("-a", NULL, 0, &((*command)[n++]));
	ft_ssl_init_add_cmd("-d", NULL, 0, &((*command)[n++]));
	ft_ssl_init_add_cmd("-e", NULL, 0, &((*command)[n++]));
	ft_ssl_init_add_cmd("-i", NULL, 1, &((*command)[n++]));
	ft_ssl_init_add_cmd("-k", NULL, 1, &((*command)[n++]));
	ft_ssl_init_add_cmd("-o", NULL, 1, &((*command)[n++]));
	ft_ssl_init_add_cmd("-p", NULL, 1, &((*command)[n++]));
	ft_ssl_init_add_cmd("-s", NULL, 1, &((*command)[n++]));
	ft_ssl_init_add_cmd("-v", NULL, 1, &((*command)[n++]));
	ft_ssl_init_add_cmd(NULL, NULL, 0, &((*command)[n++]));

	return (TRUE);
}

extern t_bool		ft_ssl_init(t_command **command, t_pchar type)
{
	if (!command)
		return (FALSE);

	if (!ft_strcmp(type, "md5") && ft_ssl_init_md5(command))
		return (TRUE);
	if (!ft_strcmp(type, "sha256") && ft_ssl_init_md5(command))
		return (TRUE);
	if (!ft_strcmp(type, "whirlpool") && ft_ssl_init_md5(command))
		return (TRUE);
	if (!ft_strcmp(type, "base64") && ft_ssl_init_base64(command))
		return (TRUE);
	if (!ft_strcmp(type, "des") && ft_ssl_init_des(command))
		return (TRUE);

	return (FALSE);
}