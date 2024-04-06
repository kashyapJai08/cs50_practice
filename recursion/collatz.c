#include <cs50.h>
#include <stdio.h>

int collatz(int n);
int steps = 0;

int main(void)
{
    int number[] = {1, 2, 3, 4, 5, 6, 7, 8, 15, 27, 50};
    int steps_mat[11];

    for(int i = 0;  i < 11; i++)
    {
        steps = collatz(number[i]);
        printf("%i : %i\n", number[i], steps);
    }
}

int collatz(int n)
{

    if (n == 1)
    {
        return 0;
    }
    else if ((n % 2) == 0)
    {
        steps++;
        return 1 + collatz(n / 2);

    }
    else if ((n % 2) != 0)
    {
        steps++;
        return 1 + collatz(3 * n + 1);
    }

    return steps;
}
