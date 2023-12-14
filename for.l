%{
#include "y.tab.h"
%}
%%
for	{return FOR;}
[(]	{return OP;}
\{	{return OC;}
\}	{return CC;}
(int|float|double)	{return TYPE;}
[a-zA-Z]+[0-9]*	{return VAR;}
\;	{return SC;}
[0-9]+	{return NO;}
\=	{return EQ;}
[<>]    {return CMP;}
[<>][=]	{return CMP;}
[)]	{return CP;}
[+][+]      {return INC;}
[-][-]	{return DCR;}
\n	{return 0;}     
%%
yywrap(){
	return 1;
}
