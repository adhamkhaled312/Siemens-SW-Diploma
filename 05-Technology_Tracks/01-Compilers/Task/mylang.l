%{
#include "y.tab.h"
void yyerror(const char *);
%}
%option caseless
%%
[ \t\n]+                 ;
"ENTITY"                 { return ENTITY; }
"ARCHITECTURE"             { return ARCHITECTURE; }
"IS"                       { return IS; }
"OF"                       { return OF; }
"SIGNAL"                   { return SIGNAL; }
"BEGIN"                    { return BEGIN_BLOCK; }
"END"                      { return END_BLOCK; }
[a-zA-Z_][a-zA-Z0-9_]*   { yylval.string = strdup(yytext); return IDENTIFIER; } 
":"                      { return COLON; }
";"                      { return SEMICOLON; }
"<="                     { return ASSIGN; }
[^a-zA-Z_:;<=>\t\n]+     {
                            char error_message[100];
                            sprintf(error_message,"Invalid identifier: %s", yytext);
                            yyerror(error_message);
                          }
%%
int yywrap() {
    return 1;
}
