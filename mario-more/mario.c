#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        //left aligned pyramid
        for (int jl = 0; jl < n; jl++)
        {
            if (i + jl >= n -1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("  ");

        //rigth aligned pyramid
        for (int jr = 0; jr < i + 1; jr++)
        {
            printf("#");
        }
        printf("\n");
    }
}
