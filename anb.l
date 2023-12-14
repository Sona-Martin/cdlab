%{
#include "y.tab.h"
%}
%%
[aA] {return A;}
[bB] {return B;}
%%

int yywrap(){
return 1;
}
