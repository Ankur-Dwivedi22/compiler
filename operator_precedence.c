#include <stdio.h>
#include <ctype.h>

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void parse(char *exp)
{
    char stack[100];
    int top = -1;
    int i = 0;
    while (exp[i] != '\0')
    {
        if (isalnum(exp[i]))
        {
            printf("%c ", exp[i]);
        }
        else if (exp[i] == '(')
        {
            stack[++top] = '(';
        }
        else if (exp[i] == ')')
        {
            while (stack[top] != '(')
            {
                printf("%c ", stack[top--]);
            }
            top--; // Pop '('
        }
        else
        {
            while (top >= 0 && precedence(stack[top]) >= precedence(exp[i]))
            {
                printf("%c ", stack[top--]);
            }
            stack[++top] = exp[i];
        }
        i++;
    }
    while (top >= 0)
    {
        printf("%c ", stack[top--]);
    }
    printf("\n");
}

int main()
{
    char exp[100];
    printf("Enter expression: ");
    fgets(exp, 100, stdin);
    parse(exp);
    return 0;
}
