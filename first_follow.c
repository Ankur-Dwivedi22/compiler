#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

char productions[10][10];
char first[10][SIZE];
char follow[10][SIZE];
int n;

int findIndex(char ch)
{
    for (int i = 0; i < n; i++)
        if (productions[i][0] == ch)
            return i;
    return -1;
}

void addToSet(char *set, char val)
{
    if (strchr(set, val) == NULL)
    {
        int len = strlen(set);
        set[len] = val;
        set[len + 1] = '\0';
    }
}

void computeFirst(int i)
{
    char ch;
    int k;
    for (int j = 2; j < strlen(productions[i]); j++)
    {
        ch = productions[i][j];

        if (!isupper(ch))
        {
            addToSet(first[i], ch);
            break;
        }
        else
        {
            k = findIndex(ch);
            computeFirst(k);
            for (int m = 0; first[k][m] != '\0'; m++)
            {
                if (first[k][m] != '#')
                    addToSet(first[i], first[k][m]);
            }
            if (!strchr(first[k], '#'))
                break;
        }

        if (j == strlen(productions[i]) - 1)
            addToSet(first[i], '#');
    }
}

void computeFollow(int i)
{
    char ch, next;
    int k;

    if (i == 0)
        addToSet(follow[i], '$');

    for (int j = 0; j < n; j++)
    {
        for (int m = 2; m < strlen(productions[j]); m++)
        {
            ch = productions[j][m];

            if (ch == productions[i][0])
            {
                if (m + 1 < strlen(productions[j]))
                {
                    next = productions[j][m + 1];

                    if (!isupper(next))
                    {
                        addToSet(follow[i], next);
                    }
                    else
                    {
                        k = findIndex(next);
                        for (int x = 0; first[k][x] != '\0'; x++)
                        {
                            if (first[k][x] != '#')
                                addToSet(follow[i], first[k][x]);
                        }

                        if (strchr(first[k], '#'))
                            computeFollow(j);
                    }
                }
                else
                {
                    if (i != j)
                        computeFollow(j);
                }
            }
        }
    }
}

int main()
{
    printf("Enter number of productions: ");
    scanf("%d", &n);
    getchar(); // clear newline

    printf("Enter productions (e.g. E=TR):\n");
    for (int i = 0; i < n; i++)
    {
        fgets(productions[i], 10, stdin);
        productions[i][strcspn(productions[i], "\n")] = '\0';
        first[i][0] = '\0';
        follow[i][0] = '\0';
    }

    for (int i = 0; i < n; i++)
    {
        computeFirst(i);
    }

    for (int i = 0; i < n; i++)
    {
        computeFollow(i);
    }

    printf("\nFIRST Sets:\n");
    for (int i = 0; i < n; i++)
        printf("FIRST(%c): { %s }\n", productions[i][0], first[i]);

    printf("\nFOLLOW Sets:\n");
    for (int i = 0; i < n; i++)
        printf("FOLLOW(%c): { %s }\n", productions[i][0], follow[i]);

    return 0;
}
