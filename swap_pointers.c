#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));
    y = malloc(sizeof(int));

    if (x == NULL || y == NULL)
    {
        return 1;
    }

    *x = 4;
    *y = 7;

    printf("x: %i | y: %i\n", *x, *y);
    swap(x , y);
    printf("x: %i | y: %i\n", *x, *y);

    free(x);
    free(y);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
