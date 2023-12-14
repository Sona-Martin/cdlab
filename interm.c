#include<stdio.h>
#include<string.h>
void gen_code_for_operator(char *inp,char operator ,char *reg)
{
        int i=0,j=0;
        char temp[100];
        /*printf("new temp for next op: %s",temp);*/
        
        while(inp[i]!='\0')
        {	/*printf("\ninput i:%c\n",inp[i]);*/
                if(inp[i]==operator)
                {
                        printf("\n%c\t%c\t%c\t%c",operator,*reg,inp[i-1],inp[i+1]);
                        temp[j-1]=*reg;
			/*printf("\nop so temp: %s",temp);*/
                        i+=2;
                        (*reg)--;
                        
                }else{
                temp[j]=inp[i];
                /*printf("\nnot op so temp: %s",temp);*/
                i++;
                j++;
		}
        }
        temp[++j]='\0';
 	/*printf("\n\t\t\t\t%s",temp);*/
        strcpy(inp,temp);
        memset(temp,0,sizeof(temp));
}

void gen_code(char *inp)
{
        char reg='Z';
        gen_code_for_operator(inp,'/',&reg);
        gen_code_for_operator(inp,'*',&reg);
        gen_code_for_operator(inp,'+',&reg);
        gen_code_for_operator(inp,'-',&reg);
        gen_code_for_operator(inp,'=',&reg);
     
}

int main()
{
        char inp[100];
        printf("\nenter thr expression\t");
        scanf("%s",inp);
        printf("\noper\tdestn\top1\t0p2");
        gen_code(inp);
}
