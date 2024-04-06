#include <cs50.h>
#include <stdio.h>

// function prototypes
long enter_number(void);
int digit_counter(long n);
int check_sum(long cc, int digits);
void digit_checker(long cc, int digits);

// global variables
int firstDigit, firstTwoDigits, checkSum;

int main(void)
{
    // prompt user for credit card number
    long creditCardNumber = enter_number();

    // calculates no. of digits
    int digits = digit_counter(creditCardNumber);

    // calculates the first and first two digits of the number
    digit_checker(creditCardNumber, digits);

    if (digits == 13 && firstDigit == 4)
    {
        checkSum = check_sum(creditCardNumber, digits);

        if (checkSum % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if ((digits == 15) && (firstTwoDigits == 34 || firstTwoDigits == 37))
    {
        checkSum = check_sum(creditCardNumber, digits);

        if (checkSum % 10 == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digits == 16)
    {
        checkSum = check_sum(creditCardNumber, digits);

        if (checkSum % 10 == 0)
        {
            if (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 ||
                firstTwoDigits == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (firstDigit == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long enter_number(void)
{
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);

    return n;
}

int digit_counter(long n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt++;
        n = n / 10;
    }

    return cnt;
}

int check_sum(long cc, int digits)
{
    int d, sum = 0;

    for (int i = 0; i < digits; i++)
    {
        d = cc % 10;
        cc = cc / 10;
        if (i % 2 != 0)
        {
            d = d * 2;
            if (d >= 10)
            {
                while (d > 0)
                {
                    sum = sum + (d % 10);
                    d = d / 10;
                }
            }
            else
            {
                sum = sum + d;
            }
        }
        else
        {
            sum = sum + d;
        }
    }

    return sum;
}

void digit_checker(long cc, int digits)
{
    for (int i = 0; i < digits; i++)
    {
        if (i == digits - 1)
        {
            firstDigit = cc % 10;
        }
        if (i == digits - 2)
        {
            firstTwoDigits = cc % 100;
        }
        cc = cc / 10;
    }
}
