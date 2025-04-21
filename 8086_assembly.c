#include <stdio.h>
#include <string.h>

// Function to convert a TAC statement to 8086-style assembly
void generateAssembly(char tac[][20], int n) {
    printf("\nGenerated 8086 Assembly Code:\n");
    for (int i = 0; i < n; i++) {
        char op1, op2, result, operator;

        // Handle expressions like: t1 = a + b
        if (sscanf(tac[i], "%c = %c %c %c", &result, &op1, &operator, &op2) == 4) {
            printf("MOV AL, %c\n", op1);
            switch (operator) {
                case '+': printf("ADD AL, %c\n", op2); break;
                case '-': printf("SUB AL, %c\n", op2); break;
                case '*': printf("MUL %c\n", op2); break;
                case '/': printf("DIV %c\n", op2); break;
            }
            printf("MOV %c, AL\n\n", result);
        }

        // Handle assignments like: a = t1
        else if (sscanf(tac[i], "%c = %c", &result, &op1) == 2) {
            printf("MOV %c, %c\n\n", result, op1);
        }
    }
}

int main() {
    int n;
    char tac[10][20];

    printf("Enter number of TAC statements: ");
    scanf("%d", &n);
    getchar(); // consume newline

    printf("Enter TAC statements (e.g., t1 = a + b):\n");
    for (int i = 0; i < n; i++) {
        fgets(tac[i], sizeof(tac[i]), stdin);
        tac[i][strcspn(tac[i], "\n")] = 0; // remove newline
    }

    generateAssembly(tac, n);

    return 0;
}
