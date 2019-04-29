
#include "libft.h"
#include "types.h"
#include "internal.h"

extern t_bool		ft_ssl_tools_check_flag_name(t_lst *flags, t_pchar name)
{
	t_lst		*tmp;

	tmp = flags;
	while (((t_flag *)(tmp->data))->name != NULL &&
			ft_strcmp(((t_flag *)(tmp->data))->name, name))
		tmp = tmp->next;

	if (!ft_strcmp(((t_flag *)(tmp->data))->name, name))
		return (TRUE);

	return (FALSE);
}

extern t_pvoid		ft_ssl_tools_get_flag_param(t_lst *flags, t_pchar name)
{
	t_lst		*tmp;

	tmp = flags;
	while (((t_flag *)(tmp->data))->name != NULL &&
		   ft_strcmp(((t_flag *)(tmp->data))->name, name))
		tmp = tmp->next;

	if (!ft_strcmp(((t_flag *)(tmp->data))->name, name))
		return (((t_flag *)(tmp->data))->param);

	return (NULL);
}
