#include <stdio.h>
#include <time.h>
#include <math.h>

/** The sequence of triangle numbers is generated by adding the natural numbers. So */
/** the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten */
/** terms would be: */

/** 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ... */

/** Let us list the factors of the first seven triangle numbers: */

/**  1: 1 */
/**  3: 1,3 */
/**  6: 1,2,3,6 */
/** 10: 1,2,5,10 */
/** 15: 1,3,5,15 */
/** 21: 1,3,7,21 */
/** 28: 1,2,4,7,14,28 */
/** We can see that 28 is the first triangle number to have over five divisors. */

/** What is the value of the first triangle number to have over five hundred divisors? */

int main()
{
    clock_t begin = clock();

    long sum = 0;
    int divisors = 0;

    int i, j;
    for(i = 0; divisors < 500; i++) {
        sum += i;
        divisors = 0;
        for (j = 1; j <= sqrt(sum); j++) {
            if (sum % j == 0) {
                if (sum / j == j) {
                    divisors++;
                } else {
                    divisors += 2;
                }
            }
        }
        printf("%ld: %d\n", sum, divisors);
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f seconds", time_spent);
}

