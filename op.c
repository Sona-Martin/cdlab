#include<stdio.h>
#include<string.h>
#include<stdio.h>
int main()
{
        int n,k=0,col=0,row=0,top=0;
        char stack[20],ter[20],ip[20],opt[20][20];
        printf("\nenter thr no of terminals\t");
        scanf("%d",&n);
        printf("\nenter the terminals\t");
        scanf("%s",ter);
        printf("\nenter their precedence ");
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        printf("\nenter their precedence %c %c :",ter[i],ter[j]);
                        scanf("%s",&opt[i][j]);
                }
        }
        printf("\nprecedence table is \n");
        for(int i=0;i<n;i++)
        {
                printf("\t%c",ter[i]);
        }
        for(int i=0;i<n;i++)
        {
                printf("\n%c",ter[i]);
                for(int j=0;j<n;j++)
                {
                        printf("\t %c",opt[i][j]);
                }
        }
        printf("\nenter the input string\t");
        scanf("%s",ip);
        stack[top]='$';
        printf("\nSTACK\t\t\tINPUT\t\t\tACTION");
        printf("\n%s\t\t\t%s\t\t\t",stack,ip);
        while(k<=strlen(ip))
        {
                for(int i=0;i<n;i++)
                {
                        if(stack[top]==ter[i])
                                col=i;
                        if(ip[k]==ter[i])
                                row=i;
                }
                if((stack[top]=='$')&&(ip[k]=='$'))
                {
                        printf("\nstring is accepted");
                        break;
                }
                else if((opt[col][row]=='<')||(opt[col][row]=='='))
                {
                        stack[++top]=opt[col][row];
                        stack[++top]=ip[k];
                        printf("shifted %c",ip[k]);
                        k++;
                }
                else
                {
                        if(opt[col][row]=='>')
                        {
                                while(stack[top]!='<')
                                        top--;
                                top=top-1;
                                printf("reduced");
                        }
                        else{
                                printf("\nstring is not accpeted");
                                break;
                            }
                }
                printf("\n");
                for(int i=0;i<=top;i++)
                {
                        printf("%c",stack[i]);
                }
                printf("\t\t\t");
                for(int i=k;i<strlen(ip);i++)
                {
                        printf("%c",ip[i]);
                }
                printf("\t\t\t");
         }      
}
