
/********** IMPLEMENTATITON OF TRIBONACCI SEQUENCE ***************/
#include <cs50.h>
#include <stdio.h>

int tribonacci(int num); // Function prototype

int main(void)
{
    // gets input from the user and checks for the valid input
    int number, i = 0;
    do
    {
        number = get_int("Number: ");
        if (number < 0)
        {
            printf("Enter number > 0\n");
        }

        i++;
        if (i == 5)
        {
            // If user keeps on givin invalid input exits the program
            printf("Too many incorrect attempts.\nExiting the program.\n");
            return -1;
        }
    }
    while (number < 0);

    printf("%ith number of tribonacci sequence is: %i\n", number, tribonacci(number)); // prints the required number
}

// implementation of tribonacci function
int tribonacci(int num)
{
    // we need conditional in base case. num goes to zero
    // we need to return 0 for that special case, otherwise we return 1 only.
    if (num < 3 && num > 0)
    {
        return 1;
    }
    else if (num <= 0)
    {
        return 0;
    }

    // recursive case: any number in tribonacci sequence  is sum of previous three numbers.
    return tribonacci(num - 1) + tribonacci(num - 2) + tribonacci(num - 3);
}
