#include<stdio.h>

/** By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that */
/** the 6th prime is 13. */
/** What is the 10 001st prime number? */

int is_prime(long num);

int main(int argc, char *argv[])
{
    int found = 0;
    long last = 0;
    int i = 2;

    while (found < 10001) {
        if (is_prime(i)) {
            found++;
            last = i;
        }
        i++;
    }

    printf("found %d primes\n", found);
    printf("the last prime is %ld", last);
    return 0;
}

int is_prime(long num)
{
    int i;
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;

        }
    }

    return 1;
}
