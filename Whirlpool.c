
#include "libft.h"
#include "types.h"
#include "whirlpool.h"

static void processBuffer(t_whirlpool *out_whirlpool) {
    int i, r;
    uint64_t K[8];
    uint64_t block[8];
    uint64_t state[8];
    uint64_t L[8];
    uint8_t *buffer = out_whirlpool->buffer;


    for (i = 0; i < 8; i++, buffer += 8) {
        block[i] =
            (((uint64_t)buffer[0]        ) << 56) ^
            (((uint64_t)buffer[1] & 0xffL) << 48) ^
            (((uint64_t)buffer[2] & 0xffL) << 40) ^
            (((uint64_t)buffer[3] & 0xffL) << 32) ^
            (((uint64_t)buffer[4] & 0xffL) << 24) ^
            (((uint64_t)buffer[5] & 0xffL) << 16) ^
            (((uint64_t)buffer[6] & 0xffL) <<  8) ^
            (((uint64_t)buffer[7] & 0xffL)      );
    }

    state[0] = block[0] ^ (K[0] = out_whirlpool->hash[0]);
    state[1] = block[1] ^ (K[1] = out_whirlpool->hash[1]);
    state[2] = block[2] ^ (K[2] = out_whirlpool->hash[2]);
    state[3] = block[3] ^ (K[3] = out_whirlpool->hash[3]);
    state[4] = block[4] ^ (K[4] = out_whirlpool->hash[4]);
    state[5] = block[5] ^ (K[5] = out_whirlpool->hash[5]);
    state[6] = block[6] ^ (K[6] = out_whirlpool->hash[6]);
    state[7] = block[7] ^ (K[7] = out_whirlpool->hash[7]);

    for (r = 1; r <= R; r++) {

        L[0] =
            C0[(int)(K[0] >> 56)       ] ^
            C1[(int)(K[7] >> 48) & 0xff] ^
            C2[(int)(K[6] >> 40) & 0xff] ^
            C3[(int)(K[5] >> 32) & 0xff] ^
            C4[(int)(K[4] >> 24) & 0xff] ^
            C5[(int)(K[3] >> 16) & 0xff] ^
            C6[(int)(K[2] >>  8) & 0xff] ^
            C7[(int)(K[1]      ) & 0xff] ^
            rc[r];
        L[1] =
            C0[(int)(K[1] >> 56)       ] ^
            C1[(int)(K[0] >> 48) & 0xff] ^
            C2[(int)(K[7] >> 40) & 0xff] ^
            C3[(int)(K[6] >> 32) & 0xff] ^
            C4[(int)(K[5] >> 24) & 0xff] ^
            C5[(int)(K[4] >> 16) & 0xff] ^
            C6[(int)(K[3] >>  8) & 0xff] ^
            C7[(int)(K[2]      ) & 0xff];
        L[2] =
            C0[(int)(K[2] >> 56)       ] ^
            C1[(int)(K[1] >> 48) & 0xff] ^
            C2[(int)(K[0] >> 40) & 0xff] ^
            C3[(int)(K[7] >> 32) & 0xff] ^
            C4[(int)(K[6] >> 24) & 0xff] ^
            C5[(int)(K[5] >> 16) & 0xff] ^
            C6[(int)(K[4] >>  8) & 0xff] ^
            C7[(int)(K[3]      ) & 0xff];
        L[3] =
            C0[(int)(K[3] >> 56)       ] ^
            C1[(int)(K[2] >> 48) & 0xff] ^
            C2[(int)(K[1] >> 40) & 0xff] ^
            C3[(int)(K[0] >> 32) & 0xff] ^
            C4[(int)(K[7] >> 24) & 0xff] ^
            C5[(int)(K[6] >> 16) & 0xff] ^
            C6[(int)(K[5] >>  8) & 0xff] ^
            C7[(int)(K[4]      ) & 0xff];
        L[4] =
            C0[(int)(K[4] >> 56)       ] ^
            C1[(int)(K[3] >> 48) & 0xff] ^
            C2[(int)(K[2] >> 40) & 0xff] ^
            C3[(int)(K[1] >> 32) & 0xff] ^
            C4[(int)(K[0] >> 24) & 0xff] ^
            C5[(int)(K[7] >> 16) & 0xff] ^
            C6[(int)(K[6] >>  8) & 0xff] ^
            C7[(int)(K[5]      ) & 0xff];
        L[5] =
            C0[(int)(K[5] >> 56)       ] ^
            C1[(int)(K[4] >> 48) & 0xff] ^
            C2[(int)(K[3] >> 40) & 0xff] ^
            C3[(int)(K[2] >> 32) & 0xff] ^
            C4[(int)(K[1] >> 24) & 0xff] ^
            C5[(int)(K[0] >> 16) & 0xff] ^
            C6[(int)(K[7] >>  8) & 0xff] ^
            C7[(int)(K[6]      ) & 0xff];
        L[6] =
            C0[(int)(K[6] >> 56)       ] ^
            C1[(int)(K[5] >> 48) & 0xff] ^
            C2[(int)(K[4] >> 40) & 0xff] ^
            C3[(int)(K[3] >> 32) & 0xff] ^
            C4[(int)(K[2] >> 24) & 0xff] ^
            C5[(int)(K[1] >> 16) & 0xff] ^
            C6[(int)(K[0] >>  8) & 0xff] ^
            C7[(int)(K[7]      ) & 0xff];
        L[7] =
            C0[(int)(K[7] >> 56)       ] ^
            C1[(int)(K[6] >> 48) & 0xff] ^
            C2[(int)(K[5] >> 40) & 0xff] ^
            C3[(int)(K[4] >> 32) & 0xff] ^
            C4[(int)(K[3] >> 24) & 0xff] ^
            C5[(int)(K[2] >> 16) & 0xff] ^
            C6[(int)(K[1] >>  8) & 0xff] ^
            C7[(int)(K[0]      ) & 0xff];
        K[0] = L[0];
        K[1] = L[1];
        K[2] = L[2];
        K[3] = L[3];
        K[4] = L[4];
        K[5] = L[5];
        K[6] = L[6];
        K[7] = L[7];

        L[0] =
            C0[(int)(state[0] >> 56)       ] ^
            C1[(int)(state[7] >> 48) & 0xff] ^
            C2[(int)(state[6] >> 40) & 0xff] ^
            C3[(int)(state[5] >> 32) & 0xff] ^
            C4[(int)(state[4] >> 24) & 0xff] ^
            C5[(int)(state[3] >> 16) & 0xff] ^
            C6[(int)(state[2] >>  8) & 0xff] ^
            C7[(int)(state[1]      ) & 0xff] ^
            K[0];
        L[1] =
            C0[(int)(state[1] >> 56)       ] ^
            C1[(int)(state[0] >> 48) & 0xff] ^
            C2[(int)(state[7] >> 40) & 0xff] ^
            C3[(int)(state[6] >> 32) & 0xff] ^
            C4[(int)(state[5] >> 24) & 0xff] ^
            C5[(int)(state[4] >> 16) & 0xff] ^
            C6[(int)(state[3] >>  8) & 0xff] ^
            C7[(int)(state[2]      ) & 0xff] ^
            K[1];
        L[2] =
            C0[(int)(state[2] >> 56)       ] ^
            C1[(int)(state[1] >> 48) & 0xff] ^
            C2[(int)(state[0] >> 40) & 0xff] ^
            C3[(int)(state[7] >> 32) & 0xff] ^
            C4[(int)(state[6] >> 24) & 0xff] ^
            C5[(int)(state[5] >> 16) & 0xff] ^
            C6[(int)(state[4] >>  8) & 0xff] ^
            C7[(int)(state[3]      ) & 0xff] ^
            K[2];
        L[3] =
            C0[(int)(state[3] >> 56)       ] ^
            C1[(int)(state[2] >> 48) & 0xff] ^
            C2[(int)(state[1] >> 40) & 0xff] ^
            C3[(int)(state[0] >> 32) & 0xff] ^
            C4[(int)(state[7] >> 24) & 0xff] ^
            C5[(int)(state[6] >> 16) & 0xff] ^
            C6[(int)(state[5] >>  8) & 0xff] ^
            C7[(int)(state[4]      ) & 0xff] ^
            K[3];
        L[4] =
            C0[(int)(state[4] >> 56)       ] ^
            C1[(int)(state[3] >> 48) & 0xff] ^
            C2[(int)(state[2] >> 40) & 0xff] ^
            C3[(int)(state[1] >> 32) & 0xff] ^
            C4[(int)(state[0] >> 24) & 0xff] ^
            C5[(int)(state[7] >> 16) & 0xff] ^
            C6[(int)(state[6] >>  8) & 0xff] ^
            C7[(int)(state[5]      ) & 0xff] ^
            K[4];
        L[5] =
            C0[(int)(state[5] >> 56)       ] ^
            C1[(int)(state[4] >> 48) & 0xff] ^
            C2[(int)(state[3] >> 40) & 0xff] ^
            C3[(int)(state[2] >> 32) & 0xff] ^
            C4[(int)(state[1] >> 24) & 0xff] ^
            C5[(int)(state[0] >> 16) & 0xff] ^
            C6[(int)(state[7] >>  8) & 0xff] ^
            C7[(int)(state[6]      ) & 0xff] ^
            K[5];
        L[6] =
            C0[(int)(state[6] >> 56)       ] ^
            C1[(int)(state[5] >> 48) & 0xff] ^
            C2[(int)(state[4] >> 40) & 0xff] ^
            C3[(int)(state[3] >> 32) & 0xff] ^
            C4[(int)(state[2] >> 24) & 0xff] ^
            C5[(int)(state[1] >> 16) & 0xff] ^
            C6[(int)(state[0] >>  8) & 0xff] ^
            C7[(int)(state[7]      ) & 0xff] ^
            K[6];
        L[7] =
            C0[(int)(state[7] >> 56)       ] ^
            C1[(int)(state[6] >> 48) & 0xff] ^
            C2[(int)(state[5] >> 40) & 0xff] ^
            C3[(int)(state[4] >> 32) & 0xff] ^
            C4[(int)(state[3] >> 24) & 0xff] ^
            C5[(int)(state[2] >> 16) & 0xff] ^
            C6[(int)(state[1] >>  8) & 0xff] ^
            C7[(int)(state[0]      ) & 0xff] ^
            K[7];
        state[0] = L[0];
        state[1] = L[1];
        state[2] = L[2];
        state[3] = L[3];
        state[4] = L[4];
        state[5] = L[5];
        state[6] = L[6];
        state[7] = L[7];
    }

    out_whirlpool->hash[0] ^= state[0] ^ block[0];
    out_whirlpool->hash[1] ^= state[1] ^ block[1];
    out_whirlpool->hash[2] ^= state[2] ^ block[2];
    out_whirlpool->hash[3] ^= state[3] ^ block[3];
    out_whirlpool->hash[4] ^= state[4] ^ block[4];
    out_whirlpool->hash[5] ^= state[5] ^ block[5];
    out_whirlpool->hash[6] ^= state[6] ^ block[6];
    out_whirlpool->hash[7] ^= state[7] ^ block[7];
}

