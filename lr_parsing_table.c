#include <stdio.h>
#include <string.h>

#define NUM_STATES 5
#define NUM_SYMBOLS 6
#define NUM_RULES 5

char *grammar[] = {
    "E -> TE'",
    "E' -> +TE' | 0",
    "T -> FT'",
    "T' -> *FT' | 0",
    "F -> (E) | id"};

int parseTable[NUM_STATES][NUM_SYMBOLS] = {
    {1, 2, -1, -1, 3, 0},     // State 0
    {-1, -1, 4, -1, -1, 5},   // State 1
    {1, 2, -1, -1, 3, 0},     // State 2
    {1, 2, -1, -1, 3, 0},     // State 3
    {-1, -1, -1, -1, -1, -1}, // State 4 (accept state)
};

void printParseTable()
{
    printf("LR Parsing Table:\n");
    printf("State   +   *   id  (   )   $  \n");
    for (int i = 0; i < NUM_STATES; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < NUM_SYMBOLS; j++)
        {
            printf("%d   ", parseTable[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printParseTable();
    return 0;
}
