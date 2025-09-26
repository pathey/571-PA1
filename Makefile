all: PA1_Serial

CC = gcc

PA1_Serial:	PA1_Serial.o
		$(CC) PA1_Serial.c -o PA1_Serial

PA1_Multithread: 

N = 1 10 100 1000 100000000

run_serial: PA1_Serial
		@for n in $(N); do \
			echo "Running with N=$$n..." >&2; \
			./PA1_Serial $$n; \
		done

		
