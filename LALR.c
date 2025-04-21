#include <stdio.h>
#include <string.h>

#define MAX 100
#define NUM_STATES 5
#define NUM_SYMBOLS 6
#define NUM_RULES 5

char stack[MAX];
int top = -1;
char input[MAX];
int i = 0;

int parseTable[NUM_STATES][NUM_SYMBOLS] = {
    {1, 2, -1, -1, 3, 0},     // State 0
    {-1, -1, 4, -1, -1, 5},   // State 1
    {1, 2, -1, -1, 3, 0},     // State 2
    {1, 2, -1, -1, 3, 0},     // State 3
    {-1, -1, -1, -1, -1, -1}, // State 4 (accept state)
};

void push(char c)
{
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop()
{
    if (top >= 0)
        return stack[top--];
    return '\0';
}

int action(int state, char symbol)
{
    if (symbol == 'i')
        return parseTable[state][0]; // 'id'
    if (symbol == '+')
        return parseTable[state][1]; // '+'
    if (symbol == '*')
        return parseTable[state][2]; // '*'
    if (symbol == '(')
        return parseTable[state][3]; // '('
    if (symbol == ')')
        return parseTable[state][4]; // ')'
    return parseTable[state][5];     // '$' (end of input)
}

void lrParse(char *input)
{
    push('$');
    push('0');
    while (1)
    {
        char symbol = input[i];
        int state = stack[top] - '0';
        int act = action(state, symbol);
        if (act == -1)
        {
            printf("Error: Invalid symbol.\n");
            break;
        }
        else if (act == 4)
        {
            printf("Input accepted.\n");
            break;
        }
        else if (act == 5)
        {
            printf("Shift: %c\n", symbol);
            push(symbol);
            push('0' + act);
            i++;
        }
        else
        {
            printf("Reduce by rule: %d\n", act);
            if (act == 1)
            {
                pop();
                pop();
                pop();
                pop();
                push('E');
            }
        }
    }
}

int main()
{
    printf("Enter input string: ");
    fgets(input, MAX, stdin);
    input[strlen(input) - 1] = '\0'; // Remove newline
    lrParse(input);
    return 0;
}
