
/* PROGRAM TO COUNT THE NO. OF EVEN AND ODD DIGITS IN A POSTIVE INTEGER*/

#include <cs50.h>
#include <stdio.h>

void digitType(int num); // Funtion prototype

int even = 0, odd = 0;

int main(void)
{
    // getting input from the user and checking it's validity
    int number = get_int("Enter a positive integer: ");
    if (number <= 0)
    {
        printf("Invalid Number.\nProgram works for positive integers only.\n");
        return 1;
    }

    digitType(number); // function call to count the no. of even and odd digits.
    printf("Even digits: %i\nOdd digits: %i\n", even, odd);
}

void digitType(int num)
{
    // base case
    if (num == 0)
    {
        return;
    }

    // recursive case
    digitType(num / 10);

    if (num % 2 == 0)
    {
        even++;
    }
    else
    {
        odd++;
    }
}

/* ALTERNATE WAY USING STRUCTS */

// #include <cs50.h>
// #include <stdio.h>

// // Structure to hold counts of even and odd digits
// typedef struct {
//     int even;
//     int odd;
// } DigitCounts;

// // Function prototype
// DigitCounts digitType(int number);

// int main(void)
// {
//     // Get input from the user and validate it
//     int number = get_int("Enter a positive integer: ");
//     while (number <= 0)
//     {
//         printf("Invalid input: Please enter a positive integer.\n");
//         number = get_int("Enter a positive integer: ");
//     }

//     // Call the function to count even and odd digits
//     DigitCounts counts = digitType(number);

//     // Output the counts
//     printf("Even digits: %i\nOdd digits: %i\n", counts.even, counts.odd);

//     return 0;
// }

// // Recursive function to count even and odd digits
// DigitCounts digitType(int number)
// {
//     DigitCounts counts;

//     // Base case: If the number becomes 0, return counts with both even and odd set to 0
//     if (number == 0)
//     {
//         counts.even = 0;
//         counts.odd = 0;
//         return counts;
//     }

//     // Recursive case: Process the current digit and call the function recursively
//     counts = digitType(number / 10);

//     // Determine if the current digit is even or odd and update the counts
//     if (number % 2 == 0)
//     {
//         counts.even++;
//     }
//     else
//     {
//         counts.odd++;
//     }

//     return counts;
// }

