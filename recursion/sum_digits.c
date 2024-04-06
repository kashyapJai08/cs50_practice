#include <cs50.h>
#include <stdio.h>

int sumDigits(int n);

int main(void)
{
    int n = get_int("Number: ");
    printf("Sum: %i\n", sumDigits(n));
}

// calculates the sum of digits of an integer
int sumDigits(int n)
{
    // base case
    if (n < 10)
    {
        return n;
    }
    
    // recursive case
    return (n % 10) + sumDigits(n / 10);
}
