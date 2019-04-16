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

	uint8_t		*(p[4]);

	p[0] = (uint8_t *)&md5.h0;
	p[1] = (uint8_t *)&md5.h1;
	p[2] = (uint8_t *)&md5.h2;
	p[3] = (uint8_t *)&md5.h3;
	FT_DEBUG("%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x", p[0][0], p[0][1], p[0][2], p[0][3], p[1][0], p[1][1], p[1][2], p[1][3], p[2][0], p[2][1], p[2][2], p[2][3], p[3][0], p[3][1], p[3][2], p[3][3]);
//	FT_DEBUG("%08x%08x%08x%08x", md5.h0, md5.h1, md5.h2, md5.h3);
	return (TRUE);
}