static void         ft_whirlpool_init(t_whirlpool *out_whirlpool)
{
    int i;

    ft_memset(out_whirlpool->bitLength, 0, 32);
    out_whirlpool->bufferBits = out_whirlpool->bufferPos = 0;
    out_whirlpool->buffer[0] = 0;

    i = 0;
    while (i < 8)
        out_whirlpool->hash[i++] = 0L;
}

static void			ft_whirlpool_add_length(uint64_t sourceBits, t_whirlpool *out_whirlpool)
{
	int			i;
	uint32_t	carry;
	uint8_t		*bitLength;
	uint64_t	value;

	i = 31;
	carry = 0;
	bitLength = out_whirlpool->bitLength;
	value = sourceBits;
	while (i >= 0 && (carry != 0 || value != LL(0)))
	{
		carry += bitLength[i] + ((uint32_t)value & 0xff);
		bitLength[i] = (uint8_t)carry;
		carry >>= 8;
		value >>= 8;

		i = i - 1;
	}
}

static void			ft_whirlpool_add_bits_digest(t_whirlpool *out_whirlpool, uint32_t *b)
{
	int bufferRem;

	bufferRem = out_whirlpool->bufferBits & 7;
	out_whirlpool->buffer[out_whirlpool->bufferPos++] |= (uint8_t)(*b >> bufferRem);
	out_whirlpool->bufferBits += 8 - bufferRem;

	if (out_whirlpool->bufferBits == DIGESTBITS)
	{
		processBuffer(out_whirlpool);
		out_whirlpool->bufferBits = 0;
		out_whirlpool->bufferPos = 0;
	}

	out_whirlpool->buffer[out_whirlpool->bufferPos] = *b << (8 - bufferRem);
	out_whirlpool->bufferBits += bufferRem;
}

