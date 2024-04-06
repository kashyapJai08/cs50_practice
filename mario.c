#include <cs50.h>
#include <stdio.h>

void print_row(int h);

int main(void)
{
    // take input from the user
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0);

    print_row(n);

}

void print_row(int h)
{

    // for loop to create the height of the row
    for (int row = 0; row < h; row++)
    {
        // for loop create the width of the piramid
        for (int column = 0; column < h; column++)
        {
            // if row plus column is greater than or equal than height -1 space print the hashes
            if (row + column >= h - 1)
                printf("#");

            // adding spaces
            else
            printf(" ");
        }
        printf("\n");
    }
}

