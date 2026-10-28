%{
    #include <stdio.h>
    int vowels=0;
    int consonents=0;
%}

%%
[aeiouAEIOU]    {vowels++;}
[a-zA-Z]    {consonents++;}
.|\n        {}
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the String: ");
    yylex();

    printf("\nNumber of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonents);
}