#include <cs50.h>
#include <stdio.h>
#include <string.h>

int stringLength(string s);

int main(void)
{
    string s = get_string("");
    printf("length of string is %i\n", stringLength(s));
    printf("length of string is %lu\n", strlen(s));
}

int stringLength(string s)
{
    int length = 0;

    while( s[length] != '\0')
    {
        length++;
    }

    return length;
}

