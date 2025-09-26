#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]){
	int N;
	int sum = 0;
	int i;
	time_t start, end;

	sscanf(argv[1], "%d", &N);
	
	start = clock();

	for (i=0; i <= N; i++){
		sum += i;
	}

	end = clock();

	double elapsed = (double)(end - start) / (double)(CLOCKS_PER_SEC);
	
	printf("%.6f seconds elapsed\n", elapsed);	
	printf("Sum: %d \n \n", sum);

	
}
