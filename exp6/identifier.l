%{
    #include<stdio.h>
    #include "y.tab.h"
%}

%%
[a-zA-Z]    {return ALPHA;}
[0-9]       {return DIGIT;}
\n          {return ENTER;}
.           {return yytext[0];}
%%

int yywrap()
{
    return 1;
}