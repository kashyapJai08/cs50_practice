#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sumNatural(int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./sum_natural number\n");
    }
    int n = atoi(argv[1]);

    printf("SUM: %i\n", sumNatural(n));
}

int sumNatural(int n)
{
    if(n == 1)
    {
        return 1;
    }

    return n + sumNatural(n - 1);
}
