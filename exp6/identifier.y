%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);
%}

%token ALPHA DIGIT ENTER

%%
start:  
    var ENTER  {
        printf("Valid Identifier!");
        exit(0);
    }
    ;
var:
    ALPHA rest
    ;
rest:
      ALPHA rest
    | DIGIT rest
    |
    ;
%%

int main()
{
    printf("Enter the Identifier: ");
    yyparse();
}

int yyerror(char *s)
{
    printf("Invald Identifier");
}