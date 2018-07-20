#include<stdio.h>
#include<string.h>

/** A palindromic number reads the same both ways. The largest palindrome made from */
/** the product of two 2-digit numbers is 9009 = 91 × 99.  Find the largest */
/** palindrome made from the product of two 3-digit numbers. */

int is_palindrome(long num);

int main(int argc, char *argv[])
{
    long largest = 0;
    int i;
    int j;

    for (i = 100; i < 1000; i++) {
        for (j = i+1; j < 1000; j++) {
            long prod = i * j;
            if (prod > largest && is_palindrome(prod)) {
                largest = prod;
            }
        }
    }

    printf("%ld", largest);

    return 0;
}

int is_palindrome(long num)
{
    char str[24];
    sprintf(str, "%ld", num);

    int len = strlen(str);
    for (int i=0;i<(len/2);i++) {
        if (str[i] != str[len-i-1]) {
            return 0;
        }
    }

    return 1;
}
