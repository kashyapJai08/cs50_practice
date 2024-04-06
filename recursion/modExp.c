/************* MODULAR EXPONENTIATION *********************/

#include <stdio.h>
#include <cs50.h>

// Function prototype
int power(int n, int e, int m);

int main(void)
{
    int base = get_int("Base number: ");
    int exponent = get_int("Exponent: ");
    int modulus = get_int("Modulus: ");

    printf("Modular exponentiation: %i\n", power(base, exponent, modulus));
}

// Function to calculate modular exponentiation
int power(int b, int e, int m)
{
    // base case
    // We keep decreasing the exponent till we obtain 0, and then we return 1.
    if (e == 0)
    {
        return 1;
    }

    // recursive case
    // return (b * power(b, e - 1, m)) % m; //modular exponentiation formula

    // Half Exponent Method
    int halfExponent = e / 2;

    // Recursive calls for the halves of the exponent
    int result = power(b, halfExponent, m);
    result = (result * result) % m;

    // If exponent is odd, multiply by base and take modulo
    if (e % 2 == 1)
    {
        result = (result * b) % m;
    }

    return result;
}
