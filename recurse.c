#include<stdio.h>
#include<stdlib.h>
int ip=0;
char istr[100];
void E();
void Eprime();
void T();
void Tprime();
void F();
int main()
{
        printf("\nGrammer without left recursion ");
        printf("\n\t\tE->TE'\n\t\tE'->+TE'|e\n\t\tT->FT' ");
        printf("\n\t\tT'->*FT'|e\n\t\tF->{E}|i");
        printf("\nenter the expression \t");
        scanf("%s",istr);
        printf("%s",istr);
        printf("\nsequence rule");
        E();
        printf("\nvalue of ip %c",istr[ip]);
        if(istr[ip]=='$')
        {
                printf("\nderived");
        }
        else{
                printf("\nnot valid");
        }
}
void E()
{

        printf("\nE->TE'");
        T();
        Eprime();
}
void Eprime()
{
        if(istr[ip]=='+')
        {
                printf("\nE->+TE'");
                ip++;
                T();
                Eprime();
        }
        else
        {
                printf("\nE->e'");
                return;
        }
}
void T()
{
        printf("\nT->FT'");
        F();
        Tprime();
}    
void Tprime()
{
        if(istr[ip]=='*')
        {
                printf("\nT'->*FT'");
                ip++;
                F();
                Tprime();
        }
        else{
                printf("\nT'->e");
                return;
        }
}  
void F()
{
        if(istr[ip]=='(')
        {
                printf("\nF->(E)");
                ip++;
                E();
                if(istr[ip]==')')
                {
                        ip++;
                }
        }
        else if(istr[ip]=='i')
        {
                printf("\nF->i");
                ip++;
        }
}
