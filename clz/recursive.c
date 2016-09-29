#include "common.h"

static uint32_t offset[] = { 16, 8, 4, 2, 1 };
static uint32_t mask[] = { 0xFFFF, 0x00FF, 0x000F, 0x0003, 0x0001 };

static int clz_helper(uint32_t x, int i)
{
    /* shift upper half down, rest is filled up with 0s */
    uint16_t upper = (x >> offset[i]);
	// mask upper half away
    uint16_t lower = (x & mask[i]);

    if (i == 4) return !upper;

    return upper ? clz_helper(upper, i + 1) : offset[i] + clz_helper(lower, i + 1);
}

int clz(uint32_t x)
{
    if (!x) return 32;

    clz_helper(x, 0);
}
