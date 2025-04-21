#include <stdio.h>
#include <string.h>

int match(char *str)
{
    if (strcmp(str, "a") == 0)
        return 1;
    if (str[0] == 'a' && str[1] == 'b' && str[2] == '+' && str[3] == '\0')
        return 1;
    if (strcmp(str, "abb") == 0)
        return 1;
    return 0;
}

int main()
{
    char str[100];
    printf("Enter string: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0'; // Remove newline character
    if (match(str))
    {
        printf("Valid string.\n");
    }
    else
    {
        printf("Invalid string.\n");
    }
    return 0;
}
