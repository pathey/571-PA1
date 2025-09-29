PA #1

The sums from 1 to N are non-inclusive of N for all programs as stated in the assignment instructions.

PA1_Serial.c corresponds to case 1: Baseline.
PA1_Multitasking_Fork.c corresponds to case 3: Multitasking (option 1)

To compile PA1_Serial.c run `gcc PA1_Serial.c -o a.o` in the terminal
To compile PA1_Multitasking_Fork.c run `gcc PA1_Multitasking_Fork.c -lm -o b.o` in the terminal

to execute PA1_Serial.c run `./a.o N` after compiling where N is {100000000, 1000000000, 10000000000}
to execute PA1_Multitasking_Fork.c run `./b.o N NUM_TASKS` after compiling where NUM_TASKS is {2, 4, 8}
