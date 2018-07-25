#include <stdio.h>
#include <time.h>

/** The following iterative sequence is defined for the set of positive integers: */
/** n → n/2 (n is even) n → 3n + 1 (n is odd) */

/** Using the rule above and starting with 13, we generate the following sequence: */
/** 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1 */

/** It can be seen that this sequence (starting at 13 and finishing at 1) contains */
/** 10 terms. Although it has not been proved yet (Collatz Problem), it is thought */
/** that all starting numbers finish at 1. */

/** Which starting number, under one million, produces the longest chain? */

/** NOTE: Once the chain starts the terms are allowed to go above one million. */

int distance[1000000] = {0};

int main()
{
    clock_t begin = clock();

    int stop = 1000000;
    int largest_num;
    int largest_chain = 1;

    int i;
    long j;
    int count;
    for (i = 1; i < stop; i++) {
        count = 1;
        j = i;

        while (j > 1) {
            if (j < i) {
                count += distance[j];
                break;
            }

            // Collatz algorithm
            if (j % 2 == 0) {
                j /= 2;
            } else {
                j = 3 * j + 1;
            }

            count++;
        }

        distance[i] = count - 1;

        if (count > largest_chain) {
            largest_chain = count;
            largest_num = i;
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%d: %d\n", largest_num, largest_chain);
    printf("Time spent: %f seconds", time_spent);
}
