#include <cs50.h>
#include <stdio.h>

int change_owed();
int quarters_n(int cents);
int dimes_n(int cents);
int nickels_n(int cents);
int pennies_n(int cents);

int main(void)
{
   int cents = change_owed();

   int quarters = quarters_n(cents);
   cents = cents - quarters * 25;

    int dimes = dimes_n(cents);
   cents = cents - dimes * 10;

      int nickels = nickels_n(cents);
   cents = cents - nickels * 5;

      int pennies = pennies_n(cents);
   cents = cents - pennies * 1;

    int coins = quarters + dimes + nickels + pennies;

    printf ("%i\n", coins);

}
int change_owed(void)
{
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n <= 0);

    return n;
}

int quarters_n(int cents)
{
    int q = cents / 25;
    return q;
}

int dimes_n(int cents)
{
    int d = cents / 10;
    return d;
}

int nickels_n(int cents)
{
    int n = cents / 5;
    return n;
}

int pennies_n(int cents)
{
    int p = cents / 1;
    return p;
}

