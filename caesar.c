#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//declare bool
bool check_valid_key(string s);

int main(int arg, string argv[])
{
    if (arg != 2 || !check_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //convert "13" => 13
    int key = atoi(argv[1]);

    //get the input string value
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            char modi = 'A';
            //convert A => a
            if (islower(c))
            {
                modi = 'a';
            }
            //Applying Caesar’s algorithm
            printf("%c", (c - modi + key) % 26 + modi);

        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");

}

//verify valid key
bool check_valid_key(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }

    return true;

}