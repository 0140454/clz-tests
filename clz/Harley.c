#include "common.h"

#define u 99

int clz(uint32_t x)
{
    static uint8_t const Table[] = {
        32,31, u,16, u,30, 3, u,  15, u, u, u,29,10, 2, u,
         u, u,12,14,21, u,19, u,   u,28, u,25, u, 9, 1, u,
        17, u, 4, u, u, u,11, u,  13,22,20, u,26, u, u,18,
         5, u, u,23, u,27, u, 6,   u,24, 7, u, 8, u, 0, u
    };

    /* Propagate leftmost 1-bit to the right */
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);

    /* x = x * 0x6EB14F9 */
    x = (x << 3) - x;   /* Multiply by 7. */
    x = (x << 8) - x;   /* Multiply by 255. */
    x = (x << 8) - x;   /* Again. */
    x = (x << 8) - x;   /* Again. */

    return Table[x >> 26];
}
