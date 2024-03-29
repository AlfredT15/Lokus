/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

  #include "/home/alfred/Code/Language/new_langauge/Lokus/include/node.hpp"
  #include <cstdio>
  #include <cstdlib>
  #include <vector>
	NBlock *programBlock; /* the top level root node of our final AST */

	#define YYERROR_VERBOSE 1
	#define YYDEBUG 1
	extern int yylex();
	extern int line_num;

  void yyerror(const char *s) { 
    std::printf("Error on line %d!  Message: %s \n", line_num, s);std::exit(1); }

#line 87 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "syntax.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHARACTER_VALUE = 3,            /* CHARACTER_VALUE  */
  YYSYMBOL_STRING_VALUE = 4,               /* STRING_VALUE  */
  YYSYMBOL_INTEGER_VALUE = 5,              /* INTEGER_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 6,                /* FLOAT_VALUE  */
  YYSYMBOL_TRUE_VALUE = 7,                 /* TRUE_VALUE  */
  YYSYMBOL_FALSE_VALUE = 8,                /* FALSE_VALUE  */
  YYSYMBOL_IDENTIFIER = 9,                 /* IDENTIFIER  */
  YYSYMBOL_DATA_TYPE = 10,                 /* DATA_TYPE  */
  YYSYMBOL_EQ_OP = 11,                     /* EQ_OP  */
  YYSYMBOL_COMP_OP = 12,                   /* COMP_OP  */
  YYSYMBOL_ADD = 13,                       /* ADD  */
  YYSYMBOL_SUB = 14,                       /* SUB  */
  YYSYMBOL_MUL = 15,                       /* MUL  */
  YYSYMBOL_DIV = 16,                       /* DIV  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_MOD = 19,                       /* MOD  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_LPAREN = 21,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 22,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 23,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 24,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 25,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 26,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 27,                     /* COMMA  */
  YYSYMBOL_DOT = 28,                       /* DOT  */
  YYSYMBOL_PRINT = 29,                     /* PRINT  */
  YYSYMBOL_RETURN = 30,                    /* RETURN  */
  YYSYMBOL_EXTERN = 31,                    /* EXTERN  */
  YYSYMBOL_LEN = 32,                       /* LEN  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_ELIF = 34,                      /* ELIF  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_FOR = 36,                       /* FOR  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_program = 39,                   /* program  */
  YYSYMBOL_stmts = 40,                     /* stmts  */
  YYSYMBOL_stmt = 41,                      /* stmt  */
  YYSYMBOL_block = 42,                     /* block  */
  YYSYMBOL_if_stmt = 43,                   /* if_stmt  */
  YYSYMBOL_elif_stmt = 44,                 /* elif_stmt  */
  YYSYMBOL_for_stmt = 45,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 46,                /* while_stmt  */
  YYSYMBOL_var_decl = 47,                  /* var_decl  */
  YYSYMBOL_extern_decl = 48,               /* extern_decl  */
  YYSYMBOL_func_decl = 49,                 /* func_decl  */
  YYSYMBOL_func_decl_args = 50,            /* func_decl_args  */
  YYSYMBOL_data_type_and_ident = 51,       /* data_type_and_ident  */
  YYSYMBOL_ident = 52,                     /* ident  */
  YYSYMBOL_numeric = 53,                   /* numeric  */
  YYSYMBOL_integer = 54,                   /* integer  */
  YYSYMBOL_float_val = 55,                 /* float_val  */
  YYSYMBOL_boolean = 56,                   /* boolean  */
  YYSYMBOL_list = 57,                      /* list  */
  YYSYMBOL_list_access = 58,               /* list_access  */
  YYSYMBOL_expr = 59,                      /* expr  */
  YYSYMBOL_op = 60,                        /* op  */
  YYSYMBOL_call_args = 61                  /* call_args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   421

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    73,    74,    79,    79,    79,    79,    79,
      79,    80,    81,    82,    83,    89,    90,    93,    94,    96,
      97,    98,   101,   102,   105,   108,   109,   112,   116,   120,
     121,   122,   125,   128,   131,   132,   135,   136,   139,   140,
     143,   144,   147,   148,   149,   152,   153,   154,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   182,
     183,   184
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CHARACTER_VALUE",
  "STRING_VALUE", "INTEGER_VALUE", "FLOAT_VALUE", "TRUE_VALUE",
  "FALSE_VALUE", "IDENTIFIER", "DATA_TYPE", "EQ_OP", "COMP_OP", "ADD",
  "SUB", "MUL", "DIV", "AND", "OR", "MOD", "EQ", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "COMMA", "DOT", "PRINT",
  "RETURN", "EXTERN", "LEN", "IF", "ELIF", "ELSE", "FOR", "WHILE",
  "$accept", "program", "stmts", "stmt", "block", "if_stmt", "elif_stmt",
  "for_stmt", "while_stmt", "var_decl", "extern_decl", "func_decl",
  "func_decl_args", "data_type_and_ident", "ident", "numeric", "integer",
  "float_val", "boolean", "list", "list_access", "expr", "op", "call_args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     161,   -43,   -43,   -43,   -43,   -43,   -43,    -2,    33,   224,
     224,     2,   224,    35,    12,   224,    30,   224,    20,   161,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,    27,     4,   -43,
     -43,   -43,   -43,   402,   -43,   -43,   -43,   342,    23,   402,
     224,   402,    32,   224,   329,    64,   329,   -43,   -43,   224,
      35,   224,   224,   195,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   224,   -43,   -43,   224,     0,    35,   354,
      93,    26,    28,    38,   246,   -43,   402,   -43,    -1,   402,
     402,     8,    36,    40,   297,   402,   402,   -43,   224,    10,
     -43,   -43,   127,   224,    39,   -43,   224,   224,    39,    35,
     -43,   224,   224,    47,   366,   -43,   -43,   329,   -43,   263,
     280,   -43,   -43,   402,   313,   224,   -43,    26,   224,   224,
     402,   -43,   378,   390,    39,    39,   -43,   -43
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    56,    36,    38,    40,    41,    33,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     8,     9,    10,     5,     7,     6,    25,    50,    53,
      34,    35,    54,    11,    32,    37,    39,     0,     0,    43,
       0,    12,     0,     0,     0,     0,     0,     1,     4,     0,
      29,     0,    69,    42,    61,    60,    67,    68,    64,    65,
      62,    63,    66,     0,    58,    55,     0,     0,    29,     0,
       0,    17,     0,    25,     0,    24,    26,    30,     0,    48,
      70,     0,     0,     0,    43,    57,    44,    13,     0,     0,
      59,    16,     0,     0,     0,    18,     0,     0,     0,     0,
      49,     0,     0,    51,     0,    27,    15,     0,    21,     0,
       0,    28,    31,    71,    44,     0,    14,    19,     0,     0,
      52,    20,     0,     0,     0,     0,    23,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,     6,   -17,   -42,   -43,   -37,   -43,   -43,   -40,
     -43,   -43,     9,    -4,   -43,   -43,   -43,   -43,   -43,    37,
     -43,    -9,   -43,   -43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    18,    19,    20,    71,    21,    95,    22,    23,    24,
      25,    26,    78,    27,    28,    29,    30,    31,    32,    38,
      83,    33,    63,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    39,    48,    41,    75,    72,    44,    34,    46,    42,
      77,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      47,    98,    87,    40,    51,    52,    99,    88,    77,    53,
     100,    67,   105,    43,    69,   101,    74,    99,    35,    36,
      76,    73,    79,    80,    84,     7,    73,    49,    50,    65,
      66,    45,   108,    68,    85,    96,   111,    86,    49,   112,
      93,    94,    70,   102,    73,   117,   103,   115,     1,     2,
       3,     4,     5,     6,     7,    48,    92,    89,     8,   104,
     121,     0,   126,   127,   107,     9,     0,   109,   110,    10,
      82,     0,   113,   114,     0,    73,    14,     1,     2,     3,
       4,     5,     6,     7,     0,     0,   120,     8,     0,   122,
     123,     0,     0,     0,     9,     0,     0,    91,    10,     0,
       0,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     1,     2,     3,     4,     5,     6,     7,     0,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     9,     0,
       0,   106,    10,     0,     0,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     1,     2,     3,     4,     5,
       6,     7,     0,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     9,     0,     0,     0,    10,     0,     0,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     9,     0,     0,     0,
      10,   -45,     0,     0,     0,     0,     0,    14,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,     9,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,    14,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
       0,     0,     0,    97,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,     0,
     118,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,   119,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,   -46,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,   -47,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,     0,    70,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,    64,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,    90,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,   116,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,     0,
     124,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,   125,    54,    55,    56,    57,    58,    59,    60,
      61,    62
};

static const yytype_int8 yycheck[] =
{
       9,    10,    19,    12,    46,    45,    15,     9,    17,    13,
      50,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    22,    22,    21,    20,    21,    27,    27,    68,    25,
      22,    40,    22,    21,    43,    27,    45,    27,     5,     6,
      49,    45,    51,    52,    53,    10,    50,    20,    21,    26,
      27,    21,    94,    21,    63,    27,    98,    66,    20,    99,
      34,    35,    23,    27,    68,   107,    26,    20,     4,     5,
       6,     7,     8,     9,    10,    92,    70,    68,    14,    88,
     117,    -1,   124,   125,    93,    21,    -1,    96,    97,    25,
      53,    -1,   101,   102,    -1,    99,    32,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,   115,    14,    -1,   118,
     119,    -1,    -1,    -1,    21,    -1,    -1,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,    36,
      37,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    -1,    -1,    36,    37,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    36,    37,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    32,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    23,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    22,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    22,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      22,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    22,    11,    12,    13,    14,    15,    16,    17,
      18,    19
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    14,    21,
      25,    29,    30,    31,    32,    33,    36,    37,    39,    40,
      41,    43,    45,    46,    47,    48,    49,    51,    52,    53,
      54,    55,    56,    59,     9,     5,     6,    59,    57,    59,
      21,    59,    51,    21,    59,    21,    59,     0,    41,    20,
      21,    20,    21,    25,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    60,    22,    26,    27,    59,    21,    59,
      23,    42,    47,    51,    59,    42,    59,    47,    50,    59,
      59,    61,    57,    58,    59,    59,    59,    22,    27,    50,
      22,    24,    40,    34,    35,    44,    27,    27,    22,    27,
      22,    27,    27,    26,    59,    22,    24,    59,    42,    59,
      59,    42,    47,    59,    59,    20,    22,    42,    27,    27,
      59,    44,    59,    59,    22,    22,    42,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    42,    42,    43,    43,    44,
      44,    44,    45,    45,    46,    47,    47,    48,    49,    50,
      50,    50,    51,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     6,     3,     2,     3,     4,     3,
       4,     2,     9,     9,     3,     1,     3,     5,     5,     0,
       1,     3,     2,     1,     1,     1,     1,     2,     1,     2,
       1,     1,     0,     1,     3,     0,     1,     3,     3,     4,
       1,     4,     6,     1,     1,     3,     1,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: stmts  */
