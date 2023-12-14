%{
	#include "y.tab.h"
%}
%%
(https|http) {printf("\n\nschema:\t%s\n",yytext);return SC;}
:\/\/[a-z]*\.[a-z]*\.[a-z]* {printf("\n\ndomain:\t%.*s",yyleng,yytext+3);return DM;}
\/[a-z]* {printf("\n\npath:\t%.*s",yyleng,yytext+1);return PT;}
\?[a-z]*\=[0-9]* {printf("\n\nquery:\t%.*s",yyleng,yytext+1);return QR;}
. {return yytext[0];}
%%

int yywrap(){
return 1;
}