static void			ft_whirlpool_add_bits(t_puchar source, uint64_t sourceBits, t_whirlpool *out_whirlpool, uint32_t *b)
{
	int bufferRem;
	int sourcePos;
	int sourceGap;

	bufferRem = out_whirlpool->bufferBits & 7;
	sourcePos = 0;
	sourceGap = (8 - ((int)sourceBits & 7)) & 7;
	while (sourceBits > 8)
	{
		*b = ((source[sourcePos] << sourceGap) & 0xff) |
			((source[sourcePos + 1] & 0xff) >> (8 - sourceGap));

		ft_whirlpool_add_bits_digest(out_whirlpool, b);

		sourceBits -= 8;
		sourcePos++;
	}

	if (sourceBits > 0)
	{
		*b = (source[sourcePos] << sourceGap) & 0xff;
		out_whirlpool->buffer[out_whirlpool->bufferPos] |= *b >> bufferRem;
	}
	else
		*b = 0;
}

static void			ft_whirlpool_add_buffer(uint64_t sourceBits, t_whirlpool *out_whirlpool, uint32_t b)
{
	int bufferRem;

	bufferRem = out_whirlpool->bufferBits & 7;
	if (bufferRem + sourceBits < 8)
		out_whirlpool->bufferBits += sourceBits;
	else
	{
		out_whirlpool->bufferPos++;
		out_whirlpool->bufferBits += 8 - bufferRem;
		sourceBits -= 8 - bufferRem;
		if (out_whirlpool->bufferBits == DIGESTBITS)
		{
			processBuffer(out_whirlpool);
			out_whirlpool->bufferBits = out_whirlpool->bufferPos = 0;
		}
		out_whirlpool->buffer[out_whirlpool->bufferPos] = b << (8 - bufferRem);
		out_whirlpool->bufferBits += (int)sourceBits;
	}
}

