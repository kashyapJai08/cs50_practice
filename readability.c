#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// function prototypes
int calculate_letters(string text);
int calculate_words(string text);
int calculate_sentences(string text);

int main(void)
{
    // get input from the user
    string text = get_string("Text: ");

    // calculate no. of letters
    int letters = calculate_letters(text);

    // calculate no. of words
    int words = calculate_words(text);

    // calculate no. of sentences
    int sentences = calculate_sentences(text);

    // calculate the index and print out the grade level
    float L = (letters / (float) words) * 100.0;
    float S = (sentences / (float) words) * 100.0;

    float index = 0.0588 * L - 0.296 * S - 15.8; //Coleman-Liau index calculation

    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int calculate_letters(string text)
{
    int count = 0;
    char c;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int calculate_words(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count + 1;
}

int calculate_sentences(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
