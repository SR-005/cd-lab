#include<stdio.h>
#include<string.h>

int main()
{
    FILE *input=fopen("input.txt","r");
    FILE *output=fopen("machinecode.txt","w");

    

    int i;
    char quadruple[20];
    char operator, arg1, arg2, result;

    while(fscanf(input, "%s", quadruple)!=EOF)
    {
        result=quadruple[0];
        arg1=quadruple[2];

        fprintf(output, "MOV R%d, %c\n", i, arg1);

        if(quadruple[3]!='\0')
        {
            operator=quadruple[3];
            arg2=quadruple[4];

            if(operator=='+')
                fprintf(output, "ADD R%d, %c\n", i, arg2);
            else if(operator=='-')
                fprintf(output, "SUB R%d, %c\n", i, arg2);
            else if(operator=='*')
                fprintf(output, "MUL R%d, %c\n", i, arg2);
            else if(operator=='/')
                fprintf(output, "DIV R%d, %c\n", i, arg2);
        }
        fprintf(output, "MOV %c, R%d\n", result, i);
        i++;
    }
    fclose(input);
    fclose(output);
}