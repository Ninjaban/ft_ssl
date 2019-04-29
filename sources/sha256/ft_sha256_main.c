
#include "types.h"
#include "error.h"
#include "internal.h"
#include "libft.h"

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
	ft_putstr("ca marche\n");
	if ((*out = malloc(64 + 1)) == NULL)
		return (FALSE);
	ft_putstr("un peu\n");
	(*out)[0] = 'f';
	(*out)[1] = '\0';
	printf("%08x\n", sha256.h0);
		printf("%08x\n", sha256.h1);	
			printf("%08x\n", sha256.h2);
				printf("%08x\n", sha256.h3);
					printf("%08x\n", sha256.h4);
						printf("%08x\n", sha256.h5);
							printf("%08x\n", sha256.h6);
								printf("%08x\n", sha256.h7);	
	snprintf(*out, 64 + 1, "%08x%08x%08x%08x%08x%08x%08x%08x", sha256.h0, sha256.h1, sha256.h2, sha256.h3, sha256.h4, sha256.h5, sha256.h6, sha256.h7);
//	snprintf(*out, 64 + 1, "%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x", p[0][0], p[0][1], p[0][2], p[0][3], p[1][0], p[1][1], p[1][2], p[1][3], p[2][0], p[2][1], p[2][2], p[2][3], p[3][0], p[3][1], p[3][2], p[3][3],
//	p[4][0], p[4][1], p[4][2], p[4][3], p[5][0], p[5][1], p[5][2], p[5][3], p[6][0], p[6][1], p[6][2], p[6][3], p[7][0], p[7][1], p[7][2], p[7][3]);
    ft_putstr("tres bien\n");
	return (TRUE);
}