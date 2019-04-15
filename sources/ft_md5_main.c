//
// Created by Jonathan CARRA on 2019-04-15.
//

#include "types.h"
#include "error.h"
#include "internal.h"

extern t_bool		ft_md5_main(t_pchar string)
{
	t_md5		md5;

	if (!ft_md5_init(&md5))
	{
		FT_WARNING("ft_md5_init() failed %s", "");
		return (FALSE);
	}

	if (!ft_md5_padding(&md5, (string) ? string : ""))
	{
		FT_WARNING("ft_md5_padding() failed %s", "");
		return (FALSE);
	}

	FT_DEBUG("%08x%08x%08x%08x", md5.h0, md5.h1, md5.h2, md5.h3);
	return (TRUE);
}