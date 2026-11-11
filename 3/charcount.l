%{
    #include<stdio.h>
    int lc, wc, cc, sc;
%}

%%
[\n]        {lc++; cc+=yyleng;}
[\t ]       {sc++; cc+=yyleng;}
[^\n\t ]+   {wc++; cc+=yyleng;}
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the content: ");
    yylex();
    printf("Lines: %d\n",lc);
    printf("Word: %d\n",wc);
    printf("Character: %d\n",cc);
    printf("Space: %d\n",sc);
}
