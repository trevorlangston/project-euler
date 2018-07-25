#include <stdio.h>

/** get 3, 5, 6 and 9. The sum of these multiples is 23. */
/** Find the sum of all the multiples of 3 or 5 below 1000. */

int main()
{
    int i;
    int total = 0;

    for (i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            total += i;
        }
    }

    printf("%d", total);
}
