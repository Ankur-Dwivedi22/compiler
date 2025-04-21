#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int i = 0;

// Function to check the grammar for S -> aA, A -> +aA | ε
void S()
{
    if (input[i] == 'a')
    {
        printf("S -> aA\n");
        i++;
        A();
    }
    else
    {
        printf("Error: Expected 'a' at the beginning.\n");
    }
}

void A()
{
    if (input[i] == '+')
    {
        printf("A -> +aA\n");
        i++;
        if (input[i] == 'a')
        {
            i++;
            A();
        }
    }
    else
    {
        printf("A -> ε\n");
    }
}

// Function to start parsing
void parse()
{
    S();
    if (input[i] == '\0')
    {
        printf("Input string is valid.\n");
    }
    else
    {
        printf("Error: Extra characters found.\n");
    }
}

int main()
{
    printf("Enter input string: ");
    scanf("%s", input);

    // Start parsing from S
    parse();

    return 0;
}
