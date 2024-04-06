#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

bool valid_triangle(int x, int y, int z);

int main()
{
    int a = get_int("Enter the side1: \n");
    int b = get_int("Enter the side2: \n");
    int c = get_int("Enter the side3: \n");

    if (valid_triangle(a, b, c))
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }
}

bool valid_triangle(int x, int y, int z)
{
    if ((x + y > z) && (x + z > y) && (y + z > x))
    {
        return true;
    }
    else
    {
        return false;
    }
}
