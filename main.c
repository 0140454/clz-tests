#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#include "common.h"

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main()
{

#if defined(VERIFY)
    if (clz(0) != 32) printf("Error on 0\n");
    #pragma omp parallel for
    for (uint32_t i = 1; i <= 0xFFFFFFFE; ++i) {
        if (clz(i) != __builtin_clz(i)) {
            printf("Error on %u\n", i);
        }
    }
#else
    FILE *fp = fopen(OUTPUT_NAME ".txt", "w");
    struct timespec start, end;

    for (uint32_t i = 0; i <= 0x00FFFFFF; ++i) {
        clock_gettime(CLOCK_REALTIME, &start);
        clz(i);
        clock_gettime(CLOCK_REALTIME, &end);
        fprintf(fp, "%u %lf\n", i, diff_in_second(start, end) * 1000000);
    }

    fclose(fp);
#endif

    return 0;
}
