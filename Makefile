all: 	PA1_Serial
	PA1_Multithread

CC = gcc

PA1_Serial:		PA1_Serial.o
			$(CC) PA1_Serial.c -o PA1_Serial

PA1_Multithread:	PA1_Multithread.o
			$(CC) -O2 -pthread -o PA1_Multithread PA1_Multithread.c

RUNS = 15
N = 100000000 1000000000 10000000000
NUM_THREADS = 2 4 8
NUM_TASKS = 2 4 8

run_serial: PA1_Serial
		@for n in $(N); do \
			echo "Running with N=$$n..." >&2; \
			./PA1_Serial $$n; \
		done

run_multithread:	PA1_Multithread
				@for t in $(NUM_THREADS); do \
					echo "Running with Threads=$$t..." >&2; \
					for n in $(N); do \
						echo "Running with N=$$n..." >&2; \
						./PA1_Multithread $$n $$t; \
					done \
				done
