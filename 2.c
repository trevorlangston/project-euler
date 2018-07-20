#include<stdio.h>

int main(int argc, char *argv[])
{
    int i = 1;
    int j = 2;
    int temp;
    int sum = 2;

    while (i + j < 4000000) {
        temp = j;
        j += i;
        i = temp;

        if (j % 2 == 0) {
            sum += j;
        }
    }

    printf("%d", sum);

    return 0;
}

