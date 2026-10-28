#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, count=0;
char production[10][10];
char result[20];


int add(char c)
{
    for(int i=0; i<count;i++)
    {
        if(result[i]==c)
        {
            return;
        }
    }
    result[count++]=c;
}


int first(char c)
{
    if(!isupper(c))
    {
        add(c);
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if (production[i][0]==c)
        {
            if(production[i][2]=='#')
            {
                add('#');
            }
            else if(!isupper(production[i][2]))
            {
                add(production[i][2]);
            }
            else
            {
                first(production[i][2]);
            }
        }
    }
}

int follow(char c)
{
    if(production[0][0]==c)
    {
        add('$');
    }
    for(int i=0;i<n;i++)
    {
        for(int j=2;j<strlen(production[i]);j++)
        {
            if (production[i][j]==c)
            {
                if(production[i][j+1] != '\0')
                {
                    first(production[i][j+1]);
                }
                else if(production[i][j+1]=='\0' && c!=production[i][0])
                {
                    follow(production[i][0]);
                }
            }
        }
    }
}

int main()
{
    int choice;
    char c;
    printf("Enter the Number of Productions: ");
    scanf("%d",&n);

    printf("Enter Productions: ");
    for(int i=0;i<n;i++)
    {
        scanf("%s",production[i]);
    }

    do
    {
        printf("Enter the non terminal: ");
        scanf(" %c",&c);

        count=0;
        first(c);

        printf("FIRST(%c)={", c);
        for(int i=0;i<count;i++)
        {
            printf("%c",result[i]);
        }

        count=0;
        follow(c);
        printf("FOLLOW(%c)={", c);
        for (int i = 0; i < count; i++) {
            if (result[i]!='#') {
                printf("%c ", result[i]);
            }
        }

        printf("}\n");

        printf("Continue? (1/0): ");
        scanf("%d", &choice);
    } while (choice == 1);

}