%{
  #include "../include/node.hpp"
  #include <cstdio>
  #include <cstdlib>
  #include <vector>
	NBlock *programBlock; /* the top level root node of our final AST */

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
  	NIdentifier *data_type;
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
%token <string> CHARACTER_VALUE STRING_VALUE INTEGER_VALUE FLOAT_VALUE BOOL_VALUE
%token <string> IDENTIFIER DATA_TYPE
%token <string> EQ_OP COMP_OP ADD SUB MUL DIV
%token <token>  EQ
%token <token>  LPAREN RPAREN LBRACE RBRACE COMMA DOT
%token <token>  RETURN EXTERN
%token          END_LINE

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident> ident
%type <op> op
%type <data_type> data_type;
%type <expr> numeric expr 
%type <varvec> func_decl_args
%type <exprvec> call_args
%type <block> program stmts block
%type <stmt> stmt var_decl func_decl extern_decl

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
	  | stmts END_LINE stmt { $1->statements.push_back($<stmt>3); }
    | stmts END_LINE
	  ;

stmt : var_decl | func_decl | extern_decl
	 | expr { $$ = new NExpressionStatement(*$1); }
	 | RETURN expr { $$ = new NReturnStatement(*$2); }
     ;

block : LBRACE stmts RBRACE { $$ = $2; }
	  | LBRACE RBRACE { $$ = new NBlock(); }
	  ;

var_decl : data_type ident { $$ = new NVariableDeclaration(*$1, *$2); }
		 | data_type ident EQ expr { $$ = new NVariableDeclaration(*$1, *$2, $4); }
		 ;

extern_decl : EXTERN data_type ident LPAREN func_decl_args RPAREN
                { $$ = new NExternDeclaration(*$2, *$3, *$5); delete $5; }
            ;

func_decl : data_type ident LPAREN func_decl_args RPAREN block 
			{ $$ = new NFunctionDeclaration(*$1, *$2, *$4, *$6); delete $4; }
		  ;

data_type : DATA_TYPE { $$ = new NIdentifier(*$1); delete $1; }
	
func_decl_args : /*blank*/  { $$ = new VariableList(); }
		  | var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1); }
		  | func_decl_args COMMA var_decl { $1->push_back($<var_decl>3); }
		  ;

ident : IDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }
	  ;

numeric : INTEGER_VALUE { $$ = new NInteger(atol($1->c_str())); delete $1; }
		| FLOAT_VALUE { $$ = new NDouble(atof($1->c_str())); delete $1; }
		;
	
expr : ident EQ expr { $$ = new NAssignment(*$<ident>1, *$3); }
	 | ident LPAREN call_args RPAREN { $$ = new NMethodCall(*$1, *$3); delete $3; }
	 | ident { $<ident>$ = $1; }
	 | numeric
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