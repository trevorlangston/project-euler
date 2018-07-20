#include<stdio.h>

/** A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, */
/** a2 + b2 = c2 For example, 32 + 42 = 9 + 16 = 25 = 52. */
/** There exists exactly one Pythagorean triplet for which a + b + c = 1000.  Find */
/** the product abc. */

int main(int argc, char *argv[])
{
    int a, b, c;
    for (a = 1; a < 1000; a++) {
        for (b = 1; b < 1000; b++) {
            c = 1000 - a - b;
            if (a * a + b * b == c * c) {
                int answer = a * b * c;
                printf("a is %d, b is %d and c is %d\n", a, b, c);
                printf("%d", answer);
                return 0;
            }
        }
    }

    return 0;
}
