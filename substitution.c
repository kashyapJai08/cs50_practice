#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
bool keyAlphaCheck(string key);
char substitute(char plain, string key);

const int KEYLENGTH = 26; // The key must contain 26 characters only.

int main(int argc, string argv[])
{
    // Checks for valid input
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != KEYLENGTH || keyAlphaCheck(argv[1]))
    {
        printf("Key must contain 26 distinct alphabetic characters\n");
        return 1;
    }

    // Get input from the user
    string plaintext = get_string("plaintext: ");

    // Print the ciphertext by making call to rotate function
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", substitute(plaintext[i], argv[1]));
    }
    printf("\n");

    return 0;
}

// Checks whether the key contains 26 distinct alphabetical chars or not
bool keyAlphaCheck(string key)
{
    for (int i = 0; i < KEYLENGTH; i++)
    {
        if (!isalpha(key[i]))
        {
            return true;
        }
        else
        {
            for (int j = i + 1; j < KEYLENGTH; j++)
            {
                if (key[i] == key[j])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// This function takes in the characters of plaintext one by one
// and roatates them or substitutes them according to the key
// and returns the ciphered character
char substitute(char plain, string key)
{
    char cipher;
    if (isupper(plain))
    {
        cipher = toupper(key[plain - 'A']);
    }
    else if (islower(plain))
    {
        cipher = tolower(key[plain - 'a']);
    }
    else
    {
        cipher = plain;
    }
    return cipher;
}
