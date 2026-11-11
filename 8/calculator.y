%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<ctype.h>
    int yylex();
    int yyerror(char *s);    
%}

%token NUM
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%
start : expr{
    printf("Result %d\n", $1);
    exit(0);
};

expr:   expr '+' expr               {$$=$1+$3;}
        | expr '-' expr             {$$=$1-$3;}
        | expr '*' expr             {$$=$1*$3;}
        | expr '/' expr             {$$=$1/$3;}
        | '-' expr %prec UMINUS     {$$=-$2;}
        | '(' expr ')'              {$$=$2;}
        | NUM                       {$$=$1;}
        ;
%%

int yyerror(char *c)
{
    printf("Error");
    exit(0);
}

int main()
{
    printf("Enter the input: ");
    yyparse();
}