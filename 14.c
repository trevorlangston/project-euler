#include <stdio.h>
#include <math.h>
#include <time.h>

int distance[1000000] = {0};

int main()
{
    clock_t begin = clock();

    int stop = 1000000;
    int largest_num;
    int largest_chain = 1;

    int i;
    long j;
    int count;
    for (i = 1; i < stop; i++) {
        count = 1;
        j = i;

        while (j > 1) {
            if (j < i) {
                count += distance[j];
                break;
            }

            // Collatz algorithm
            if (j % 2 == 0) {
                j /= 2;
            } else {
                j = 3 * j + 1;
            }

            count++;
        }

        distance[i] = count - 1;

        if (count > largest_chain) {
            largest_chain = count;
            largest_num = i;
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%d: %d\n", largest_num, largest_chain);
    printf("Time spent: %f seconds", time_spent);
}
