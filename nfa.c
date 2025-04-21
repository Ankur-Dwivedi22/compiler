#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a valid identifier
int isIdentifier(char *str)
{
    if (!isalpha(str[0]) && str[0] != '_')
        return 0;
    for (int i = 1; str[i]; i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
            return 0;
    }
    return 1;
}

// Function to check if a string is a constant (integer only)
int isConstant(char *str)
{
    int i = 0;
    if (str[0] == '-')
        i++;
    for (; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return i > 0;
}

// Function to check if a string is a valid operator
int isOperator(char *str)
{
    const char *operators[] = {"+", "-", "*", "/", "%", "==", "!=", "<", "<=", ">", ">=", "="};
    for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++)
    {
        if (strcmp(str, operators[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char input[50];
    printf("Enter a string to classify: ");
    scanf("%s", input);

    if (isIdentifier(input))
        printf("'%s' is an Identifier.\n", input);
    else if (isConstant(input))
        printf("'%s' is a Constant.\n", input);
    else if (isOperator(input))
        printf("'%s' is an Operator.\n", input);
    else
        printf("'%s' is not recognized by the NFA.\n", input);

    return 0;
}
