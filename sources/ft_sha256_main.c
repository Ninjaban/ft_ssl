
#include "types.h"
#include "error.h"
#include "internal.h"

extern t_bool		ft_sha256_main(t_pchar string, t_pchar *out) {
	
	t_sha256		sha256;

	if (!out)
	{
		FT_ERROR("out %p", out);
		return (FALSE);
	}

	if (!ft_sha256_init(&sha256))
	{
		FT_WARNING("ft_sha256_init() failed %s", "");
		return (FALSE);
	}
	(void)string;
    return (TRUE);
}