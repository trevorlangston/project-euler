#include <stdio.h>
#include <time.h>

/** A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, */
/** a2 + b2 = c2 For example, 32 + 42 = 9 + 16 = 25 = 52. */
/** There exists exactly one Pythagorean triplet for which a + b + c = 1000.  Find */
/** the product abc. */

int main()
{
    clock_t begin = clock();

    int a, b, c;
    for (a = 1; a < 1000; a++) {
        for (b = 1; b < 1000; b++) {
            c = 1000 - a - b;
            if (a * a + b * b == c * c) {
                int answer = a * b * c;
                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("a: %d\nb: %d\nc: %d\nabc: %d\n", a, b, c, answer);
                printf("Time spent: %f seconds", time_spent);
                return 0;
            }
        }
    }
}
