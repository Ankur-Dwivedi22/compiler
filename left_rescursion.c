#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char nonTerminal, char productions[][10], int *prodCount)
{
    char newNonTerminal = nonTerminal + 'A' - 'Z';
    printf("\nLeft Recursion Elimination for %c:\n", nonTerminal);
    printf("%c -> ", nonTerminal);
    for (int i = 0; i < *prodCount; i++)
    {
        if (productions[i][0] == nonTerminal)
        {
            printf("%s%c | ", productions[i] + 1, newNonTerminal);
        }
        else
        {
            printf("%s%c | ", productions[i], newNonTerminal);
        }
    }
    printf("\n%c -> ε | ", newNonTerminal);
    for (int i = 0; i < *prodCount; i++)
    {
        if (productions[i][0] == nonTerminal)
            printf("%s%c | ", productions[i] + 1, newNonTerminal);
    }
    printf("\n");
}

void eliminateLeftFactoring(char nonTerminal, char productions[][10], int *prodCount)
{
    int maxPrefixLen = 0;
    for (int i = 1; i < *prodCount; i++)
    {
        int j = 0;
        while (productions[i][j] == productions[0][j] && productions[i][j] != '\0')
            j++;
        if (j > maxPrefixLen)
            maxPrefixLen = j;
    }

    if (maxPrefixLen > 0)
    {
        char newNonTerminal = nonTerminal + 'A' - 'Z';
        printf("\nLeft Factoring for %c:\n", nonTerminal);
        printf("%c -> ", nonTerminal);
        for (int i = 0; i < *prodCount; i++)
        {
            printf("%s%c | ", productions[i], newNonTerminal);
        }
        printf("\n%c -> ", newNonTerminal);
        for (int i = 0; i < *prodCount; i++)
        {
            if (strlen(productions[i]) > maxPrefixLen)
                printf("%s | ", productions[i] + maxPrefixLen);
        }
        printf("\n");
    }
}

int main()
{
    char nonTerminal;
    int prodCount;
    char productions[10][10];

    // Input the grammar
    printf("Enter the Non-terminal: ");
    scanf(" %c", &nonTerminal);
    printf("Enter the number of productions: ");
    scanf("%d", &prodCount);
    for (int i = 0; i < prodCount; i++)
    {
        printf("Enter production %d: ", i + 1);
        scanf("%s", productions[i]);
    }

    eliminateLeftRecursion(nonTerminal, productions, &prodCount);
    eliminateLeftFactoring(nonTerminal, productions, &prodCount);

    return 0;
}
