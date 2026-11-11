#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char string[50];
int i=0;


int T()
{
    if(isalpha(string[i]))
    {
        printf("T->id\n");
        i++;
    }
    else
    {
        printf("Error: Expected identifier\n");
        exit(0);
    }
}

int EPrime()
{
    if(string[i]=='+')
    {
        printf("E'->+TE'\n");
        i++;
        T();
        EPrime();
    }
    else
    {
        printf("E'->e\n");
    }
}

int E()
{
    printf("E->TE'\n");
    T();
    EPrime();
}

int main()
{
    printf("Enter the String: ");
    scanf("%s", string);

    E();
    if(string[i]=='\0')
    {
        printf("Stirng is Accepted!");
    }
    else
    {
        printf("Stirng is not Accepted!");
    }
}