#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *kw[] = {"int", "float", "char", "if", "else"};
char ops[] = {'+', '-', '*', '/', '=', ';'};

int isId(char *s)
{
    if (!isalpha(s[0]) && s[0] != '_')
        return 0;
    for (int i = 1; i < strlen(s); i++)
        if (!isalnum(s[i]) && s[i] != '_')
            return 0;
    return 1;
}

int isKw(char *s)
{
    for (int i = 0; i < 5; i++)
        if (strcmp(s, kw[i]) == 0)
            return 1;
    return 0;
}

int isOp(char c)
{
    for (int i = 0; i < 6; i++)
        if (c == ops[i])
            return 1;
    return 0;
}

void lexAnalyze(char *s)
{
    int i = 0, len = strlen(s);
    while (i < len)
    {
        if (isspace(s[i]))
        {
            i++;
            continue;
        }
        if (isalpha(s[i]) || s[i] == '_')
        {
            char buf[20];
            int j = 0;
            while (isalnum(s[i]) || s[i] == '_')
                buf[j++] = s[i++];
            buf[j] = '\0';
            if (isKw(buf))
                printf("%s is a Keyword\n", buf);
            else if (isId(buf))
                printf("%s is an Identifier\n", buf);
        }
        else if (isOp(s[i]))
        {
            printf("%c is an Operator\n", s[i]);
            i++;
        }
        else
        {
            printf("%c is Invalid\n", s[i]);
            i++;
        }
    }
}

int main()
{
    char str[100];
    printf("Enter string: ");
    fgets(str, 100, stdin);
    lexAnalyze(str);
    return 0;
}
