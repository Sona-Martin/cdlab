%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

extern int yylval;
%}

%option noyywrap

%%
[a-zA-Z]+:\/\/   { yylval = strdup(yytext); return SCHEME; }
[0-9]+         { yylval = strdup(yytext); return PORT; }
[a-zA-Z0-9.-]+ { yylval = strdup(yytext); return HOST; }
\/[a-zA-Z0-9/]+ { yylval = strdup(yytext); return PATH; }
[?&][a-zA-Z0-9=&]+ { yylval = strdup(yytext); return QUERY; }
#[a-zA-Z0-9]+   { yylval = strdup(yytext); return FRAGMENT; }
\n             { return 0; }
.              { return *yytext; }
%%

int main() {
    yylex();
    return 0;
}
