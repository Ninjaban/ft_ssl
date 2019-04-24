
#include <stdlib.h>

#include "types.h"
#include "error.h"
#include "internal/md5.h"

extern t_bool		ft_md5_main(t_pchar string, t_pchar *out)
{
	t_md5		md5;
	uint8_t		*(p[4]);

	if (!out)
		return (FALSE);
	if (!ft_md5_init(&md5))
		return (FALSE);
	if (!ft_md5_padding(&md5, (string) ? string : ""))
		return (FALSE);
	p[0] = (uint8_t *)&md5.h0;
	p[1] = (uint8_t *)&md5.h1;
	p[2] = (uint8_t *)&md5.h2;
	p[3] = (uint8_t *)&md5.h3;
	if ((*out = malloc(32 + 1)) == NULL)
		return (FALSE);
	snprintf(*out, 32 + 1, "%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x", p[0][0], p[0][1], p[0][2], p[0][3], p[1][0], p[1][1], p[1][2], p[1][3], p[2][0], p[2][1], p[2][2], p[2][3], p[3][0], p[3][1], p[3][2], p[3][3]);
	return (TRUE);
}