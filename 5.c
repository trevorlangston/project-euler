#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/** 2520 is the smallest number that can be divided by each of the numbers from 1 */
/** to 10 without any remainder.  What is the smallest positive number that is */
/** evenly divisible by all of the numbers from 1 to 20? */

int main()
{
    clock_t begin = clock();

    int max = 20;

    /** use sieve of eratosthenes to find all primes less or equal to max */
    int sieve_count = max + 1;

    int sieve[sieve_count];
    memset(sieve, 0, sizeof sieve);

    int i, j;
    for (i = 2; i < sieve_count; i++) {
        if (sieve[i] == 0) {
            for (j = i * i; j <= max; j += i) {
                sieve[j] = 1;
            }
        }
    }

    int n_primes = 0;
    for (i = 2; i < sieve_count; i++) {
        if (sieve[i] == 0) {
            n_primes++;
        }
    }

    int primes[n_primes];
    int offset = 0;
    for (i = 2; i < sieve_count; i++) {
        if (sieve[i] == 0) {
            primes[offset++] = i;
        }
    }

    /** calculate lcm */
    long lcm = 1;
    for (i = 0; i < n_primes; i++) {
        int exp = 1;
        int squared = primes[i];
        while (1) {
            squared *= primes[i];
            if (squared <= max) {
                exp++;
            } else {
                break;
            }
        }
        lcm *= pow(primes[i], exp);
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The lcm is: %ld\n", lcm);
    printf("Time spent: %f seconds", time_spent);
}
