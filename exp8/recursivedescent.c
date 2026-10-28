#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char str[50];
int i=0;

int T()
{
    if(isalnum(str[i]))
    {
        printf("T -> id\n");
        i++;
    }
    else
    {
        printf("Syntax Error in T\n");
        exit(0);
    }
}

int EPrime()
{
    if(str[i]=='+')
    {
        printf("E' -> + T E'\n");
        i++;
        T();
        EPrime();
    }
    else
    {
        printf("E' -> e\n");
    }
}

int E()
{
    printf("E -> T E'\n");
    T();
    EPrime();
}

int main()
{
    printf("  E  -> T E'\n");
    printf("  E' -> + T E' | e\n");
    printf("  T  -> id\n\n");

    printf("Enter the input string: ");
    scanf("%s",str);

    E();

    if (str[i] == '\0') {
        printf("\nResult: String successfully parsed (Accepted)\n");
    } else {
        printf("\nResult: Syntax error, leftover characters (Rejected)\n");
    }
}