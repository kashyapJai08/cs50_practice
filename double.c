#include <stdio.h>

int main(void)
{
    int array[5];

    for (int i = 0; i < 5; i++)
    {
        if(i == 0)
        {
            array[i] = 1;
            continue;
        }

        array[i] = array[i - 1] * 2;
    }

    for (int j = 0; j < 5; j++)
    {
        printf("%i\n", array[j]);
    }
}
