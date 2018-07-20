#include<stdio.h>

/** The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17. */
/** Find the sum of all the primes below two million. */

int is_prime(long num);

int main(int argc, char *argv[])
{
    long sum = 0;
    int i;

    for (i = 2; i < 2000000; i++) {
        if (is_prime(i)) {
            sum += i;
        }
    }

    printf("%ld", sum);

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
