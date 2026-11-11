#include<stdio.h>
#include<string.h>

int main()
{
    int n,i;
    char tac[20][20];
    char operator, arg1, arg2, result;

    printf("Enter the number of lines: ");
    scanf("%d",&n);

    printf("Enter the 3 Address Code Statements: ");
    for(i=0;i<n;i++)
    {
        scanf("%s", tac[i]);
    }

    for(i=0;i<n;i++)
    {
        result=tac[i][0];
        arg1=tac[i][2];

        printf("MOV R%d %c\n", i, arg1);

        if(tac[i][3]!='\0')
        {
            operator=tac[i][3];
            arg2=tac[i][4];

            if(operator=='+')
                printf("ADD R%d, %c\n", i, arg2);
            else if(operator=='-')
                printf("SUB R%d, %c\n", i, arg2);
            else if(operator=='*')
                printf("MUL R%d, %c\n", i, arg2);
            else if(operator=='/')
                printf("DIV R%d, %c\n", i, arg2);
        }
        printf("MOV %c, R%d", result, i);
    }
}