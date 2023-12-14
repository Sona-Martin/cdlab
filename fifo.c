#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
void first(char c);
void follow(char c);
char a[20][20],f[20];
int m=0,n;
int main()
{
        char ch,c;
        int z=0;
        printf("\nenter the no of grammer \t");
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
                scanf("%s%c",a[i],&ch);
        }
        do{
                m=0;
                printf("\nenter the first and follow of the character that u want to found ");
                scanf("%c",&c);
                first(c);
                printf("\nfirst of %c {",c);
                for(int i=0;i<m;i++)
                        printf("%c",f[i]);
                printf("}\n");
                m=0;
                follow(c);
                printf("\nfollow of %c {",c);
                for(int i=0;i<m;i++)
                        printf("%c",f[i]);
                printf("}\n");
                printf("\ndo u want to continue ");
                scanf("%d%c",&z,&ch);
        }while(z==1);
}

void first(char c)
{
        if(!isupper(c))
                f[m++]=c;
        for(int k=0;k<n;k++)
        {
                if(a[k][0]==c)
                {
                        if(a[k][2]=='$')
                                follow(a[k][0]);
                        else if(islower(a[k][2]))
                                f[m++]=a[k][2];
                        else
                                first(a[k][2]);
                }
        }
}        
void follow(char c)
{
        if(a[0][0]==c)
                f[m++]='$';
        for(int i=0;i<n;i++)
        {
                for(int j=2;j<strlen(a[i]);j++)
                {
                        if(a[i][j]==c)
                        {
                                if(a[i][j+1]!='\0')
                                        first(a[i][j+1]);
                                if(a[i][j+1]=='\0' && c!=a[i][0])
                                        follow(a[i][0]);
                        }
                }
        }
}
