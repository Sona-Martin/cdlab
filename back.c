#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
        char expr[10][10],strs[20],opr[20];
        int n;
        printf("\nenter the value of n\t");
        scanf("%d",&n);
         printf("\nenter the expression\n");
        for(int i=0;i<n;i++)
        {
                scanf("%s",expr[i]);
        }
        int i=0;
        do{
                strcpy(strs,expr[i]);
                switch(strs[3])
                {
                        case '+':
                                strcpy(opr,"ADD");
                                break;
                        case '-':
                                strcpy(opr,"SUB");
                                break;
                        case '/':
                                strcpy(opr,"DIV");
                                break;
                        case '*':
                                strcpy(opr,"MUL");
                                break;
                }
                printf("\nMov %c ,R%d",strs[2],i);
                printf("\n%s %c ,R%d",opr,strs[4],i);
                printf("\nMov R%d, %c",i,strs[0]);
                n-=1;
        }while(n>0);       
}
        
       
