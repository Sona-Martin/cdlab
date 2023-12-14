%{
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 int yyerror(){
 printf("INVALID");
 exit(EXIT_FAILURE);
 }
%}
%token NO
%left '+' '-'
%left '*' '/' '%'
%left  '(' ')'
%%
expr : E {printf("\n\n\tVALID\n\nResult: \t%d",$$);}
E : E '+' E 	{$$=$1+$3;}
  |E '-' E 	{$$=$1-$3;}|
   E '*' E 	{$$=$1*$3;}|
   E '/' E 	{$$=$1/$3;}|
   E '%' E 	{$$=$1%$3;}|
   '('E')' 	{$$=$2;} |
   NO	{$$=$1;};
%%
int main(){
	yyparse();
}
