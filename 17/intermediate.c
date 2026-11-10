#include<stdio.h>
#include<string.h>
#include<ctype.h>

int i,tempcount=0, top=-1;
char stack[50][10];

int main()
{
    char expression[100], op1[10], op2[10], temp[10];
    
    printf("Enter the Postfix Expression: ");
    scanf("%s", expression);

    for (i=0; expression[i]!='\0'; i++)
    {  
        if(isalnum(expression[i]))
        {
            top++;
            stack[top][0]=expression[i];
            stack[top][1]='\0';
        }

        else if (expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/')
        {
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);

            sprintf(temp, "t%d", tempcount++);
            printf("%s=%s%c%s\n", temp, op1, expression[i], op2);       

            strcpy(stack[++top], temp);
        }
        
    }

}
