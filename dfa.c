#include <stdio.h>
#include <ctype.h>
#include <string.h>

// DFA to recognize Identifiers
int isIdentifierDFA(const char *str) {
    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        switch (state) {
            case 0:
                if (isalpha(str[i]) || str[i] == '_')
                    state = 1;
                else
                    return 0;
                break;
            case 1:
                if (isalnum(str[i]) || str[i] == '_')
                    state = 1;
                else
                    return 0;
                break;
        }
    }
    return (state == 1);
}

// DFA to recognize Constants (Integers only)
int isConstantDFA(const char *str) {
    int state = 0;
    int i = 0;

    if (str[i] == '-') i++;  // optional negative sign

    for (; str[i]; i++) {
        if (!isdigit(str[i]))
            return 0;
    }

    return (i > 0);
}

// DFA to recognize simple Operators
int isOperatorDFA(const char *str) {
    const char *ops[] = {"+", "-", "*", "/", "%", "==", "!=", "<", "<=", ">", ">=", "="};
    for (int i = 0; i < sizeof(ops)/sizeof(ops[0]); i++) {
        if (strcmp(str, ops[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[50];
    printf("Enter a string to test DFA: ");
    scanf("%s", input);

    if (isIdentifierDFA(input))
        printf("'%s' is an Identifier (via DFA).\n", input);
    else if (isConstantDFA(input))
        printf("'%s' is a Constant (via DFA).\n", input);
    else if (isOperatorDFA(input))
        printf("'%s' is an Operator (via DFA).\n", input);
    else
        printf("'%s' is not recognized by DFA.\n", input);

    return 0;
}
