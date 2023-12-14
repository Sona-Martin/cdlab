%{
  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>
  int yyerror(){
  printf("INVALID");
  exit(EXIT_FAILURE);
  }
%}
%token FOR OP CP TYPE VAR EQ NO SC CMP INC DCR OC CC
%%
stmt: S {printf("VALID");}
S: FOR condi OC S CC |;
condi: OP TYPE VAR EQ NO SC VAR CMP VAL SC VAR CNG CP;
VAL : VAR | NO;
CNG : INC | DCR;

%%
int main(){
	yyparse();
}
