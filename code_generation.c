#include <stdio.h>
#include <ctype.h>

int tempCount = 0;

void generateCode(char *exp)
{
    char temp[10], op;
    int i = 0, t1, t2;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            printf("t%d = %c\n", ++tempCount, exp[i]);
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            op = exp[i];
            t1 = tempCount - 1;
            t2 = tempCount;
            printf("t%d = t%d %c t%d\n", ++tempCount, t1, op, t2);
        }
        i++;
    }
}

int main()
{
    char exp[100];
    printf("Enter expression: ");
    fgets(exp, 100, stdin);
    generateCode(exp);
    return 0;
}
