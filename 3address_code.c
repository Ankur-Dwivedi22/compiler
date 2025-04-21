#include <stdio.h>
#include <string.h>

// Simple function to generate temporary variable names
char tempVar()
{
    static char t = 'A';
    return t++;
}

void generateTAC(char expr[])
{
    int len = strlen(expr);
    char result[100][20];
    int k = 0;
    int i;

    // Assuming input is in form: a = b + c * d (no parentheses or spacing)
    char left = expr[0];
    char op1 = expr[4];
    char op = expr[5];
    char op2 = expr[6];

    char t1 = tempVar();
    printf("%c = %c %c %c\n", t1, op1, op, op2); // t1 = c * d

    char t2 = tempVar();
    printf("%c = %c + %c\n", t2, expr[2], t1); // t2 = b + t1

    printf("%c = %c\n", left, t2); // a = t2
}

int main()
{
    char expression[20];

    printf("Enter an expression (e.g., a=b+c*d): ");
    scanf("%s", expression);

    generateTAC(expression);

    return 0;
}
