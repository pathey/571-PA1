#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, const char *argv[]){
	int i;
    unsigned long long int sum = 0, N;

	sscanf(argv[1], "%lld", &N);

	for (i=0; i < N; i++){ //non-inclusive sum
		sum += i;
	}
	printf("Sum from 1 to %lld (non-inclusive): %lld \n", N, sum);
}
