#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This simple simulation optimizes a hardcoded expression
// Example input: a = 2 + 3 * 4;
// Optimized: a = 2 + 12; => a = 14;

void constantFolding(char expr[])
{
    int num1, num2, result;
    char var, op1, op2, temp[100];

    // Simulated parsing: only supports form a = b op1 c op2 d;
    // Example: a = 2 + 3 * 4;

    sscanf(expr, "%c = %d %c %d %c %d", &var, &num1, &op1, &num2, &op2, &result);

    int intermediate = 0;

    // First apply second operator
    switch (op2)
    {
    case '+':
        intermediate = num2 + result;
        break;
    case '-':
        intermediate = num2 - result;
        break;
    case '*':
        intermediate = num2 * result;
        break;
    case '/':
        intermediate = num2 / result;
        break;
    }

    // Then apply first operator
    int finalResult = 0;
    switch (op1)
    {
    case '+':
        finalResult = num1 + intermediate;
        break;
    case '-':
        finalResult = num1 - intermediate;
        break;
    case '*':
        finalResult = num1 * intermediate;
        break;
    case '/':
        finalResult = num1 / intermediate;
        break;
    }

    printf("Optimized Code: %c = %d\n", var, finalResult);
}

int main()
{
    char expr[100];

    printf("Enter expression (e.g. a = 2 + 3 * 4): ");
    fgets(expr, sizeof(expr), stdin); // get whole line

    constantFolding(expr);

    return 0;
}
