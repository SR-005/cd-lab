#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Constant{
    char var;
    char val;
}table[10];

int count=0;

int getconstant(char v)
{
    for(int i=0; i<count;i++)
    {
        if(table[i].var==v)
        {
            return table[i].val;
        }
    }
    return 0;
}

int main()
{
    FILE *in=fopen("input.txt","r");
    FILE *out=fopen("output.txt","w");
    if (in == NULL || out == NULL) {
        printf("Error: Could not open input.txt or output.txt\n");
        return 1;
    }

    char line[50];
    printf("Original Input File");
    while(fgets(line,sizeof(line),in)!=NULL)
    {
        line[strcspn(line, "\r\n")] = '\0';
        if (strlen(line) == 0) continue;
        printf("%s",line);

        if(isalpha(line[0]) && line[1]=='=' && isdigit(line[2]) && (line[3]=='\n' ||  line[3]=='\0'))
        {
            table[count].var=line[0];
            table[count].val=line[2];
            count++;
            fputs(line,out);
        }
        else
        {
            for(int i=2;line[i]!='\0';i++)
            {
                if(isalpha(line[i]))
                {
                    char c=getconstant(line[i]);
                    if(c!=0)
                    {
                        line[i]=c;
                    }
                }
            }
            fputs(line,out);
        }
    }

    fclose(in);
    fclose(out);

    FILE *output=fopen("output.txt","r");
    while(fgets(line,sizeof(line),output)!=NULL)
    {
        printf("%s", line);
    }
    fclose(output);

}