#include <cs50.h>
#include <math.h>
#include <stdio.h>


int main(void)
{
    int number = get_int("Number: ");
    int divisors[(int) sqrt(number)];

    int size = sizeof(divisors) / sizeof(divisors[0]);
    findDivisors(number, divisors);

    // printf("Largest prime factor of %i: %i\n", number, largestPrimeFactor(number, number, prime_numbers, size));
}

findDivisors(int n, int i, int divisors[], int size)
{
    // base case
    if (i == 1)
    {
        return i;
    }
    // recursive case
    findDivisors()

    for (int k = 0; k < size; k++)
    {   if (number % i == 0)
        {
            divisors[k] == i;
        }
    }
}

checkPrime(int i)
{
    for (int j = i; j > 1; j--)
    {
        if (i % j == 0 && (j == i || j == 1))
        {
            return true; // prime
        }
    }
    return false;
}
