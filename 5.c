#include<stdio.h>

/** 2520 is the smallest number that can be divided by each of the numbers from 1 */
/** to 10 without any remainder.  What is the smallest positive number that is */
/** evenly divisible by all of the numbers from 1 to 20? */

int main(int argc, char *argv[])
{
    long smallest = 1;

    while (1) {
        int found = 1;

        for (int i = 2; i <= 20; i++) {
            if (smallest % i != 0) {
                found = 0;
                break;
            }
        }

        if (found) {
            printf("%ld", smallest);
            return 0;
        }

        smallest++;
    }
}
