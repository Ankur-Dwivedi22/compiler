#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int i = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();
void match(char c)
{
    if (input[i] == c)
        i++;
    else
    {
        printf("Syntax error!\n");
        exit(1);
    }
}

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if (input[i] == '+')
    {
        match('+');
        T();
        Eprime();
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if (input[i] == '*')
    {
        match('*');
        F();
        Tprime();
    }
}

void F()
{
    if (input[i] == '(')
    {
        match('(');
        E();
        match(')');
    }
    else if (isalnum(input[i]))
    {
        i++;
    }
    else
    {
        printf("Syntax error!\n");
        exit(1);
    }
}

int main()
{
    printf("Enter expression: ");
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0'; // Remove newline
    E();
    if (input[i] == '\0')
    {
        printf("Valid expression.\n");
    }
    else
    {
        printf("Invalid expression.\n");
    }
    return 0;
}
