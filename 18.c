#include <stdio.h>
#include <time.h>

int main()
{
    clock_t begin = clock();

    int triangle [15][15];

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time spent: %f seconds", time_spent);
}
