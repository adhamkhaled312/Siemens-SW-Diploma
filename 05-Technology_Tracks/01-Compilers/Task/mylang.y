%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();

typedef struct signal {
    char *name;
    char *type;
} signal_t;

signal_t signals[100];
int signal_count = 0;
int find_signal(const char *name);
void add_signal(const char *name, const char *type);
char *entity_name;
char error_message[100];

%}

%union {
    char *string;
}

%token <string> IDENTIFIER ENTITY ARCHITECTURE IS OF SIGNAL BEGIN_BLOCK END_BLOCK ASSIGN
%token COLON SEMICOLON
%type <string> entity architecture signal signal_decl

%%

program: entity architecture { printf("Parsing successful\n"); }
       ;

entity: ENTITY IDENTIFIER IS END_BLOCK SEMICOLON
       { entity_name=$2; }
       ;

architecture: ARCHITECTURE IDENTIFIER OF IDENTIFIER IS signal_decl BEGIN_BLOCK statement_list END_BLOCK SEMICOLON
            {
                if (strcmp($4,entity_name) != 0) {
                    sprintf(error_message,"%s doesn't match the declared entity name %s",$4,entity_name);
                    yyerror(error_message);
                }
            }
            ;

signal_decl: {}
           | signal_decl signal
           ;

signal: SIGNAL IDENTIFIER COLON IDENTIFIER SEMICOLON
       { 
           if (find_signal($2) == -1) {
               add_signal($2, $4);
           } else {
               yyerror("Signal already declared");
           }
       }
       ;

statement_list: {}
              | statement_list statement
              ;

statement: IDENTIFIER ASSIGN IDENTIFIER SEMICOLON
         {
             int lhs_index = find_signal($1);
             int rhs_index = find_signal($3);
             if (lhs_index == -1) {
                sprintf(error_message,"Unknown signal: %s", $1);
                yyerror(error_message);
             } else if(rhs_index == -1){
                sprintf(error_message,"Unknown signal: %s", $3);
                yyerror(error_message);
             } else if (strcmp(signals[lhs_index].type, signals[rhs_index].type) != 0) {
                sprintf(error_message,"Signal types don't match in assignment. LHS type : %s ,RHS type : %s",signals[lhs_index].type,signals[rhs_index].type);
                yyerror(error_message);
             }else 
             {}
         }
         ;

%%

int find_signal(const char *name) {
    for (int i = 0; i < signal_count; i++) {
        if (strcmp(signals[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_signal(const char *name, const char *type) {
    signals[signal_count].name = strdup(name);
    signals[signal_count].type = strdup(type);
    signal_count++;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(EXIT_FAILURE);
}

int main() {
    return yyparse();
}
