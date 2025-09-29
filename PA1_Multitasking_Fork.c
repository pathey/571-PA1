#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <sys/wait.h>

#define BILLION 1000000000UL //UL: unsigned long

int main (int argc, const char *argv[]){
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    double exetime, sec, nanosec;    //execution time
    unsigned long long int sum = 0, N, i, interval;
    unsigned int NUM_TASKS = strtol(argv[2], NULL, 10);
    unsigned int pid_array_size = log2(NUM_TASKS); //calculate how many trackers using log base 2
    int pid[pid_array_size];         //pid array to keep track of NUM_TASKS
    int fd[2]; //array for pipe: write to fd[1], read from fd[0]
    unsigned long long int start_sum, end_sum, partial_sum = 0;

    N = strtoull(argv[1], NULL, 10); //string to ull (unsigned long long)
    interval = N / NUM_TASKS;
    pipe(fd);       //creation of pipe


    for(i = 0; i < pid_array_size; i++){
        pid[i] = fork();    //number of forks based on how many tasks desired
    }

    if(pid_array_size == 3){
        if((pid[0] > 0) && (pid[1] > 0) && (pid[2] > 0)){
            start_sum = interval * (0) + 1;
            end_sum = interval * (1);

            for(i = start_sum; i <= end_sum; i++){
                partial_sum += i;
            }

            sum = partial_sum;

            for(i = 0; i < NUM_TASKS - 1; i++){
                wait(NULL);
            }

            for(i = 0; i < NUM_TASKS - 1; i++){
                close(fd[1]); //close write side of pipe
                read(fd[0], &partial_sum, sizeof(partial_sum)); //read from each child
                sum += partial_sum;     //add each partial sum
            }
            
        }
        else if((pid[0] > 0) && (pid[1] > 0) && (pid[2] == 0)){
            start_sum = interval * (1) + 1;
            end_sum = interval * (2);

            for(i = start_sum; i <= end_sum; i++){
                partial_sum += i;
            }

            close(fd[0]); //sender closes read
            write(fd[1], &partial_sum, sizeof(partial_sum)); //write to pipe
            exit(0);
        }
        else if((pid[0] > 0) && (pid[1] == 0) && (pid[2] > 0)){
            start_sum = interval * (2) + 1;
            end_sum = interval * (3);

            for(i = start_sum; i <= end_sum; i++){
                partial_sum += i;
            }

            close(fd[0]); //sender closes read
            write(fd[1], &partial_sum, sizeof(partial_sum)); //write to pipe
            exit(0);
        }
        else if((pid[0] > 0) && (pid[1] == 0) && (pid[2] == 0)){
            start_sum = interval * (3) + 1;
            end_sum = interval * (4);

            for(i = start_sum; i <= end_sum; i++){
                partial_sum += i;
            }

            close(fd[0]); //sender closes read
            write(fd[1], &partial_sum, sizeof(partial_sum)); //write to pipe
            exit(0);
        }
        else if((pid[0] == 0) && (pid[1] > 0) && (pid[2] > 0)){
            start_sum = interval * (4) + 1;
            end_sum = interval * (5);

            for(i = start_sum; i <= end_sum; i++){
                partial_sum += i;
            }

            close(fd[0]); //sender closes read
            write(fd[1], &partial_sum, sizeof(partial_sum)); //write to pipe
            exit(0);
        }
        else if((pid[0] == 0) && (pid[1] > 0) && (pid[2] == 0)){
            start_sum = interval * (5) + 1;
            end_sum = interval * (6);

            for(i = start_sum; i <= end_sum; i++){
                partial_sum += i;
            }

            close(fd[0]); //sender closes read
            write(fd[1], &partial_sum, sizeof(partial_sum)); //write to pipe
            exit(0);
        }
        else if((pid[0] == 0) && (pid[1] == 0) && (pid[2] > 0)){
            start_sum = interval * (6) + 1;
            end_sum = interval * (7);

            for(i = start_sum; i <= end_sum; i++){
                partial_sum += i;
            }

            close(fd[0]); //sender closes read
            write(fd[1], &partial_sum, sizeof(partial_sum)); //write to pipe
            exit(0);
        }
        else if((pid[0] == 0) && (pid[1] == 0) && (pid[2] == 0)){
            start_sum = interval * (7) + 1;
            end_sum = interval * (8);

            for(i = start_sum; i < end_sum; i++){
                partial_sum += i;
            }
            close(fd[0]); //sender closes read
            write(fd[1], &partial_sum, sizeof(partial_sum)); //write to pipe
            exit(0);
        }
    }
    else if(pid_array_size == 2){
        if((pid[0] > 0) && (pid[1] > 0)){
            start_sum = interval * (0) + 1;
            end_sum = interval * (1);

            for(i = start_sum; i <= end_sum; i++){
                partial_sum += i;
            }

            sum = partial_sum;

            for(i = 0; i < NUM_TASKS - 1; i++){
                wait(NULL);
            }

            for(i = 0; i < NUM_TASKS - 1; i++){
                close(fd[1]); //close write side of pipe
                read(fd[0], &partial_sum, sizeof(partial_sum)); //read from each child

                sum += partial_sum;     //add each partial sum
            }
            
        }
        else if((pid[0] > 0) && (pid[1] == 0)){
            start_sum = interval * (1) + 1;
            end_sum = interval * (2);

            for(i = start_sum; i <= end_sum; i++){
                partial_sum += i;
            }

            close(fd[0]); //sender closes read
            write(fd[1], &partial_sum, sizeof(partial_sum)); //write to pipe
            exit(0);
        }
        else if((pid[0] == 0) && (pid[1] > 0)){
            start_sum = interval * (2) + 1;
            end_sum = interval * (3);

            for(i = start_sum; i <= end_sum; i++){
                partial_sum += i;
            }

            close(fd[0]); //sender closes read
            write(fd[1], &partial_sum, sizeof(partial_sum)); //write to pipe
            exit(0);
        }
        else if((pid[0] == 0) && (pid[1] == 0)){
            start_sum = interval * (3) + 1;
            end_sum = interval * (4);

            for(i = start_sum; i < end_sum; i++){
                partial_sum += i;
            }

            close(fd[0]); //sender closes read
            write(fd[1], &partial_sum, sizeof(partial_sum)); //write to pipe
            exit(0);
        }
    }
    else if(pid_array_size == 1){
        if((pid[0] > 0)){
            start_sum = interval * (0) + 1;
            end_sum = interval * (1);

            for(i = start_sum; i <= end_sum; i++){
                partial_sum += i;
            }

            sum = partial_sum;

            for(i = 0; i < NUM_TASKS - 1; i++){
                wait(NULL);
            }

            for(i = 0; i < NUM_TASKS - 1; i++){
                close(fd[1]); //close write side of pipe
                read(fd[0], &partial_sum, sizeof(partial_sum)); //read from each child

                sum += partial_sum;     //add each partial sum
            }
            
        }
        else if((pid[0] == 0)){
            start_sum = interval * (1) + 1;
            end_sum = interval * (2);

            for(i = start_sum; i < end_sum; i++){
                partial_sum += i;
            }

            close(fd[0]); //sender closes read
            write(fd[1], &partial_sum, sizeof(partial_sum)); //write to pipe
            exit(0);
        }
    }

    

	

    clock_gettime(CLOCK_MONOTONIC, &end);
    sec = end.tv_sec - start.tv_sec;
    nanosec = (double)(end.tv_nsec - start.tv_nsec) / BILLION; //tv_nsec defined as a long int
    exetime = sec + nanosec;
    printf("Execution time: %0.9f seconds \n", exetime);
    printf("Sum from 1 to %llu (non-inclusive): %llu \n", N, sum);
    printf("number of pid array elements %d \n", pid_array_size);
}
