#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[20],act[20],stk[20],ac[20];
int c=0,k=0,i=0,j=0,z=0;
void check();
int main()
{

      printf("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id");
      printf("enter input string ");
      scanf("%s",a);
      c=strlen(a);
      strcpy(act,"SHIFT->");
      printf("stack \t input \t action");
      for(k=0,i=0; j<c; k++,i++,j++)
       {
         if(a[j]=='i' && a[j+1]=='d')
           {
              stk[i]=a[j];
              stk[i+1]=a[j+1];
              stk[i+2]='\0';
              a[j]=' ';
              a[j+1]=' ';
              printf("\n$%s\t%s\t%sid",stk,a,act);
              check();
           }
         else
           {
              stk[i]=a[j];
              stk[i+1]='\0';
              a[j]=' ';
              printf("\n$%s\t%s\t%ssymbols",stk,a,act);
              check();
           }
       }

}
void check()
{
        strcpy(ac,"Reduced to E");
        for(z=0;z<c;z++)
        {
                if(stk[z]=='i'&& stk[z+1]=='d')
                {
                        stk[z]='E';
                        stk[z+1]='\0';
                        printf("\n$%s\t%s\t%s",stk,a,ac);
                        j++;
               }
      
               else if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E')
                {
                        stk[z]='E';
                        stk[z+1]='\0';
                        stk[z+2]='\0';
                        printf("\n$%s\t%s\t%s",stk,a,ac);
                        i=i-2;
                }
                else if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E')
                {
                        stk[z]='E';
                        stk[z+1]='\0';
                        stk[z+2]='\0';
                        printf("\n$%s\t%s\t%s",stk,a,ac);
                        i=i-2;
                }
                else if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
                {
                        stk[z]='E';
                        stk[z+1]='\0';
                        stk[z+2]='\0';
                        printf("\n$%s\t%s$\t%s",stk,a,ac);
                        i=i-2;
                }
        }                  
        
}
