#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "common.h"

int main()
{
    if (clz(0) != 32) printf("Error on 0\n");
    #pragma omp parallel for
    for (uint32_t i = 1; i <= 0xFFFFFFFE; ++i) {
        if (clz(i) != __builtin_clz(i)) {
            printf("Error on %u\n", i);
        }
    }

    return 0;
}
