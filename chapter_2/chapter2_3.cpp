#include <iostream>

#include "omp.h"

int main(int argc, char **argv)
{
    int tid, mcpu;

    tid = omp_get_thread_num();       ///< 获取线程号
    mcpu = omp_get_num_threads();     ///< 获取最大线程数量
    printf("Hello from thread %d in %d CPUs\n", tid, mcpu);
    printf("________before parallel\n");
    printf("\n");
    printf("________during parallel\n");

    #pragma omp parallel num_threads(3) private(tid, mcpu)
    {
        tid = omp_get_thread_num();
        mcpu = omp_get_num_threads();
        printf("Hello from thread %d in %d CPUs\n", tid, mcpu);
    }

    printf("\n");
    printf("_______after parallel\n");
    printf("Hello from thread %d in %d CPUs\n", tid, mcpu);

    return 0;
}