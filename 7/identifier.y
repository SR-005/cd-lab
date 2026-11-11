%{
    #include<stdio.h>
    #include <stdlib.h>
    int yylex();
    int yyerror();
%}

%token ALPHA NUMBER ENTER

%%
var: v ENTER {
    printf("Valid Variable\n");
    exit(0);
    };

v:  ALPHA expl;

expl:   ALPHA expl
        | NUMBER expl
        |
        ;
%%

int yyerror()
{
    printf("Invalid Variable!");
    exit(0);
}

int main()
{
    printf("Enter the Identifier: ");
    yyparse();
}