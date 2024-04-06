#include <cs50.h>
#include <stdio.h>

long input_isbn(void);
int check_sum(long isbn);

int main(void)
{
    // get input from the user
    long isbn = input_isbn();

    // calculate the checksum on the number
    int checksum = check_sum(isbn);

    // check for validity of the number by using the condition
    if (checksum % 11 == 0)
    {
        printf("VALID ISBN\n");
    }
    else
    {
        printf("INVALID ISBN\n");
    }

}

long input_isbn(void)
{
    long isbn;
    int cnt;
    do
    {
        isbn = get_long("ISBN - 10 number: ");
        int i = isbn;
        cnt = 0;
        while (i != 0)
        {
            i = i / 10;
            cnt++;
        }
    }
    while (isbn < 0 || isbn > 9999999999);

    return isbn;
}

int check_sum(long isbn)
{
    int digit, sum = 0;

    for (int i = 1; i < 11; i++)
    {
        digit = isbn % 10;
        sum = sum + digit * i;
        isbn = isbn / 10;
    }

    return sum;
}
