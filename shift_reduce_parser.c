#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) stack[++top] = c;
}

char pop() {
    if (top >= 0) return stack[top--];
    return '\0';
}

int checkEPlusT() {
    if (top >= 3 && stack[top] == 'T' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
        top -= 2;
        push('E');
        return 1;
    }
    return 0;
}

int checkE() {
    if (top >= 1 && stack[top] == 'T') {
        top--;
        push('E');
        return 1;
    }
    return 0;
}

int checkTStarF() {
    if (top >= 3 && stack[top] == 'F' && stack[top - 1] == '*' && stack[top - 2] == 'T') {
        top -= 2;
        push('T');
        return 1;
    }
    return 0;
}

int checkT() {
    if (top >= 1 && stack[top] == 'F') {
        top--;
        push('T');
        return 1;
    }
    return 0;
}

int checkF() {
    if (top >= 0 && stack[top] == 'i') {
        top--;
        push('F');
        return 1;
    }
    return 0;
}

void printStack() {
    for (int i = 0; i <= top; i++) printf("%c", stack[i]);
    printf("\n");
}

void parse(char *input) {
    int i = 0;
    while (input[i] != '\0') {
        push(input[i]);
        i++;
        while (checkEPlusT() || checkE() || checkTStarF() || checkT() || checkF());
        if (top == 0 && stack[0] == 'S') {
            printf("Valid input.\n");
            return;
        }
    }
    printf("Invalid input.\n");
}

int main() {
    char input[MAX];
    printf("Enter input: ");
    fgets(input, MAX, stdin);
    input[strlen(input) - 1] = '\0';
    parse(input);
    return 0;
}
