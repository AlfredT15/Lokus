%{
  #include "../include/node.hpp"
  #include <cstdio>
  #include <cstdlib>
  #include <vector>
	NBlock *programBlock; /* the top level root node of our final AST */

	#define YYERROR_VERBOSE 1
	extern int yylex();
	extern int line_num;

  void yyerror(const char *s) { 
    std::printf("Error on line %d!  Message: %s \n", line_num, s);std::exit(1); }
%}

/* Represents the many different ways we can access our data */
%union {
	Node *node;
	NBlock *block;
	NExpression *expr;
	NStatement *stmt;
	NIdentifier *ident;
	NOperator *op;
	NVariableDeclaration *var_decl;
	std::vector<NVariableDeclaration*> *varvec;
	std::vector<NExpression*> *exprvec;
	std::string *string;
	int token;
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <string> CHARACTER_VALUE STRING_VALUE INTEGER_VALUE FLOAT_VALUE TRUE_VALUE FALSE_VALUE
%token <string> IDENTIFIER DATA_TYPE
%token <string> EQ_OP COMP_OP ADD SUB MUL DIV
%token <token>  EQ
%token <token>  LPAREN RPAREN LBRACE RBRACE COMMA DOT
%token <token>  RETURN EXTERN
%token <token> 	IF ELIF ELSE
%token <token> 	FOR WHILE 
// %token          END_LINE

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident> ident data_type_and_ident
%type <op> op
%type <expr> numeric boolean expr 
%type <varvec> func_decl_args
%type <exprvec> call_args
%type <block> program stmts block
%type <stmt> stmt var_decl func_decl extern_decl if_stmt for_stmt while_stmt

/* Operator precedence for mathematical operators */
%precedence EQ_OP 
%precedence COMP_OP
%left ADD SUB
%left MUL DIV

%start program

%%

program : stmts { programBlock = $1; }
		;

		
stmts : stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
	  | stmts stmt { $1->statements.push_back($<stmt>2); }
	  ;


stmt : var_decl | func_decl | extern_decl | if_stmt | for_stmt | while_stmt
	 | expr { $$ = new NExpressionStatement(*$1); }
	 | RETURN expr { $$ = new NReturnStatement($2); }
     ;

block : LBRACE stmts RBRACE { $$ = $2; }
	  | LBRACE RBRACE { $$ = new NBlock(); }
	  ;

if_stmt : IF expr block { $$ = new NIfStatement($2, *$3); }
		| IF expr block if_stmt { $$ = new NIfStatement($2, *$3, $4); }
		| ELIF expr block { $$ = new NIfStatement($2, *$3); }
		| ELIF expr block if_stmt { $$ = new NIfStatement($2, *$3, $4); }
		| ELSE block  { $$ = new NIfStatement(*$2); }
		;

for_stmt : FOR LPAREN expr COMMA expr COMMA expr RPAREN block { $$ = new NForStatement($3, $5, $7, *$9); }
		 | FOR LPAREN var_decl COMMA expr COMMA expr RPAREN block { $$ = new NForStatement($3, $5, $7, *$9); }
		 ;

while_stmt : WHILE expr block { $$ = new NWhileStatement($2, *$3); }
		   ;

var_decl : data_type_and_ident { $$ = new NVariableDeclaration(*$1); }
		 | data_type_and_ident EQ expr { $$ = new NVariableDeclaration(*$1, $3); }
		 ;

extern_decl : EXTERN data_type_and_ident LPAREN func_decl_args RPAREN
                { $$ = new NExternDeclaration(*$2,*$4); delete $4;}
            ;

func_decl : data_type_and_ident LPAREN func_decl_args RPAREN block 
			{ $$ = new NFunctionDeclaration(*$1, *$3, *$5); delete $3; }
		  ;
	
func_decl_args : /*blank*/  { $$ = new VariableList(); }
		  | var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1); }
		  | func_decl_args COMMA var_decl { $1->push_back($<var_decl>3); }
		  ;

data_type_and_ident : DATA_TYPE IDENTIFIER { $$ = new NIdentifier(*$1, *$2); delete $1; delete $2;}
					;

ident : IDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }
	  ;

// numeric and boolean should be removed later
numeric : INTEGER_VALUE { $$ = new NInteger(atol($1->c_str())); delete $1; }
		| FLOAT_VALUE { $$ = new NDouble(atof($1->c_str())); delete $1; }
		;

boolean : TRUE_VALUE { $$ = new NBool($1->c_str()); delete $1; }
		| FALSE_VALUE { $$ = new NBool($1->c_str()); delete $1; }
		;
	
expr : ident EQ expr { $$ = new NAssignment(*$<ident>1, *$3); }
	 | ident LPAREN call_args RPAREN { $$ = new NMethodCall(*$1, *$3); delete $3; }
	 | ident { $<ident>$ = $1; }
	 | numeric
	 | boolean
	 | expr op expr { $$ = new NBinaryOperator(*$1, *$2, *$3); }
	 | LPAREN expr RPAREN { $$ = $2; }
	 ;

op : MUL	{ $$ = new NOperator(*$1); delete $1; }
   | DIV	{ $$ = new NOperator(*$1); delete $1; }
   | ADD	{ $$ = new NOperator(*$1); delete $1; }
   | SUB	{ $$ = new NOperator(*$1); delete $1; }
   | COMP_OP{ $$ = new NOperator(*$1); delete $1; }
   | EQ_OP	{ $$ = new NOperator(*$1); delete $1; }

	
call_args : /*blank*/  { $$ = new ExpressionList(); }
		  | expr { $$ = new ExpressionList(); $$->push_back($1); }
		  | call_args COMMA expr  { $1->push_back($3); }
		  ;

%%