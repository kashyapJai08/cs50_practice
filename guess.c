#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = 5;
    int guess = get_int("guess?: ");

    while (guess!=number)
    {
        printf("wrong guess");
    }

    printf ("correct\n");
}
