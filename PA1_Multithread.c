// PA1_Multithread.c
// Minimal pthread sum over [0, N) with N % T == 0.
// Usage: ./PA1_Multithread <N> <T>

#define _POSIX_C_SOURCE 200809L
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

typedef struct {
    unsigned long long start;   // inclusive
    unsigned long long end;     // exclusive
    unsigned long long *out;    // partial sum destination
} Task;

static void *worker(void *arg) {
    Task *t = (Task *)arg;
    unsigned long long s = 0;
    for (unsigned long long i = t->start; i < t->end; ++i) {
        s += i;
    }
    *t->out = s;
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <N> <T>\n", argv[0]);
        return 1;
    }

    unsigned long long N = strtoull(argv[1], NULL, 10);
    unsigned int T = (unsigned int)strtoul(argv[2], NULL, 10);

    unsigned long long chunk = N / T;

    pthread_t *threads = (pthread_t *)malloc(T * sizeof *threads);
    Task *tasks = (Task *)malloc(T * sizeof *tasks);
    unsigned long long *partials = (unsigned long long *)malloc(T * sizeof *partials);

    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);

    for (unsigned int i = 0; i < T; ++i) {
        unsigned long long start = i * chunk;
        unsigned long long end   = start + chunk;
        tasks[i].start = start;
        tasks[i].end   = end;
        tasks[i].out   = &partials[i];
        pthread_create(&threads[i], NULL, worker, &tasks[i]);
    }

    unsigned long long total = 0;
    for (unsigned int i = 0; i < T; ++i) {
        pthread_join(threads[i], NULL);
        total += partials[i]; // modulo 2^64 wrap is fine
    }

    clock_gettime(CLOCK_MONOTONIC, &t1);
    double elapsed = (t1.tv_sec - t0.tv_sec) + (t1.tv_nsec - t0.tv_nsec) / 1e9;

    printf("Sum (mod 2^64): %llu\n", total);
    printf("Elapsed: %.6f s\n", elapsed);

    free(threads);
    free(tasks);
    free(partials);
    return 0;
}