static void         ft_whirlpool_add(t_puchar source, uint64_t sourceBits, t_whirlpool *out_whirlpool)
{
    uint32_t		b;

    ft_whirlpool_add_length(sourceBits, out_whirlpool);
	ft_whirlpool_add_bits(source, sourceBits, out_whirlpool, &b);
	ft_whirlpool_add_buffer(sourceBits, out_whirlpool, b);
}

static void         ft_whirlpool_end_digest(t_whirlpool *out_whirlpool, uint8_t *digest)
{
    int         i;

    i = 0;
    while (i < DIGESTBYTES / 8)
    {
        digest[0] = (uint8_t)(out_whirlpool->hash[i] >> 56);
        digest[1] = (uint8_t)(out_whirlpool->hash[i] >> 48);
        digest[2] = (uint8_t)(out_whirlpool->hash[i] >> 40);
        digest[3] = (uint8_t)(out_whirlpool->hash[i] >> 32);
        digest[4] = (uint8_t)(out_whirlpool->hash[i] >> 24);
        digest[5] = (uint8_t)(out_whirlpool->hash[i] >> 16);
        digest[6] = (uint8_t)(out_whirlpool->hash[i] >>  8);
        digest[7] = (uint8_t)(out_whirlpool->hash[i]      );
        digest += 8;

        i = i + 1;
    }
}

static void         ft_whirlpool_finalize(t_whirlpool *out_whirlpool, uint8_t *digest)
{
    uint8_t     *buffer = out_whirlpool->buffer;
    int         bufferBits = out_whirlpool->bufferBits;
    int         bufferPos = out_whirlpool->bufferPos;

    buffer[bufferPos++] |= 0x80U >> (bufferBits & 7);

    if (bufferPos > WBLOCKBYTES - LENGTHBYTES) {
        if (bufferPos < WBLOCKBYTES)
            ft_memset(&buffer[bufferPos], 0, WBLOCKBYTES - bufferPos);
        processBuffer(out_whirlpool);
        bufferPos = 0;
    }
    if (bufferPos < WBLOCKBYTES - LENGTHBYTES)
        ft_memset(&buffer[bufferPos], 0, (WBLOCKBYTES - LENGTHBYTES) - bufferPos);
    bufferPos = WBLOCKBYTES - LENGTHBYTES;
    ft_memcpy(&buffer[WBLOCKBYTES - LENGTHBYTES], out_whirlpool->bitLength, LENGTHBYTES);
    processBuffer(out_whirlpool);

    ft_whirlpool_end_digest(out_whirlpool, digest);

    out_whirlpool->bufferBits   = bufferBits;
    out_whirlpool->bufferPos    = bufferPos;
}

static void display(const uint8_t array[], int length) {
	int i;
	for (i = 0; i < length; i++) {
		if (i%32 == 0) {
			printf("\n");
		}
		if (i%8 == 0) {
			printf(" ");
		}
		printf("%02X", array[i]);
	}
}

