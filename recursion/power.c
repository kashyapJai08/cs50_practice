#include <stdio.h>
#include <cs50.h>

int power(int n, int e);

int main(void)
{
    int n = get_int("number: ");
    int e = get_int("exponent: ");

    printf("answer: %i\n", power(n, e));
}

int power(int n, int e)
{
    // base case
    if (e == 0)
    {
        return 1;
    }

    // recursive case
    return n * power(n, e - 1);
}
