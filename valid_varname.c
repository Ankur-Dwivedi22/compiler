#include <stdio.h>
#include <ctype.h>

// Function to check if a string is a valid variable name
int isValidVariable(char str[])
{
    // First character must be a letter or underscore
    if (!(isalpha(str[0]) || str[0] == '_'))
        return 0;

    // Remaining characters must be letters, digits, or underscores
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (!(isalnum(str[i]) || str[i] == '_'))
            return 0;
    }

    return 1;
}

int main()
{
    char var[100];

    printf("Enter a variable name: ");
    scanf("%s", var);

    if (isValidVariable(var))
        printf("'%s' is a valid variable name.\n", var);
    else
        printf("'%s' is NOT a valid variable name.\n", var);

    return 0;
}
