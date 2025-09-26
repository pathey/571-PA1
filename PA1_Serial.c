#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BILLION 1000000000UL //UL: unsigned long

int main (int argc, const char *argv[]){
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    double exetime, sec, nanosec;    //execution time
    unsigned long long int sum = 0, N, i;

    N = strtoull(argv[1], NULL, 10); //string to ull (unsigned long long)

	for (i=0; i < N; i++){           //non-inclusive sum
		sum += i;
	}
	printf("Sum from 1 to %llu (non-inclusive): %llu \n", N, sum);

    clock_gettime(CLOCK_MONOTONIC, &end);
    sec = end.tv_sec - start.tv_sec;
    nanosec = (double)(end.tv_nsec - start.tv_nsec) / BILLION; //tv_nsec defined as a long int
    exetime = sec + nanosec;
    printf("Execution time: %0.9f seconds \n", exetime);
}
