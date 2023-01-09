%{
    #include "/home/alfred/Code/Language/new_langauge/Lokus/include/node.hpp"
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
"void"      |
"int"       |
"char"      |
"bool"      |
"string"    |
"list"      |
"float"                                         SAVE_TOKEN; return DATA_TYPE;

"extern"                                        return TOKEN(EXTERN);
"return"				                        return TOKEN(RETURN);
"if"                                            return TOKEN(IF);
"else"                                          return TOKEN(ELSE);
"elif"                                          return TOKEN(ELIF);
"for"                                           return TOKEN(FOR);
"while"                                         return TOKEN(WHILE);
"print"                                         return TOKEN(PRINT);
"len"                                           return TOKEN(LEN);
\"[^\n"]+\"                                     SAVE_TOKEN; return STRING_VALUE;
[0-9]+					                        SAVE_TOKEN; return INTEGER_VALUE;
[0-9]+\.[0-9]* 			                        SAVE_TOKEN; return FLOAT_VALUE;

"true"				                            SAVE_TOKEN; return TRUE_VALUE;
"false"					                        SAVE_TOKEN; return FALSE_VALUE;

"or"                                            SAVE_TOKEN; return OR;
"and"                                           SAVE_TOKEN; return AND;

[a-zA-Z_][a-zA-Z0-9_]*                          SAVE_TOKEN; return IDENTIFIER;

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
"%"                                             SAVE_TOKEN; return MOD;

"//"[^\n]*                                      
"("	          					                return TOKEN(LPAREN);
")"					          	                return TOKEN(RPAREN);
"{"         						            return TOKEN(LBRACE);
"}"					          	                return TOKEN(RBRACE);
"["                                             return TOKEN(LBRACKET);
"]"                                             return TOKEN(RBRACKET);

"."         						            return TOKEN(DOT);
","				          		                return TOKEN(COMMA);



{linefeed}                                      {line_num++;}
{whitespace}                                    ;
.                                               {InvalidToken();}


%%

void InvalidToken(){
    printf("ERROR ON LINE %d : \n Invalid Token %s\n", line_num,yytext);
    exit(0);
}