#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/** Starting in the top left corner of a 2×2 grid, and only being able to move to */
/** the right and down, there are exactly 6 routes to the bottom right corner. */

/** How many such routes are there through a 20×20 grid? */

unsigned long long factorial(unsigned long long num);

int main()
{
    clock_t begin = clock();

    /** Rotate the lattice so the top left corner is on top and you'll see that */
    /** this is Pascal's triangle. We could compute the answer directly */
    /** with 40 choose 20, but that involves calculating really large */
    /** factorials. Here we just build the triangle row by row until we find */
    /** the answer. */

    long pascals[41] = {1};   // current row in pascals triangle
    long next_row[41] = {1};  // temporary copy of current row

    long val;
    int i,j;
    for (i = 0; i < 41; i++) {
        for (j = 0; j < i + 1; j++) {
            if (j == 0 || j == i + 1) {
                val = 1;
            } else {
                val = pascals[j-1] + pascals[j];
            }
            next_row[j] = val;
        }
        memcpy(pascals, next_row, 41 * sizeof(long));
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Routes: %ld ", pascals[20]);
    printf("Time spent: %f seconds", time_spent);
}
