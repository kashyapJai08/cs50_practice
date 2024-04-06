#include <cs50.h>
#include <stdio.h>

int gcd(int a, int n);
int eulerTotient(int n, int a);

int main(void)
{
    int n = get_int("number: ");
    printf("Euler totient of n: %i\n", eulerTotient(n, 1));
}

int eulerTotient(int n, int a)
{
    int count = 0;
    while(a <= n)
    {
        if (gcd(a, n) == 1)
        {
            count++;
        }
        a++;
    }
    return count;
}

// Recursive implementation of euler totient function..

// int eulerTotient(int n, int a)
// {
//     if (a == n)
//     {
//         return gcd(a, n) == 1 ? 1 : 0;
//     }

//     return gcd(a, n) == 1 ? 1 + eulerTotient(n, a + 1) : eulerTotient(n, a + 1);
// }

int gcd(int a, int n)
{
    if(n == 0)
    {
        return a;
    }

    return gcd(n, a % n);
}
