#include <cs50.h>
#include <stdio.h>

int sumOfDivisors(int n, int i);
// int sum = 0;
int main(void)
{
    int number = get_int("Number: ");

    // for (int i = number; i >= 1; i--)
    // {
    //     if (number % i == 0)
    //     {
    //         sum = sum + i;
    //     }
    // }

    // printf("Sum of divisors of %i is %i\n", number, sum);
    printf("Sum of divisors of %i is %i\n", number, sumOfDivisors(number, number));
}

int sumOfDivisors(int n, int i)
{
    /* Each recursive call to sumOfDivisors
    has its own independent sum variable, and
    they do not share the same memory space.
    Therefore, when you add values to sum in one recursive call,
    it does not affect the sum in other recursive calls.

    To maintain the accumulated sum across recursive calls,
    you need to either use a global variable
    (which is not recommended due to potential side effects and reduced modularity)
    or pass the sum as a parameter to the recursive function and return it at each step. */

    // int sum = 0; // this is the problem. we can't define this here.

    // base case
    if (i == 0)
    {
        return i;
    }

    // recursive case
    int sum = sumOfDivisors(n, i - 1); // sum gets updated with every return call.

    if (n % i == 0)
    {
        sum = sum + i;
    }

    return sum; //+ sumOfDivisors(n, i - 1);
}
