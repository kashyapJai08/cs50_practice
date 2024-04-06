#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
bool only_digits(string text);
char rotate(char p, int key);

int main(int argc, string argv[])
{
    // asks for valid command line argument from the user
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // converts the string type key to integer for use
    int key = atoi(argv[1]);

    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

// checks whether the argument by user is digit or not
bool only_digits(string text)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (!(isdigit(text[i])))
        {
            return false;
        }
    }
    return true;
}

// rotates each character of the plaintext by key number
char rotate(char p, int key)
{
    char c;
    if (isupper(p))
    {
        c = (((p - 'A') + key) % 26) + 'A';
    }
    else if (islower(p))
    {
        c = (((p - 'a') + key) % 26) + 'a';
    }
    else
    {
        c = p;
    }

    return c;
}
