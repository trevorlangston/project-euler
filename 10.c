#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/** The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17. */
/** Find the sum of all the primes below two million. */

int is_prime(long num, long *primes);

int main()
{
    clock_t begin = clock();

    long max = 2000000;
    long sum = 2;

    int primes_offset = 0;
    long *primes;
    primes = (long*)calloc(max, sizeof(long));
    *primes = 2;

    long i;
    for (i = 3; i < max; i+= 2) {
        if (is_prime(i, primes)) {
            primes_offset++;
            *(primes + primes_offset) = i;
            sum += i;
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The sum is: %ld\n", sum);
    printf("Time spent: %f seconds", time_spent);

    free(primes);
}

int is_prime(long num, long *primes)
{
    int primes_offset = 0;
    long prime;

    while (1) {
        prime = *(primes + primes_offset);
        if (prime > sqrt(num)) {
            return 1;
        }

        if (num % prime == 0) {
            return 0;
        }

        primes_offset++;
    }

    return 1;
}
