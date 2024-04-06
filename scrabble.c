#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// array storing the points
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// function prototypes
int score_calculator(string word);
void print_winner(int score1, int score2);

int main(void)
{
    // get input from the users
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // calculate the respective scores
    int score1 = score_calculator(word1);
    int score2 = score_calculator(word2);

    // print the winner accordingly
    print_winner(score1, score2);
}

// calculates the scores of respective words
int score_calculator(string word)
{
    int sum = 0;

    for (int i = 0, l = strlen(word); i < l; i++)
    {
        if (isalpha(word[i]))
        {
            word[i] = toupper(word[i]);
            sum = sum + POINTS[word[i] - 'A'];
        }
    }
    return sum;
}

// prints the winner of the scrabble
void print_winner(int score1, int score2)
{
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
