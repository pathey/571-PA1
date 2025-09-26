#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]){
	int N;
	int sum = 0;
	int i;
	sscanf(argv[1], "%d", &N);
	for (i=0; i <= N; i++){
		sum += i;
	}
	printf("Sum: %d \n", sum);
}
