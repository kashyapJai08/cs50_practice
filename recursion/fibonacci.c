#include <stdio.h>
#include <cs50.h>

int fibo(int n);

int main(void)
{
    int n = get_int("number: ");

    int i = n;
    printf("%ith fibonacci number: %i\n", i, fibo(n));
}

int fibo(int n)
{
    // base case
    if (n <= 1)
    {
        return n;
    }

    // recursive case
    return fibo(n - 1) + fibo(n - 2);
}
