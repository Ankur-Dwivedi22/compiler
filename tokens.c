#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {
    "int", "float", "char", "return", "if", "else", "while", "for", "void", "main"};

int isKeyword(char *word)
{
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char line[256];
    char token[50];
    int i = 0, j = 0;

    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);

    printf("\nTokens Identified:\n");

    while (line[i] != '\0')
    {
        // Skip whitespace
        if (isspace(line[i]))
        {
            i++;
            continue;
        }

        // Identifier or keyword
        if (isalpha(line[i]) || line[i] == '_')
        {
            j = 0;
            while (isalnum(line[i]) || line[i] == '_')
            {
                token[j++] = line[i++];
            }
            token[j] = '\0';

            if (isKeyword(token))
                printf("Keyword     : %s\n", token);
            else
                printf("Identifier  : %s\n", token);
        }

        // Number
        else if (isdigit(line[i]))
        {
            j = 0;
            while (isdigit(line[i]))
            {
                token[j++] = line[i++];
            }
            token[j] = '\0';
            printf("Number      : %s\n", token);
        }

        // Operators and Symbols
        else
        {
            printf("Symbol      : %c\n", line[i]);
            i++;
        }
    }

    return 0;
}
