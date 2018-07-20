#include<stdio.h>
#include<stdlib.h>

/** The prime factors of 13195 are 5, 7, 13 and 29. */
/** What is the largest prime factor of the number 600851475143 ? */

void calc_next_prime(long *prime, int primes_offset);

int main(int argc, char *argv[])
{
    long prime = 600851475143;

    long *primes;
    primes = (long*)calloc(1, sizeof(long));
    *primes = 2;

    int primes_offset = 0;

    if(primes == NULL) {
        printf("Error.Not enough space available");
        return 0;
    }

    int i = 0;
    while (1) {
        if (primes_offset < i) {
            calc_next_prime(primes, primes_offset);
            primes_offset++;
        }

        long current_prime = *(primes+i);

        if (current_prime >= prime) {
            printf("%ld\n", current_prime);
            return 0;
        }

        if (prime % current_prime == 0) {
            printf("%ld\n", current_prime);
            prime /= current_prime;
            i = 0;
        } else {
            i++;
        }
    }

    return 0;
}

void calc_next_prime(long *primes, int primes_offset) {
    long current_prime = *(primes + primes_offset);
    long possible_prime = current_prime + 1;

    while (1) {

        int i;
        int is_prime = 1;
        for (i = 2; i < possible_prime; i++) {
            if (possible_prime % i == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            *(primes + primes_offset + 1) = possible_prime;
            return;
        }

        possible_prime++;
    }
}
