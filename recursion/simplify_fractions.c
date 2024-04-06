#include <cs50.h>
#include <stdio.h>

void simplifyFractions(int n, int d);
int gcd(int n, int d);

int main(void)
{
    int numerator = get_int("Numerator: ");
    int denominator = get_int("Denominator: ");

    simplifyFractions(numerator, denominator);
}

int gcd(int n, int d)
{
    if (d == 0)
    {
        return n;
    }

    return gcd(d, n % d);
}

void simplifyFractions(int n, int d)
{
    int i = gcd(n, d);
    printf("Simplified fraction: \nNumerator: %i\nDenominator: %i\n", n / i, d / i);
}
