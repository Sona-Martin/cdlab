%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern int yywrap();
extern char* yytext;
extern int yylval;

#define YYSTYPE char*

%}

%token SCHEME HOST PORT PATH QUERY FRAGMENT

%%
url : SCHEME ':' hier_part
    {
        printf("Scheme: %s\n", $1);
        printf("Host: %s\n", $3);
        if ($4 != NULL) printf("Port: %s\n", $4);
        printf("Path: %s\n", $5);
        if ($6 != NULL) printf("Query: %s\n", $6);
        if ($7 != NULL) printf("Fragment: %s\n", $7);
    }
    ;

hier_part : '\/\/' HOST port_and_path
    {
        // Handle optional port and path here
        printf("Host: %s\n", $2);
    }
    | PATH optional_query
    {
        // Handle path and optional query here
        printf("Path: %s\n", $1);
        if ($2 != NULL) printf("Query: %s\n", $2);
    }
    ;

port_and_path : PORT PATH optional_query
    {
        // Construct the result based on matched elements
        // You may need to handle the NULL cases as needed
        // This is just a basic example
        $$ = strcat($1, $2);
        if ($3 != NULL) {
            $$ = strcat($$, $3);
        }
    }
    | PATH optional_query
    {
        // Construct the result based on matched elements
        // You may need to handle the NULL cases as needed
        // This is just a basic example
        $$ = $1;
        if ($2 != NULL) {
            $$ = strcat($$, $2);
        }
    }
    ;

optional_query : '?' QUERY
    {
        $$ = $2;
    }
    | /* empty */
    {
        $$ = NULL;
    }
    ;

%%

int main() {
    yyparse();
    return 0;
}
