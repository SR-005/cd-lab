%{
    #include<stdio.h>    
%}

DIGIT   [0-9]
ID      [a-zA-Z_][a-zA-Z0-9_]

%%

if|then|else|for|while|int|char         {printf("%s is a keyword\n",yytext);}
{DIGIT}+                                {printf("%s is a digit\n",yytext);}
{DIGIT}\.{DIGIT}+                      {printf("%s is a floating point number\n",yytext);}
{ID}+                                   {printf("%s is an Identifier\n",yytext);}
[=+\-*/<>]                              {printf("%s is an Operator\n",yytext);}
[(),;]                                  {printf("%s is an Seperator\n",yytext);}
[\t\n ]+                                ;
.                                       ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the Input: ");
    yylex();
}