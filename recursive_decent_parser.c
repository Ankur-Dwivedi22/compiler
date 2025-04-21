#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

// Match a given terminal symbol
void match(char expected)
{
    if (input[i] == expected)
        i++;
    else
    {
        printf("Error: Expected '%c'\n", expected);
        exit(1);
    }
}

void E();
void EPrime();
void T();
void TPrime();
void F();

void E()
{
    T();
    EPrime();
}

void EPrime()
{
    if (input[i] == '+')
    {
        i++;
        T();
        EPrime();
    }
    // else ε
}

void T()
{
    F();
    TPrime();
}

void TPrime()
{
    if (input[i] == '*')
    {
        i++;
        F();
        TPrime();
    }
    // else ε
}

void F()
{
    if (input[i] == '(')
    {
        match('(');
        E();
        match(')');
    }
    else if (input[i] == 'i')
    { // i stands for id
        match('i');
    }
    else
    {
        printf("Error: Invalid symbol '%c'\n", input[i]);
        exit(1);
    }
}

int main()
{
    printf("Enter the input string (e.g. i+i*i): ");
    scanf("%s", input);

    E();

    if (input[i] == '\0')
        printf("String is ACCEPTED.\n");
    else
        printf("String is REJECTED. Remaining: %s\n", &input[i]);

    return 0;
}
