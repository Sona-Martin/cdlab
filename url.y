%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int yyerror(const char *);
%}
%token  SC
%%
URL : SC {printf("hi:%s",$1); $$=$1;}

%%
int yyerror(const char *s)
{
  
  return 0;
}
int main(){
yyparse();
}
