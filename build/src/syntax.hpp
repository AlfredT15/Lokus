/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_ALFRED_CODE_LANGUAGE_NEW_LANGAUGE_LOKUS_BUILD_SRC_SYNTAX_HPP_INCLUDED
# define YY_YY_HOME_ALFRED_CODE_LANGUAGE_NEW_LANGAUGE_LOKUS_BUILD_SRC_SYNTAX_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHARACTER_VALUE = 258,         /* CHARACTER_VALUE  */
    STRING_VALUE = 259,            /* STRING_VALUE  */
    INTEGER_VALUE = 260,           /* INTEGER_VALUE  */
    FLOAT_VALUE = 261,             /* FLOAT_VALUE  */
    TRUE_VALUE = 262,              /* TRUE_VALUE  */
    FALSE_VALUE = 263,             /* FALSE_VALUE  */
    IDENTIFIER = 264,              /* IDENTIFIER  */
    DATA_TYPE = 265,               /* DATA_TYPE  */
    EQ_OP = 266,                   /* EQ_OP  */
    COMP_OP = 267,                 /* COMP_OP  */
    ADD = 268,                     /* ADD  */
    SUB = 269,                     /* SUB  */
    MUL = 270,                     /* MUL  */
    DIV = 271,                     /* DIV  */
    EQ = 272,                      /* EQ  */
    LPAREN = 273,                  /* LPAREN  */
    RPAREN = 274,                  /* RPAREN  */
    LBRACE = 275,                  /* LBRACE  */
    RBRACE = 276,                  /* RBRACE  */
    COMMA = 277,                   /* COMMA  */
    DOT = 278,                     /* DOT  */
    PRINTING = 279,                /* PRINTING  */
    RETURN = 280,                  /* RETURN  */
    EXTERN = 281,                  /* EXTERN  */
    IF = 282,                      /* IF  */
    ELIF = 283,                    /* ELIF  */
    ELSE = 284,                    /* ELSE  */
    FOR = 285,                     /* FOR  */
    WHILE = 286                    /* WHILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "syntax.y"

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

#line 109 "/home/alfred/Code/Language/new_langauge/Lokus/build/src/syntax.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_ALFRED_CODE_LANGUAGE_NEW_LANGAUGE_LOKUS_BUILD_SRC_SYNTAX_HPP_INCLUDED  */