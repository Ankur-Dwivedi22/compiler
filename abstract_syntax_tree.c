#include <stdio.h>
#include <string.h>

void generateCode(char *ast)
{
    printf("MOV R0, %c\n", ast[0]);     // Example for generating simple machine code
    printf("ADD R0, R0, %c\n", ast[2]); // Simple addition for a 3-node AST
}

int main()
{
    char ast[5] = {'5', '+', '3', '\0'};
    generateCode(ast);
    return 0;
}
