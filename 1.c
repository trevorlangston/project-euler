#include<stdio.h>

int main(int argc, char *argv[])
{
    int total = 0;
    int i;

    for (i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            total += i;
        }
    }

    printf("%d", total);

    return 0;
}
