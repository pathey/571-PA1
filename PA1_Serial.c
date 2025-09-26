#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, const char *argv[]){
	time_t start, end;
  
  unsigned long long int sum = 0, N, i;

  N = strtoull(argv[1], NULL, 10); //string to ull (unsigned long long)

  start = clock();

	for (i=0; i < N; i++){ //non-inclusive sum
		sum += i;
	}
  
  end = clock();

	double elapsed = (double)(end - start) / (double)(CLOCKS_PER_SEC);
	
	printf("%.6f seconds elapsed\n", elapsed);	
  
	printf("Sum from 1 to %llu (non-inclusive): %llu \n", N, sum);
  
}
