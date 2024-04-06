#include <cs50.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    int n = get_int("Number: ");

    printf("factorial: %i\n", fact(n));
}

int fact(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }
    // recursive case
    return n * fact(n - 1);
}
