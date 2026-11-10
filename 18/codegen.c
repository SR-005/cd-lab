#include<stdio.h>
#include<string.h>

int main()
{
    int n,i;
    char expression[20][20];
    char operator, arg1, arg2, result;

    printf("Enter the number of lines: ");
    scanf("%d",&n);

    printf("Enter the 3 Address Code Statements: ");
    for(i=0;i<n;i++)
    {
        scanf("%s", expression[i]);
    }

    for(i=0;i<n;i++)
    {
        result=expression[i][0];
        arg1=expression[i][2];

        printf("MOV R%d %c\n", i, arg1);

        if(expression[i][3]!='\0')
        {
            operator=expression[i][3];
            arg2=expression[i][4];

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