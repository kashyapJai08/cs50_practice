#include <cs50.h>
#include <stdio.h>

// function prototype
int digitCounter(int n);

int main(void)
{
    int number = get_int("Number: "); // input from the user

    // function call to count the digits by passing the input number
    printf("Digits: %i\n", digitCounter(number));
}

// digit counter function
int digitCounter(int n)
{
    // base case
    if (n < 10)
    {
        return 1;
    }

    // recursive case,
    // reduces the number to single digit then returns 1
    // and then adding 1 more for each call back.
    return digitCounter(n / 10) + 1;
}
