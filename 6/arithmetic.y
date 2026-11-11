%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    int yyerror(char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
expr: e{
    printf("Result: %d\n",$1);
    return 0;
};

e:  e '+' e     {$$=$1+$3;}
    | e '-' e   {$$=$1-$3;}
    | e '*' e   {$$=$1*$3;}
    | e '/' e   {$$=$1/$3;}
    | '(' e ')' {$$=$1;}
    | NUM       {$$=$1;}
    ;

%%

int yyerror(char *s)
{
    printf("Invalid Expression");
    exit(0);
}

int main()
{
    printf("Enter arithmetic expression: ");
    yyparse();
    printf("Valid Expression");
}