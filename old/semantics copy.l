%{
    #include "syntax.tab.h"
    void InvalidToken();

%}

%option noyywrap

whitespace      [ \t\r\v\f]
linefeed        \n

%%
"void"  |
"int"   |
"char"  |
"bool"  |
"float"                                         {yylval.dataType = strdup(yytext);return DATA_TYPE;}

"struct"                                        {yylval.dataType = strdup(yytext);return STRUCT;}

"^"                                             {return POW;}
"*"                                             {return MUL;}
"/"                                             {return DIV;}
"+"                                             {return PLUS;}
"-"                                             {return MINUS;}
"'"                                             {return SINGLE_QUOTES;}
","                                             {return COMMA;}
"="                                             {return EQ;}
"("                                             {return LPAREN;}
")"                                             {return RPAREN;}
"{"                                             {return LCURLY;}
"}"                                             {return RCURLY;}
"["                                             {return LSQUARE;}
"]"                                             {return RSQUARE;}

"return"                                        {return RETURN;}
"continue"                                      {return CONTINUE;}
"break"                                         {return BREAK;}

"and"                                           {return AND;}
"or"                                            {return OR;}
"!"   |
"not"                                           {return NOT;}
"=="                                            {return EE;}
">"                                             {return GT;}
"<"                                             {return LT;}
">="                                            {return GTE;}
"<="                                            {return LTE;}

false                                           {yylval.boolVal = false; return BOOL_VALUE;}
true                                            {yylval.boolVal = true; return BOOL_VALUE;}
[\'][a-zA-Z][\']                                {yylval.charVal = yytext[1];    return CHARACTER_VALUE;}
[-+]?[0-9]+                                     {yylval.intVal = atoi(yytext);  return INTEGER_VALUE;}
[-+]?[0-9]*\.?[0-9]+                            {yylval.floatVal = atof(yytext); return FLOAT_VALUE;}

[a-zA-Z][_a-zA-Z0-9]*(\[[0-9]+\])+              {yylval.strVal = strdup(yytext); return ARRAY_IDENTIFIER;}
[a-zA-Z][_a-zA-Z0-9]*                           {yylval.dataType = strdup(yytext); return IDENTIFIER;}


\"(\\.|[^"])*\"                                 {yylval.strVal = strdup(yytext); return STRING_VALUE;}


{linefeed}                                      {yylineno++; return END_LINE;}
{whitespace}                                    ;
.                                               {InvalidToken();}


%%

void InvalidToken(){
    printf("ERROR ON LINE %d : \n Invalid Token %s\n", yylineno,yytext);
    exit(0);
}