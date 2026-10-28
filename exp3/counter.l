%{                                  //indicates c section in lex
    #include <stdio.h>

    int linecount=0;
    int wordcount=0;
    int charactercount=0;
%}

%%
\n          {linecount++; charactercount++;}
[ \t]+      {charactercount=charactercount+yyleng;}     //yyleng determines length of the string
[^\t\n ]+   {wordcount++; charactercount=charactercount+yyleng;}
%%

//automatically called by scanner upon hitting EOF
int yywrap(void)
{
    return 1;
}

int main()
{
    printf("Enter the input text: ");
    yylex();        //starts scanning action from taking input from terminal

    printf("\nNumber of lines: %d\n", linecount);
    printf("Number of words: %d\n", wordcount);
    printf("Number of characters: %d\n", charactercount);
}

