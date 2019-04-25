

#ifndef SHA256_H
# define SHA256_H

extern t_bool        ft_sha256_main(t_pchar string, t_pchar *out);

#define	revers_uint32(x) ((x >> 24) | ((x & 0xff0000) >> 8) | ((x & 0xff00) << 8) | (x << 24));

typedef struct		s_sha256_var
{
	int32_t			a;
	int32_t			b;
	int32_t			c;
	int32_t			d;
    int32_t         e;
    int32_t         f;
    int32_t         g;
    int32_t         h;
}					t_sha256_var;

typedef struct		s_sha256
{
    int32_t         k[64];
	int32_t			t1[32];
	int32_t			t2[32];
	int32_t			h0;
	int32_t			h1;
	int32_t			h2;
	int32_t			h3;
    int32_t         h4;
    int32_t         h5;
    int32_t         h6;
    int32_t         h7;
}					t_sha256;

extern t_bool		ft_sha256_main(t_pchar string, t_pchar *out);
extern t_bool		ft_sha256_init(t_sha256 *sha256);
extern t_bool		ft_sha256_padding(t_sha256 *sha256, t_pchar string);

#endif