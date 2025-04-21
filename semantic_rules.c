#include <stdio.h>
#include <ctype.h>

int eval(char *exp)
{
    int result = 0;
    int num = 0, i = 0;
    char op = '+';
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            num = num * 10 + (exp[i] - '0');
        }
        if (!isdigit(exp[i]) || exp[i + 1] == '\0')
        {
            if (op == '+')
                result += num;
            if (op == '-')
                result -= num;
            if (op == '*')
                result *= num;
            num = 0;
            op = exp[i];
        }
        i++;
    }
    return result;
}

int main()
{
    char exp[100];
    printf("Enter expression: ");
    fgets(exp, 100, stdin);
    printf("Result: %d\n", eval(exp));
    return 0;
}
