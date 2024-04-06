#include <stdio.h>
// #include <math.h>

void square_add(int *a, int *b);
int main(void)
{
    int x = 4;
    int y = 5;

    int *p = NULL;

    printf("%i\n", *p);

    square_add(&x, &y);

    printf("sum: %i\n", x + y);
}

void square_add(int *a, int *b)
{
   *a = *a * *a;
   *b = *b * *b;
}
