#include <stdio.h>
#include <string.h>

int isComment(char *line)
{
    if (line[0] == '/' && line[1] == '/')
        return 1;
    if (line[0] == '/' && line[1] == '*' && line[strlen(line) - 2] == '*' && line[strlen(line) - 1] == '/')
        return 1;
    return 0;
}

int main()
{
    char line[100];
    printf("Enter line: ");
    fgets(line, 100, stdin);
    if (isComment(line))
    {
        printf("This is a comment.\n");
    }
    else
    {
        printf("This is not a comment.\n");
    }
    return 0;
}
