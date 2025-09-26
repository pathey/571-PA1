#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, const char *argv[]){
    unsigned long long int sum = 0, N, i;

    N = strtoull(argv[1], NULL, 10); //string to ull (unsigned long long)

	for (i=0; i < N; i++){ //non-inclusive sum
		sum += i;
	}
	printf("Sum from 1 to %llu (non-inclusive): %llu \n", N, sum);
}