void makeISOTestVectors() {
	t_whirlpool w;
	uint8_t digest[DIGESTBYTES];
	static uint8_t data[1000000];

	ft_memset(data, 0, sizeof(data));

	printf("1. In this example the data-string is the empty string, i.e. the string of length zero.\n\n");
	ft_whirlpool_init(&w);
	ft_whirlpool_add(data, 8*0, &w);
	ft_whirlpool_finalize(&w, digest);
	printf("The hash-code is the following 512-bit string.\n\n");
	display(digest, DIGESTBYTES); printf("\n\n");

	printf("2. In this example the data-string consists of a single byte, namely the ASCII-coded version of the letter 'a'.\n\n");
	ft_whirlpool_init(&w);
	ft_whirlpool_add("a", 8*1, &w);
	ft_whirlpool_finalize(&w, digest);
	printf("The hash-code is the following 512-bit string.\n\n");
	display(digest, DIGESTBYTES); printf("\n\n");

	printf("3. In this example the data-string is the three-byte string consisting of the ASCII-coded version of 'abc'.\n\n");
	ft_whirlpool_init(&w);
	ft_whirlpool_add("abc", 8*3, &w);
	ft_whirlpool_finalize(&w, digest);
	printf("The hash-code is the following 512-bit string.\n\n");
	display(digest, DIGESTBYTES); printf("\n\n");

	printf("4. In this example the data-string is the 14-byte string consisting of the ASCII-coded version of 'message digest'.\n\n");
	ft_whirlpool_init(&w);
	ft_whirlpool_add("message digest", 8*14, &w);
	ft_whirlpool_finalize(&w, digest);
	printf("The hash-code is the following 512-bit string.\n\n");
	display(digest, DIGESTBYTES); printf("\n\n");

	printf("5. In this example the data-string is the 26-byte string consisting of the ASCII-coded version of 'abcdefghijklmnopqrstuvwxyz'.\n\n");
	ft_whirlpool_init(&w);
	ft_whirlpool_add("abcdefghijklmnopqrstuvwxyz", 8*26, &w);
	ft_whirlpool_finalize(&w, digest);
	printf("The hash-code is the following 512-bit string.\n\n");
	display(digest, DIGESTBYTES); printf("\n\n");

	printf("6. In this example the data-string is the 62-byte string consisting of the ASCII-coded version of 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'.\n\n");
	ft_whirlpool_init(&w);
	ft_whirlpool_add("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", 8*62, &w);
	ft_whirlpool_finalize(&w, digest);
	printf("The hash-code is the following 512-bit string.\n\n");
	display(digest, DIGESTBYTES); printf("\n\n");

	printf("7. In this example the data-string is the 80-byte string consisting of the ASCII-coded version of eight repetitions of '1234567890'.\n\n");
	ft_whirlpool_init(&w);
	ft_whirlpool_add("12345678901234567890123456789012345678901234567890123456789012345678901234567890", 8*80, &w);
	ft_whirlpool_finalize(&w, digest);
	printf("The hash-code is the following 512-bit string.\n\n");
	display(digest, DIGESTBYTES); printf("\n\n");

	printf("8. In this example the data-string is the 32-byte string consisting of the ASCII-coded version of 'abcdbcdecdefdefgefghfghighijhijk'.\n\n");
	ft_whirlpool_init(&w);
	ft_whirlpool_add("abcdbcdecdefdefgefghfghighijhijk", 8*32, &w);
	ft_whirlpool_finalize(&w, digest);
	printf("The hash-code is the following 512-bit string.\n\n");
	display(digest, DIGESTBYTES); printf("\n\n");
	fflush(stdout);

	ft_memset(data, 'a', 1000000);
	printf("9. In this example the data-string is the 1000000-byte string consisting of the ASCII-coded version of 'a' repeated 10^6 times.\n\n");
	ft_whirlpool_init(&w);
	ft_whirlpool_add(data, 8*1000000, &w);
	ft_whirlpool_finalize(&w, digest);
	printf("The hash-code is the following 512-bit string.\n\n");
	display(digest, DIGESTBYTES); printf("\n\n");
	fflush(stdout);

	printf("\n");
	fflush(stdout);
}

extern void         ft_whirlpool_main(t_pchar string)
{
    t_whirlpool     w;
    uint8_t         digest[DIGESTBYTES];

    ft_whirlpool_init(&w);
    ft_whirlpool_add((t_puchar) string, 8 * ft_strlen(string), &w);
	ft_whirlpool_finalize(&w, digest);
}

int main(int argc, char *argv[]) {
//    if (argc == 2)
//        ft_whirlpool_main(argv[1]);

	makeISOTestVectors();
    return 0;
}
