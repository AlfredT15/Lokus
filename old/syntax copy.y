%{
  #include <cstdio>
  #include <iostream>
  #include <string>
  using namespace std;

  void yyerror(const char *s);
  extern int yylex();
  extern char* yytext;
  extern int yylineno;
  extern FILE *yyin;

%}


%define parse.lac full
%define parse.error verbose


%union {
  int intVal;
  char* dataType;
  char* strVal;
  float floatVal;
  char charVal;
  bool boolVal;
}

// Special characters
%token  COMMA   SINGLE_QUOTES  END_LINE  EQ 
%token  LPAREN  RPAREN   LCURLY  RCURLY LSQUARE  RSQUARE

// Loop control
%token RETURN CONTINUE BREAK

// Comparison
%token AND OR NOT

// Operations
%token PLUS MINUS MUL DIV POW

%token <charVal>    CHARACTER_VALUE
%token <intVal>     INTEGER_VALUE
%token <floatVal>   FLOAT_VALUE
%token <strVal>     STRING_VALUE
%token <boolVal>    BOOL_VALUE


%token <intVal> INT
%token <floatVal> FLOAT
%token <strVal> STRING
%token <dataType> DATA_TYPE
%token <strVal> IDENTIFIER   ARRAY_IDENTIFIER
%token <strVal> STRUCT

%%

statements:
    statement END_LINE
    | END_LINE statement
    ;

statement:
    RETURN expr
    | RETURN
    | CONTINUE
    | BREAK
    | expr
    ;

expr:
    DATA_TYPE IDENTIFIER EQ expr
    | comp-expr AND comp-expr expr
    | comp-expr AND comp-expr
    | comp-expr OR comp-expr expr
    | comp-expr OR comp-expr
    | compr-expr
    ;

compr-expr: 
    NOT comp-expr
    | arith-expr EE arith-expr compr-expr
    | arith-expr EE arith-expr
    | arith-expr GT arith-expr compr-expr
    | arith-expr GT arith-expr 
    | arith-expr LT arith-expr compr-expr
    | arith-expr LT arith-expr 
    | arith-expr GTE arith-expr compr-expr
    | arith-expr GTE arith-expr 
    | arith-expr LTE arith-expr compr-expr
    | arith-expr LTE arith-expr 
    | arith-expr
    ;

arith-expr:
    term PLUS term
    | term PLUS term arith-expr 
    | term MINUS term 
    | term MINUS term arith-expr 
    | term 
    ;

term:
    factor MUL factor
    | factor MUL factor term
    | factor DIV factor
    | factor DIV factor term 
    | factor
    ;

factor:
    PLUS factor
    | MINUS factor
    | power
    ;

power:
    call
    | call POW factor 
    ;

call:
    atom LPAREN expr RPAREN
    | atom LPAREN expr COMMA call
    | expr COMMA
    | expr RPAREN
    | atom
    ;

atom:
    INTEGER_VALUE
    | FLOAT_VALUE
    | STRING_VALUE
    | BOOL_VALUE
    | IDENTIFIER
    ;

%%


int main()
{
  // open a file handle to a particular file:
  FILE *myfile = fopen("test.lk", "r");
  // make sure it is valid:
  if (!myfile) {
    cout << "I can't open test.lk!" << endl;
    return -1;
  }
  // Set flex to read from it instead of defaulting to STDIN:
  yyin = myfile;
  // Parse through the input:
  yyparse();
}

void yyerror(const char *s) {
  cout << "Error on line " << yylineno << "!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}