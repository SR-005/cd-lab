#include<stdio.h>
#include<ctype.h>

int main()
{
    FILE *input=fopen("input.txt","r");
    FILE *output=fopen("output.txt","w");

    char line[50];
    char array[10][2];
    int i,j,count=0;

    while(fscanf(input, "%s", line)!=EOF)
    {
        if(line[1]=='=' && isdigit(line[2]) && line[3]=='\0')
        {
            array[count][0]=line[0];
            array[count][1]=line[2];
            count++;
        }
        fprintf(output, "%c=", line[0]);

        for(i=2;line[i]!='\0';i++)
        {
            char ch=line[i];
            int replaced=0;

            for(j=0;j<count;j++)
            {
                if(array[j][0]==ch)
                {
                    fputc(array[j][1], output);
                    replaced=1;
                    break;
                }
            }

            if(!replaced)
            {
                fputc(ch, output);
            }
        }
        fputc('\n', output);
    }
    fclose(input);
    fclose(output);
    printf("Constant propagation completed! Check output.txt\n");
    return 0;

}