#include <stdio.h>
#include <string.h>
#include <time.h>

/** A palindromic number reads the same both ways. The largest palindrome made from */
/** the product of two 2-digit numbers is 9009 = 91 × 99.  Find the largest */
/** palindrome made from the product of two 3-digit numbers. */

int is_palindrome(long num);

int main()
{
    clock_t begin = clock();

    long largest = 0;
    int i;

    for (i = 100 * 100; i <= 999 * 999; i++) {
        if (i > largest && is_palindrome(i)) {
            largest = i;
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("size of int: %ldn", sizeof(int));
    printf("Largest: %ld\n", largest);
    printf("Time spent: %f seconds", time_spent);
}

int is_palindrome(long num)
{
    char str[24];
    sprintf(str, "%ld", num);
    int len = strlen(str);

    int i;
    for (i = 0; i < (len / 2); i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}
