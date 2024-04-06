#include <cs50.h>
#include <stdio.h>

void print_pattern(int h, int r);

int main(void)
{
    int height = get_int("Height: ");

    print_pattern(height, height);
}

void print_pattern(int h, int r)
{
    if (r == 0)
    {
        return;
    }

    print_pattern(h, r - 1);

    for (int j = 0; j < h - r; j++)
    {
        printf(" ");
    }
    for (int i = 0; i < r; i++)
    {
        printf("*");
    }
    printf("\n");
}
