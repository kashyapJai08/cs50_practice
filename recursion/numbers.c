#include <cs50.h>
#include <stdio.h>

// int print_numbers(int n);
void print_numbers(int n);

int main(void)
{
    int n = get_int("number: ");
    print_numbers(n);
    printf("\n");
}

// int print_numbers(int n)
// {
//     // base case
//     if (n == 1)
//     {
//         return 1;
//     }
//     // recursive case
//     printf ("%i ", print_numbers(n - 1));

//     return n + 1;
// }

void print_numbers(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }
    // recursive case
    printf ("%i ", n); // starts from 9 goes to 1, straight function calls are going on. (UNROLLING)
    print_numbers(n - 1);
    printf ("%i ", n); // recursive calls are being returned back after hitting the base case.(ROLLING)
}
