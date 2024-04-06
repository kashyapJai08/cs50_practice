#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main(void)
{
    int n1 = get_int("enter positive integer 1: ");
    int n2 = get_int("enter positive integer 2: ");

    printf("Greatest common divisor: %i\n", gcd(n1, n2));
}

int gcd(int a, int b)
{
    // base case
    if (b == 0)
    {
        return a;
    }
    // RECURSION
    return gcd(b, a % b);
}

