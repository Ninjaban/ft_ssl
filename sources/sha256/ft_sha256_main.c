#include "libft.h"
#include "types.h"
#include "error.h"
#include "internal/sha256.h"

extern t_bool		ft_sha256_main(t_pchar string, t_pchar *out) {
	
	t_sha256		sha256;
	t_sha256_var	sha256_var;
	uint8_t			*(p[8]);

	if (!out)
		return (FALSE);
	if (!ft_sha256_init(&sha256))
		return (FALSE);
	if (!ft_sha256_padding(&sha256_var, (string) ? string : ""))
		return (FALSE);
	if (!ft_sha256_loop_main(&sha256, &sha256_var))
		return (FALSE);
	p[0] = (uint8_t *)&sha256.h0;
	p[1] = (uint8_t *)&sha256.h1;
	p[2] = (uint8_t *)&sha256.h2;
	p[3] = (uint8_t *)&sha256.h3;
	p[4] = (uint8_t *)&sha256.h4;
	p[5] = (uint8_t *)&sha256.h5;
	p[6] = (uint8_t *)&sha256.h6;
	p[7] = (uint8_t *)&sha256.h7;
	if ((*out = malloc(64 + 1)) == NULL)
		return (FALSE);
	snprintf(*out, 64 + 1, "%08x%08x%08x%08x%08x%08x%08x%08x", sha256.h0, sha256.h1, sha256.h2, sha256.h3, sha256.h4, sha256.h5, sha256.h6, sha256.h7);
	return (TRUE);
}