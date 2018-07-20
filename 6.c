#include<stdio.h>
#include<math.h>

/** 2520 is the smallest number that can be divided by each of the numbers from 1 */
/** to 10 without any remainder.  What is the smallest positive number that is */
/** evenly divisible by all of the numbers from 1 to 20? */

int main(int argc, char *argv[])
{
    long sum_of_squares = 0;
    long square_of_sum = 0;
    long diff;
    int i;

    for (i = 1; i <= 100; i++) {
        square_of_sum += i;
        sum_of_squares += pow(i, 2);
    }

    square_of_sum = pow(square_of_sum, 2);
    diff = square_of_sum - sum_of_squares;
    printf("%ld\n", diff);

    return 0;
}
