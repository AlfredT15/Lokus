%{
    #include "../include/node.hpp"
    #include "syntax.hpp"
    void InvalidToken();
    int line_num = 1;

    #define SAVE_TOKEN  yylval.string = new std::string(yytext, yyleng)
    #define TOKEN(t)    (yylval.token = t)

%}

%option noyywrap

whitespace      [ \t\r\v\f]
linefeed        \n

%%
"void"  |
"int"   |
"char"  |
"bool"  |
"float"                                         SAVE_TOKEN; return DATA_TYPE;

"extern"                                        return TOKEN(EXTERN);
"return"				                        return TOKEN(RETURN);
[a-zA-Z_][a-zA-Z0-9_]*                          SAVE_TOKEN; return IDENTIFIER;
[0-9]+\.[0-9]* 			                        SAVE_TOKEN; return FLOAT_VALUE;
[0-9]+					                        SAVE_TOKEN; return INTEGER_VALUE;

"="                                             return TOKEN(EQ);		

"=="    |				          	                
"!="	                                        SAVE_TOKEN; return EQ_OP; 

"<"		|		          		                
"<="	|          				                
">"		|		          		                
">="	                                        SAVE_TOKEN; return COMP_OP;	

"+"				          		                SAVE_TOKEN; return ADD;
"-"		                                        SAVE_TOKEN; return SUB;

"*"		         				                SAVE_TOKEN; return MUL;
"/"				          		                SAVE_TOKEN; return DIV;

"("	          					                return TOKEN(LPAREN);
")"					          	                return TOKEN(RPAREN);
"{"         						            return TOKEN(LBRACE);
"}"					          	                return TOKEN(RBRACE);

"."         						            return TOKEN(DOT);
","				          		                return TOKEN(COMMA);




{linefeed}                                      {line_num++; return END_LINE;}
{whitespace}                                    ;
.                                               {InvalidToken();}


%%

void InvalidToken(){
    printf("ERROR ON LINE %d : \n Invalid Token %s\n", line_num,yytext);
    exit(0);
}