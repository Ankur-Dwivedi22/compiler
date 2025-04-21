#include <stdio.h>
#include <ctype.h>

void lexicalAnalyzer(char *input)
{
    int i = 0;
    while (input[i] != '\0')
    {
        if (isspace(input[i]) || input[i] == '\n' || input[i] == '\t')
        {
            i++;
            continue;
        }
        if (input[i] == '/' && input[i + 1] == '/')
        {
            while (input[i] != '\n')
                i++; // Skip single-line comment
            continue;
        }
        if (input[i] == '/' && input[i + 1] == '*')
        {
            i += 2;
            while (!(input[i] == '*' && input[i + 1] == '/'))
                i++;
            i += 2; // Skip multi-line comment
            continue;
        }
        printf("Token: %c\n", input[i]);
        i++;
    }
}

int main()
{
    char input[100];
    printf("Enter code: ");
    fgets(input, 100, stdin);
    lexicalAnalyzer(input);
    return 0;
}
