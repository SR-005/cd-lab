#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKENLENGTH 256

const char *keywords[]={
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", 
    "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", 
    "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", 
    "volatile", "while"
};

//finding the total number of keywords by dividing total number by size of one keyword
const int totalkeywords=sizeof(keywords)/sizeof(keywords[0]);

int iskeyword(const char *str)
{
    for (int i=0;i<totalkeywords;i++)
    {
        if(strcmp(str, keywords[i])==0)
            return 1;
    }
    return 0;
}

int isoperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='='||c=='>'||c=='<');
}

int isseperator(char c){
    return (c==','||c=='('||c==')'||c=='{'||c=='}'||c=='['||c==']');
}

int isdelimiter(char c){
    return (c==';');
}

int main()
{
    FILE *file=fopen("la.txt","r");
    if (file==NULL)
    {
        printf("File not Found!!");
        return 1;
    }

    char token[MAXTOKENLENGTH];
    int c;

    while ((c=fgetc(file)) != EOF)
    {
        if (c=='#')         //if c is start of preprocessor line '#'
        {
            int i=0;
            token[i++]=c;       //store # to token

            while ((c=fgetc(file)) != EOF && c!='\n')     //read every character into token until newline 
            {
                if (i < MAXTOKENLENGTH - 1)
                {
                    token[i++]=c;
                }
            }
            token[i]='\0';

            char *start=strchr(token, '<');     //to find first occurance of <
            char *end=strchr(token, '>');       //to find first occurance of >

            if(start && end && start<end)
            {
                printf("header file: %s\n", token);
            }
            else
            {
                printf("preprocessor directive: %s\n", token);
            }
        }

        else if(isalpha(c) || c=='_')   //c variables must begin with alphabets or _
        {
            int i=0;
            token[i++]=c;
            while((c=fgetc(file)) != EOF && (isalnum(c) || c=='_'))   //keep reading as long as they are letter,digits,underscores
            {
                if (i < MAXTOKENLENGTH - 1)
                {
                    token[i++]=c;
                }
            }   
            token[i]='\0';
            ungetc(c, file);        //return the file pointer to where you began the loop
        
            if(iskeyword(token))
                printf("Keyword: %s\n", token);
            else
                printf("Identifier: %s\n", token);
        }

        else if(isdigit(c)) 
        {
            int i=0;
            token[i++]=c;
            while((c=fgetc(file)) != EOF && isdigit(c))   //keep reading as long as they are letter,digits,underscores
            {
                token[i++]=c;
            }
            token[i]='\0';
            ungetc(c, file);        //return the file pointer to where you began the loop
            printf("Number: %s\n", token);
        }

        else if (isdelimiter(c))
        {
            printf("Delimiter: %c\n", c);
        }

        else if (isseperator(c))
        {
            printf("Separator: %c\n", c);
        }

        else if (isoperator(c))
        {
            printf("Operator: %c\n", c);
        }

        else if (c=='"')
        {
            int i=0;
            token[i++]=c;
            while ((c=fgetc(file))!=EOF && c!='"')
            {
                if (i < MAXTOKENLENGTH - 1)
                {
                    token[i++]=c;
                }
            }
            
            if (i < MAXTOKENLENGTH - 1)
            {
                token[i++]='"';
            }

            token[i]='\0';
            printf("String: %s\n", token);
        }

        else if (isspace(c)) {
            continue;
        }
        else {
            printf("Other: %c\n", c);
        }
    }

    fclose(file);
    return 0;
}