#line 69 "syntax.y"
                { programBlock = (yyvsp[0].block); }
#line 1278 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 3: /* stmts: stmt  */
#line 73 "syntax.y"
             { (yyval.block) = new NBlock(); (yyval.block)->statements.push_back((yyvsp[0].stmt)); }
#line 1284 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 4: /* stmts: stmts stmt  */
#line 74 "syntax.y"
                       { (yyvsp[-1].block)->statements.push_back((yyvsp[0].stmt)); }
#line 1290 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 11: /* stmt: expr  */
#line 80 "syntax.y"
                { (yyval.stmt) = new NExpressionStatement(*(yyvsp[0].expr)); }
#line 1296 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 12: /* stmt: RETURN expr  */
#line 81 "syntax.y"
                       { (yyval.stmt) = new NReturnStatement((yyvsp[0].expr)); }
#line 1302 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 13: /* stmt: PRINT LPAREN expr RPAREN  */
#line 82 "syntax.y"
                                    { (yyval.stmt) = new NPrintStatement((yyvsp[-1].expr)); }
#line 1308 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 14: /* stmt: PRINT LPAREN expr COMMA expr RPAREN  */
#line 83 "syntax.y"
                                               { (yyval.stmt) = new NPrintStatement((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1314 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 15: /* block: LBRACE stmts RBRACE  */
#line 89 "syntax.y"
                            { (yyval.block) = (yyvsp[-1].block); }
#line 1320 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 16: /* block: LBRACE RBRACE  */
#line 90 "syntax.y"
                          { (yyval.block) = new NBlock(); }
#line 1326 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 17: /* if_stmt: IF expr block  */
#line 93 "syntax.y"
                        { (yyval.stmt) = new NIfStatement((yyvsp[-1].expr), *(yyvsp[0].block)); }
#line 1332 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 18: /* if_stmt: IF expr block elif_stmt  */
#line 94 "syntax.y"
                                          { (yyval.stmt) = new NIfStatement((yyvsp[-2].expr), *(yyvsp[-1].block), (yyvsp[0].stmt)); }
#line 1338 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 19: /* elif_stmt: ELIF expr block  */
#line 96 "syntax.y"
                            { (yyval.stmt) = new NIfStatement((yyvsp[-1].expr), *(yyvsp[0].block)); }
#line 1344 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 20: /* elif_stmt: ELIF expr block elif_stmt  */
#line 97 "syntax.y"
                                              { (yyval.stmt) = new NIfStatement((yyvsp[-2].expr), *(yyvsp[-1].block), (yyvsp[0].stmt)); }
#line 1350 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 21: /* elif_stmt: ELSE block  */
#line 98 "syntax.y"
                                { (yyval.stmt) = new NIfStatement(*(yyvsp[0].block)); }
#line 1356 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 22: /* for_stmt: FOR LPAREN expr COMMA expr COMMA expr RPAREN block  */
#line 101 "syntax.y"
                                                              { (yyval.stmt) = new NForStatement((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), *(yyvsp[0].block)); }
#line 1362 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 23: /* for_stmt: FOR LPAREN var_decl COMMA expr COMMA expr RPAREN block  */
#line 102 "syntax.y"
                                                                          { (yyval.stmt) = new NForStatement((yyvsp[-6].stmt), (yyvsp[-4].expr), (yyvsp[-2].expr), *(yyvsp[0].block)); }
#line 1368 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 24: /* while_stmt: WHILE expr block  */
#line 105 "syntax.y"
                              { (yyval.stmt) = new NWhileStatement((yyvsp[-1].expr), *(yyvsp[0].block)); }
#line 1374 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 25: /* var_decl: data_type_and_ident  */
#line 108 "syntax.y"
                               { (yyval.stmt) = new NVariableDeclaration(*(yyvsp[0].ident)); }
#line 1380 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 26: /* var_decl: data_type_and_ident EQ expr  */
#line 109 "syntax.y"
                                               { (yyval.stmt) = new NVariableDeclaration(*(yyvsp[-2].ident), (yyvsp[0].expr)); }
#line 1386 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 27: /* extern_decl: EXTERN data_type_and_ident LPAREN func_decl_args RPAREN  */
#line 113 "syntax.y"
                { (yyval.stmt) = new NExternDeclaration(*(yyvsp[-3].ident),*(yyvsp[-1].varvec)); delete (yyvsp[-1].varvec);}
#line 1392 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 28: /* func_decl: data_type_and_ident LPAREN func_decl_args RPAREN block  */
#line 117 "syntax.y"
                        { (yyval.stmt) = new NFunctionDeclaration(*(yyvsp[-4].ident), *(yyvsp[-2].varvec), *(yyvsp[0].block)); delete (yyvsp[-2].varvec); }
#line 1398 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 29: /* func_decl_args: %empty  */
#line 120 "syntax.y"
                            { (yyval.varvec) = new VariableList(); }
#line 1404 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 30: /* func_decl_args: var_decl  */
#line 121 "syntax.y"
                             { (yyval.varvec) = new VariableList(); (yyval.varvec)->push_back((yyvsp[0].var_decl)); }
#line 1410 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 31: /* func_decl_args: func_decl_args COMMA var_decl  */
#line 122 "syntax.y"
                                                  { (yyvsp[-2].varvec)->push_back((yyvsp[0].var_decl)); }
#line 1416 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 32: /* data_type_and_ident: DATA_TYPE IDENTIFIER  */
#line 125 "syntax.y"
                                           { (yyval.ident) = new NIdentifier(*(yyvsp[-1].string), *(yyvsp[0].string)); delete (yyvsp[-1].string); delete (yyvsp[0].string);}
#line 1422 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 33: /* ident: IDENTIFIER  */
#line 128 "syntax.y"
                   { (yyval.ident) = new NIdentifier(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1428 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 36: /* integer: INTEGER_VALUE  */
#line 135 "syntax.y"
                        { (yyval.expr) = new NInteger(atol((yyvsp[0].string)->c_str())); delete (yyvsp[0].string); }
#line 1434 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 37: /* integer: SUB INTEGER_VALUE  */
#line 136 "syntax.y"
                                    { (yyval.expr) = new NInteger(-atol((yyvsp[0].string)->c_str())); delete (yyvsp[-1].string); }
#line 1440 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 38: /* float_val: FLOAT_VALUE  */
#line 139 "syntax.y"
                        { (yyval.expr) = new NDouble(atof((yyvsp[0].string)->c_str())); delete (yyvsp[0].string); }
#line 1446 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 39: /* float_val: SUB FLOAT_VALUE  */
#line 140 "syntax.y"
                                    { (yyval.expr) = new NDouble(-atof((yyvsp[0].string)->c_str())); delete (yyvsp[-1].string); }
#line 1452 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 40: /* boolean: TRUE_VALUE  */
#line 143 "syntax.y"
                     { (yyval.expr) = new NBool((yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }
#line 1458 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 41: /* boolean: FALSE_VALUE  */
#line 144 "syntax.y"
                              { (yyval.expr) = new NBool((yyvsp[0].string)->c_str()); delete (yyvsp[0].string); }
#line 1464 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 42: /* list: %empty  */
#line 147 "syntax.y"
                  { (yyval.exprvec) = new ExpressionList(); }
#line 1470 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 43: /* list: expr  */
#line 148 "syntax.y"
                { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yyvsp[0].expr)); }
#line 1476 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 44: /* list: list COMMA expr  */
#line 149 "syntax.y"
                            { (yyvsp[-2].exprvec)->push_back((yyvsp[0].expr)); }
#line 1482 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 45: /* list_access: %empty  */
#line 152 "syntax.y"
                         { (yyval.exprvec) = new ExpressionList(); }
#line 1488 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 46: /* list_access: expr  */
#line 153 "syntax.y"
                               { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yyvsp[0].expr)); }
#line 1494 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 47: /* list_access: list COMMA expr  */
#line 154 "syntax.y"
                                           { (yyvsp[-2].exprvec)->push_back((yyvsp[0].expr)); }
#line 1500 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 48: /* expr: ident EQ expr  */
#line 157 "syntax.y"
                     { (yyval.expr) = new NAssignment(*(yyvsp[-2].ident), *(yyvsp[0].expr)); }
#line 1506 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 49: /* expr: ident LPAREN call_args RPAREN  */
#line 158 "syntax.y"
                                         { (yyval.expr) = new NMethodCall(*(yyvsp[-3].ident), *(yyvsp[-1].exprvec)); delete (yyvsp[-1].exprvec); }
#line 1512 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 50: /* expr: ident  */
#line 159 "syntax.y"
                 { (yyval.ident) = (yyvsp[0].ident); }
#line 1518 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 51: /* expr: ident LBRACKET list_access RBRACKET  */
#line 160 "syntax.y"
                                               { (yyval.expr) = new NListAccess(*(yyvsp[-3].ident), *(yyvsp[-1].exprvec)); delete (yyvsp[-1].exprvec); }
#line 1524 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 52: /* expr: ident LBRACKET list_access RBRACKET EQ expr  */
#line 161 "syntax.y"
                                                       { (yyval.expr) = new NListAssignment(*(yyvsp[-5].ident), *(yyvsp[-3].exprvec), *(yyvsp[0].expr)); delete (yyvsp[-3].exprvec); }
#line 1530 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 55: /* expr: LBRACKET list RBRACKET  */
#line 164 "syntax.y"
                                  { (yyval.expr) = new NList(*(yyvsp[-1].exprvec)); delete (yyvsp[-1].exprvec); }
#line 1536 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 56: /* expr: STRING_VALUE  */
#line 165 "syntax.y"
                        { (yyval.expr) = new NString((yyvsp[0].string)->c_str()); delete (yyvsp[0].string);}
#line 1542 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 57: /* expr: expr op expr  */
#line 166 "syntax.y"
                        { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), *(yyvsp[-1].op), *(yyvsp[0].expr)); }
#line 1548 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 58: /* expr: LPAREN expr RPAREN  */
#line 167 "syntax.y"
                              { (yyval.expr) = (yyvsp[-1].expr); }
#line 1554 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 59: /* expr: LEN LPAREN expr RPAREN  */
#line 168 "syntax.y"
                                  { (yyval.expr) = new NLength((yyvsp[-1].expr)); }
#line 1560 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 60: /* op: COMP_OP  */
#line 171 "syntax.y"
            { (yyval.op) = new NOperator(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1566 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 61: /* op: EQ_OP  */
#line 172 "syntax.y"
                { (yyval.op) = new NOperator(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1572 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 62: /* op: AND  */
#line 173 "syntax.y"
                { (yyval.op) = new NOperator(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1578 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 63: /* op: OR  */
#line 174 "syntax.y"
                { (yyval.op) = new NOperator(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1584 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 64: /* op: MUL  */
#line 175 "syntax.y"
                { (yyval.op) = new NOperator(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1590 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 65: /* op: DIV  */
#line 176 "syntax.y"
                { (yyval.op) = new NOperator(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1596 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 66: /* op: MOD  */
#line 177 "syntax.y"
                { (yyval.op) = new NOperator(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1602 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 67: /* op: ADD  */
#line 178 "syntax.y"
                { (yyval.op) = new NOperator(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1608 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 68: /* op: SUB  */
#line 179 "syntax.y"
                { (yyval.op) = new NOperator(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1614 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 69: /* call_args: %empty  */
#line 182 "syntax.y"
                       { (yyval.exprvec) = new ExpressionList(); }
#line 1620 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 70: /* call_args: expr  */
#line 183 "syntax.y"
                         { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yyvsp[0].expr)); }
#line 1626 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;

  case 71: /* call_args: call_args COMMA expr  */
#line 184 "syntax.y"
                                          { (yyvsp[-2].exprvec)->push_back((yyvsp[0].expr)); }
#line 1632 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"
    break;


#line 1636 "/home/alfred/Code/Language/new_langauge/Lokus/src/syntax.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 187 "syntax.y"
