#include<stdio.h>
#include<string.h>

char  input[50], stack[50]="";

int check()
{
    int stacklength, flag=1;

    while(flag)
    {
        flag=0;
        stacklength=strlen(stack);

        if (stacklength>=2 && stack[stacklength-2]=='i' && stack[stacklength-1]=='d')
        {
            stack[stacklength-2]='E';
            stack[stacklength-1]='\0';
            printf("%s\t\t%s\t\tREDUCE E->id\n", stack, input);
            flag=1;
        }

        else if (stacklength>=3 && stack[stacklength-3]=='E' && stack[stacklength-1]=='+' && stack[stacklength-1]=='E')
        {
            stack[stacklength-3]='E';
            stack[stacklength-2]='\0';
            printf("%s\t\t%s\t\tREDUCE E->E+E\n", stack, input);
            flag=1;
        }
        else if (stacklength>=3 && stack[stacklength-3]=='E' && stack[stacklength-1]=='*' && stack[stacklength-1]=='E')
        {
            stack[stacklength-3]='E';
            stack[stacklength-2]='\0';
            printf("%s\t\t%s\t\tREDUCE E->E*E\n", stack, input);
            flag=1;
        }
        else if (stacklength>=3 && stack[stacklength-3]=='(' && stack[stacklength-1]=='E' && stack[stacklength-1]==')')
        {
            stack[stacklength-3]='E';
            stack[stacklength-2]='\0';
            printf("%s\t\t%s\t\tREDUCE E->(E)\n", stack, input);
            flag=1;
        }
    }
}

int main()
{
    printf("Grammer: \nE->E+E\nE->E*E\nE->(E)\nE->id\n\n");
    printf("Enter the Input: ");
    scanf("%s",input);

    printf("Stack\t\tInput\t\tAction\n");
    int i=0,inputlength=strlen(input);

    while(i<inputlength)
    {
        if(input[i]=='i' && input[i+1]=='d')
        {
            strcat(stack, "id");

            input[i]=' ';
            input[i+1]=' ';
            i+=2;
            printf("%s\t\t%s\t\tSHIFT id\n", stack, input);
        }
        else
        {
            int stacklength=strlen(stack);
            stack[stacklength]=input[i];
            stack[stacklength+1]='\0';

            input[i]=' ';
            i++;
            printf("%s\t\t%s\t\tSHIFT symbol\n", stack, input);
        }

        check();
    }

    if(strcmp(stack,"E"))
    {
        printf("\nResult: String Accepted Successfully!\n");
    }
    else
    {  
        printf("\nResult: String Rejected\n");   
    }

}