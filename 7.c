#include <stdio.h>
#include <math.h>
#include <time.h>

/** By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that */
/** the 6th prime is 13. */
/** What is the 10,001st prime number? */

int is_prime(long num);

int main()
{
    clock_t begin = clock();

    int found = 1;
    long last = 2;
    int i = 3;

    while (found < 10001) {
        if (is_prime(i)) {
            found++;
            last = i;
        }
        i+= 2;
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The 10001st prime is %ld\n", last);
    printf("Time spent: %f seconds", time_spent);
}

int is_prime(long num)
{
    int i;
    if (num % 3 == 0) {
        return 0;
    }

    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}
