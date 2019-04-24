//
// Created by Jonathan CARRA on 2019-04-24.
//

#include "libft.h"
#include "types.h"
#include "internal/whirlpool.h"

static void         ft_whirlpool_finalize_digest (t_whirlpool *out_whirlpool, uint8_t *digest)
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

extern void         ft_whirlpool_finalize(t_whirlpool *out_whirlpool, uint8_t *digest)
{
    uint8_t     *buffer = out_whirlpool->buffer;
    int         bufferBits = out_whirlpool->bufferBits;
    int         bufferPos = out_whirlpool->bufferPos;

    buffer[bufferPos++] |= 0x80U >> (bufferBits & 7);

    if (bufferPos > WBLOCKBYTES - LENGTHBYTES) {
        if (bufferPos < WBLOCKBYTES)
            ft_memset(&buffer[bufferPos], 0, WBLOCKBYTES - bufferPos);
		ft_whirlpool_process(out_whirlpool);
        bufferPos = 0;
    }
    if (bufferPos < WBLOCKBYTES - LENGTHBYTES)
        ft_memset(&buffer[bufferPos], 0, (WBLOCKBYTES - LENGTHBYTES) - bufferPos);
    bufferPos = WBLOCKBYTES - LENGTHBYTES;
    ft_memcpy(&buffer[WBLOCKBYTES - LENGTHBYTES], out_whirlpool->bitLength, LENGTHBYTES);
	ft_whirlpool_process(out_whirlpool);

	ft_whirlpool_finalize_digest(out_whirlpool, digest);

    out_whirlpool->bufferBits   = bufferBits;
    out_whirlpool->bufferPos    = bufferPos;
}

