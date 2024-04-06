/**************************** PRIME FACTORIZATION *********************/
#include <cs50.h>
#include <stdio.h>

void primeFactorization(int n, int i);

int main(void)
{
    int number = get_int("Number: ");

    // We start with smallest prime number i.e. 2. we pass the number and 2 to the function.
    primeFactorization(number, 2);

    printf("\n");
}

void primeFactorization(int n, int i)
{
    // the function reduces the original number to 1 in which case the call backs happen
    // Base Case
    if (n == 1)
    {
        return;
    }

    /* In recursion we have to reduce the number to 1 and check for the potential divisors while doing so.
    So first we check whether a number, is a potential divisor or not and if it is then we recursively call the function
    passing this time (number / divisor) and the divisor to check for the power of divisor.
    If a number is not a divisor then we recursively call the function, this time passing the number as it is but incrementing the
    divisor by 1.*/

    // Recursion
    if (n % i == 0) //
    {
        // we keep printing the divisor before recursive call.
        printf("%i ", i); // this gives the divisors in increasing order
        primeFactorization(n / i, i);
        // printf("%i ", i); // this gives in decreasing order
    }
    else
    {
        primeFactorization(n, i + 1);
    }
}
