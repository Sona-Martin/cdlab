%{
#include<stdio.h>
#include<stdlib.h>
int yyerror(){
printf("Invalid");
exit(EXIT_FAILURE);
}
%}
%token A B
%%
stmt:S	{printf("\nvalid\n");}
S:A S B|;
 
%%
int main(){
	yyparse();
}
