%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/'
%left '(' ')'


%%
expr:
    e{
        printf("valid expression\n");
        printf("Result: %d\n", $1);
        return 0;
    }

e:
      e '+' e       {$$=$1+$3;}
    | e '-' e       {$$=$1-$3;}
    | e '*' e       {$$=$1*$3;}
    | e '/' e       {$$=$1/$3;}
    | '(' e ')'     {$$=$2;}
    | NUM           {$$=$1;}
    ;
%%

int main()
{
    printf("Enter the arithmetic expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf("Invalid expression\n");
    exit(0);
}
