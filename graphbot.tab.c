/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     RW_MOVE = 258,
     RW_TURN = 259,
     RW_SETPOS = 260,
     RW_SETX = 261,
     RW_SETY = 262,
     RW_SETCOLOR = 263,
     RW_SETPENSIZE = 264,
     RW_SETBACKGROUND = 265,
     RW_SETBACKGROUNDTXT = 266,
     RW_SHOW = 267,
     RW_HIDE = 268,
     RW_CLEAN = 269,
     RW_HOME = 270,
     RW_GETCOLOR = 271,
     RW_GETPENSIZE = 272,
     RW_GETPOS = 273,
     RW_GETX = 274,
     RW_GETY = 275,
     RW_FUNCTION = 276,
     RW_SAVE = 277,
     RW_END = 278,
     RW_TRUE = 279,
     RW_FALSE = 280,
     RW_BOOLEAN = 281,
     RW_PLAYMUSIC = 282,
     RW_STOPMUSIC = 283,
     RW_CAMERAUP = 284,
     RW_CAMERADOWN = 285,
     RW_CAMERALEFT = 286,
     RW_CAMERARIGHT = 287,
     RW_PROGRAM = 288,
     RW_FOR = 289,
     RW_WHILE = 290,
     RW_IF = 291,
     RW_FLOAT = 292,
     OP_BRACKET = 293,
     CL_BRACKET = 294,
     OP_PAR = 295,
     CL_PAR = 296,
     COMMA = 297,
     EQUAL = 298,
     NOT_EQUAL = 299,
     GREAT_EQ_THAN = 300,
     LESS_EQ_THAN = 301,
     GREAT_THAN = 302,
     LESS_THAN = 303,
     BASIC_ARITHMETIC = 304,
     COM_ARITHMETIC = 305,
     ID = 306,
     FLOAT = 307
   };
#endif
/* Tokens.  */
#define RW_MOVE 258
#define RW_TURN 259
#define RW_SETPOS 260
#define RW_SETX 261
#define RW_SETY 262
#define RW_SETCOLOR 263
#define RW_SETPENSIZE 264
#define RW_SETBACKGROUND 265
#define RW_SETBACKGROUNDTXT 266
#define RW_SHOW 267
#define RW_HIDE 268
#define RW_CLEAN 269
#define RW_HOME 270
#define RW_GETCOLOR 271
#define RW_GETPENSIZE 272
#define RW_GETPOS 273
#define RW_GETX 274
#define RW_GETY 275
#define RW_FUNCTION 276
#define RW_SAVE 277
#define RW_END 278
#define RW_TRUE 279
#define RW_FALSE 280
#define RW_BOOLEAN 281
#define RW_PLAYMUSIC 282
#define RW_STOPMUSIC 283
#define RW_CAMERAUP 284
#define RW_CAMERADOWN 285
#define RW_CAMERALEFT 286
#define RW_CAMERARIGHT 287
#define RW_PROGRAM 288
#define RW_FOR 289
#define RW_WHILE 290
#define RW_IF 291
#define RW_FLOAT 292
#define OP_BRACKET 293
#define CL_BRACKET 294
#define OP_PAR 295
#define CL_PAR 296
#define COMMA 297
#define EQUAL 298
#define NOT_EQUAL 299
#define GREAT_EQ_THAN 300
#define LESS_EQ_THAN 301
#define GREAT_THAN 302
#define LESS_THAN 303
#define BASIC_ARITHMETIC 304
#define COM_ARITHMETIC 305
#define ID 306
#define FLOAT 307




/* Copy the first part of user declarations.  */
#line 1 "graphbot.y"

//Fernando Mendoza Ramírez
//A00515576
//Claudia Hernández Rivera
//A01033904

//Parser verificador de gramática correcta de graphbot

#include <cstdio>
#include <iostream>
#include <string>
#include "hashtable.h"
using namespace std;

data proc;
data var;
hasher dirproc;
hasher tablavar;
string var1;
int func = 1;


// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int yylineco;

void yyerror(const char *s);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 31 "graphbot.y"
{
	float fval;
	char *sval;
	char cval;
}
/* Line 193 of yacc.c.  */
#line 237 "graphbot.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 250 "graphbot.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    16,    17,    20,    23,
      26,    29,    32,    33,    35,    38,    41,    43,    45,    46,
      49,    54,    56,    58,    60,    62,    64,    67,    68,    71,
      73,    75,    77,    79,    81,    83,    85,    87,    89,    91,
      93,    96,    99,   102,   105,   108,   111,   114,   117,   120,
     123,   127,   131,   136,   141,   143,   145,   147,   151,   155,
     159,   163,   166,   169,   172,   173,   176,   178,   182,   186,
     188,   190,   192,   194,   196,   200,   202,   206,   210,   213,
     215,   217,   219,   221,   223,   225,   227,   229,   231,   233
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    64,    -1,    -1,    56,    55,    -1,
      21,    51,    57,    58,    23,    -1,    -1,    60,    57,    -1,
      65,    59,    -1,    73,    59,    -1,    74,    59,    -1,    75,
      59,    -1,    -1,    58,    -1,    61,    63,    -1,    62,    51,
      -1,    37,    -1,    26,    -1,    -1,    42,    61,    -1,    33,
      51,    58,    23,    -1,    68,    -1,    69,    -1,    70,    -1,
      71,    -1,    66,    -1,    51,    67,    -1,    -1,    79,    67,
      -1,    12,    -1,    13,    -1,    14,    -1,    15,    -1,    16,
      -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,    27,
      -1,    28,    -1,     3,    79,    -1,     4,    79,    -1,     6,
      79,    -1,     7,    79,    -1,     9,    79,    -1,    11,    79,
      -1,    29,    79,    -1,    30,    79,    -1,    31,    79,    -1,
      32,    79,    -1,     5,    79,    79,    -1,    22,    51,    72,
      -1,     8,    79,    79,    79,    -1,    10,    79,    79,    79,
      -1,    52,    -1,    79,    -1,    76,    -1,    34,    76,    76,
      -1,    35,    79,    76,    -1,    36,    79,    76,    -1,    38,
      77,    39,    -1,    52,    78,    -1,    79,    78,    -1,    65,
      78,    -1,    -1,    42,    77,    -1,    81,    -1,    81,    85,
      81,    -1,    80,    86,    80,    -1,    80,    -1,    24,    -1,
      25,    -1,    51,    -1,    82,    -1,    82,    49,    81,    -1,
      83,    -1,    83,    50,    83,    -1,    40,    79,    41,    -1,
      49,    84,    -1,    84,    -1,    51,    -1,    52,    -1,    43,
      -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,    48,
      -1,    43,    -1,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    97,    98,   102,   110,   111,   115,   116,
     117,   118,   121,   122,   127,   131,   146,   148,   151,   152,
     156,   164,   165,   166,   167,   168,   172,   175,   176,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     207,   208,   212,   213,   217,   218,   219,   223,   227,   231,
     235,   238,   239,   240,   243,   244,   248,   249,   250,   251,
     255,   256,   257,   261,   262,   266,   267,   271,   272,   273,
     277,   278,   282,   283,   284,   285,   286,   287,   291,   292
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RW_MOVE", "RW_TURN", "RW_SETPOS",
  "RW_SETX", "RW_SETY", "RW_SETCOLOR", "RW_SETPENSIZE", "RW_SETBACKGROUND",
  "RW_SETBACKGROUNDTXT", "RW_SHOW", "RW_HIDE", "RW_CLEAN", "RW_HOME",
  "RW_GETCOLOR", "RW_GETPENSIZE", "RW_GETPOS", "RW_GETX", "RW_GETY",
  "RW_FUNCTION", "RW_SAVE", "RW_END", "RW_TRUE", "RW_FALSE", "RW_BOOLEAN",
  "RW_PLAYMUSIC", "RW_STOPMUSIC", "RW_CAMERAUP", "RW_CAMERADOWN",
  "RW_CAMERALEFT", "RW_CAMERARIGHT", "RW_PROGRAM", "RW_FOR", "RW_WHILE",
  "RW_IF", "RW_FLOAT", "OP_BRACKET", "CL_BRACKET", "OP_PAR", "CL_PAR",
  "COMMA", "EQUAL", "NOT_EQUAL", "GREAT_EQ_THAN", "LESS_EQ_THAN",
  "GREAT_THAN", "LESS_THAN", "BASIC_ARITHMETIC", "COM_ARITHMETIC", "ID",
  "FLOAT", "$accept", "graphbot", "graph", "funcion", "funcion1",
  "funcion2", "funcion3", "param", "var", "var1", "var2", "programa",
  "comandos", "llamada_funcion", "llamada_funcion_aux", "comando",
  "comando1", "comando2", "comando3", "variable", "for", "while",
  "condicion", "lista", "lista1", "lista2", "expresion", "booleana", "exp",
  "termino", "factor", "varCte", "comparador", "comp_bool", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    57,    57,    58,    58,
      58,    58,    59,    59,    60,    61,    62,    62,    63,    63,
      64,    65,    65,    65,    65,    65,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    73,    74,    75,
      76,    77,    77,    77,    78,    78,    79,    79,    79,    79,
      80,    80,    80,    81,    81,    82,    82,    83,    83,    83,
      84,    84,    85,    85,    85,    85,    85,    85,    86,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     5,     0,     2,     2,     2,
       2,     2,     0,     1,     2,     2,     1,     1,     0,     2,
       4,     1,     1,     1,     1,     1,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     4,     4,     1,     1,     1,     3,     3,     3,
       3,     2,     2,     2,     0,     2,     1,     3,     3,     1,
       1,     1,     1,     1,     3,     1,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     3,     6,     1,     0,     2,     4,
      17,    16,     0,     6,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,    38,    39,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    12,    25,    21,
      22,    23,    24,    12,    12,    12,     7,     0,    14,    15,
       0,    70,    71,     0,     0,    72,    81,    40,    69,    66,
      73,    75,    79,    41,     0,    42,    43,     0,    44,     0,
      45,     0,    46,    47,    48,    49,     0,     0,     0,     0,
      26,    27,     5,    13,     8,     9,    10,    11,    19,    20,
       0,    80,    78,    88,    89,     0,    82,    83,    84,    85,
      86,    87,     0,     0,     0,    50,     0,     0,    54,    51,
      56,    55,    80,    81,    64,     0,    64,    57,    58,    59,
      28,    77,    72,    68,    67,    74,    76,    52,    53,     0,
      61,    63,    60,    62,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    12,    93,    94,    13,    14,    15,
      58,     8,    47,    48,    90,    49,    50,    51,    52,   119,
      53,    54,    55,    87,   125,   140,    91,    68,    69,    70,
      71,    72,   112,   105
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -107
static const yytype_int16 yypact[] =
{
     -10,    -6,    17,    25,   -10,    -7,  -107,     5,  -107,  -107,
    -107,  -107,   149,    -7,    24,    10,   149,    19,    19,    19,
      19,    19,    19,    19,    19,    19,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,    26,  -107,  -107,    19,    19,
      19,    19,    58,    19,    19,    19,    74,   149,  -107,  -107,
    -107,  -107,  -107,   149,   149,   149,  -107,    -7,  -107,  -107,
      75,  -107,  -107,    19,    21,    87,  -107,  -107,    31,    45,
      52,    70,  -107,  -107,    19,  -107,  -107,    19,  -107,    19,
    -107,    27,  -107,  -107,  -107,  -107,    99,    58,    58,    58,
    -107,    19,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
      84,  -107,  -107,  -107,  -107,    -9,  -107,  -107,  -107,  -107,
    -107,  -107,   -15,   -15,   -15,  -107,    19,    19,    37,  -107,
    -107,  -107,   -11,   -30,    94,   101,    94,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,    99,
    -107,  -107,  -107,  -107,  -107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,   134,  -107,   128,    23,    -5,  -107,    85,  -107,
    -107,  -107,   -76,  -107,    53,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,   -34,     4,  -106,   -17,    40,   -18,  -107,
      32,    83,  -107,  -107
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const yytype_int16 yytable[] =
{
      67,    73,    74,    75,    76,    77,    78,    79,    80,   -64,
     124,     1,   139,    61,    62,    61,    62,     6,   141,    10,
     143,    82,    83,    84,    85,    63,    88,    89,   -27,    63,
      11,   -27,   -72,   -72,    64,    46,   101,    66,    64,    60,
      65,    66,   132,    61,    62,     5,   100,   120,    95,    96,
      97,    61,    62,   127,   128,   129,    16,   115,     7,    63,
     116,    59,   117,   124,   121,    86,    57,    63,    64,   126,
      65,    66,   101,    66,   103,   104,    64,    81,    65,   118,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   106,   107,
     108,   109,   110,   111,   134,   135,    86,    92,    99,   137,
     138,   113,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     114,    35,   126,    61,    62,   131,    36,    37,    38,    39,
      40,    41,   -80,   -80,   -80,   -80,   139,   -80,     9,    63,
     142,    56,    98,   144,   130,   133,   136,   102,    64,     0,
     122,   123,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,    35,     0,     0,     0,     0,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45
};

static const yytype_int16 yycheck[] =
{
      17,    18,    19,    20,    21,    22,    23,    24,    25,    39,
      86,    21,    42,    24,    25,    24,    25,     0,   124,    26,
     126,    38,    39,    40,    41,    40,    43,    44,    39,    40,
      37,    42,    43,    44,    49,    12,    51,    52,    49,    16,
      51,    52,    51,    24,    25,    51,    63,    81,    53,    54,
      55,    24,    25,    87,    88,    89,    51,    74,    33,    40,
      77,    51,    79,   139,    81,    38,    42,    40,    49,    86,
      51,    52,    51,    52,    43,    44,    49,    51,    51,    52,
      43,    44,    45,    46,    47,    48,    49,    50,    43,    44,
      45,    46,    47,    48,   112,   113,    38,    23,    23,   116,
     117,    49,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      50,    22,   139,    24,    25,    41,    27,    28,    29,    30,
      31,    32,    45,    46,    47,    48,    42,    50,     4,    40,
      39,    13,    57,   139,    91,   105,   114,    64,    49,    -1,
      51,    52,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    54,    55,    56,    51,     0,    33,    64,    55,
      26,    37,    57,    60,    61,    62,    51,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    27,    28,    29,    30,
      31,    32,    34,    35,    36,    51,    58,    65,    66,    68,
      69,    70,    71,    73,    74,    75,    57,    42,    63,    51,
      58,    24,    25,    40,    49,    51,    52,    79,    80,    81,
      82,    83,    84,    79,    79,    79,    79,    79,    79,    79,
      79,    51,    79,    79,    79,    79,    38,    76,    79,    79,
      67,    79,    23,    58,    59,    59,    59,    59,    61,    23,
      79,    51,    84,    43,    44,    86,    43,    44,    45,    46,
      47,    48,    85,    49,    50,    79,    79,    79,    52,    72,
      76,    79,    51,    52,    65,    77,    79,    76,    76,    76,
      67,    41,    51,    80,    81,    81,    83,    79,    79,    42,
      78,    78,    39,    78,    77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 91 "graphbot.y"
    {cout<<"Matched GRAPHBOT"<<endl;
                    dirproc.output();
                    tablavar.output(); ;}
    break;

  case 5:
#line 102 "graphbot.y"
    {cout<<"Matched FUNCION"<<endl;
                                             proc.id = func;
                                             proc.value = 28;
                                             dirproc.add(proc);
                                             func++;
                                             ;}
    break;

  case 15:
#line 131 "graphbot.y"
    {cout<<"Matched VARIABLE_DE_FUNCION"<<endl;
               
              //  string nombre = $2;
                var.name = (yyvsp[(2) - (2)].sval);  
                cout << var.name << "aqui hay una variable" << endl; 
                if (var1.compare("float") == 0)
                var.type = 1;
                else
                var.type = 2;
                tablavar.add(var);

;}
    break;

  case 16:
#line 146 "graphbot.y"
    {cout<<"Matched RW_FLOAT"<<endl;
                    var1 =  (yyvsp[(1) - (1)].sval); ;}
    break;

  case 17:
#line 148 "graphbot.y"
    {cout<<"Matched RW_BOOLEAN"<<endl;
                    var1 = (yyvsp[(1) - (1)].sval);  ;}
    break;

  case 20:
#line 156 "graphbot.y"
    {cout<<"Matched PROGRAMA"<<endl;
                                   proc.id = func;
                                   proc.value = 28;
                                   dirproc.add(proc);
;}
    break;

  case 26:
#line 172 "graphbot.y"
    {cout<<"Matched FUNCION DEFINIDA POR EL USUARIO"<<endl;;}
    break;

  case 29:
#line 180 "graphbot.y"
    {cout<<"Matched RW_SHOW"<<endl;;}
    break;

  case 30:
#line 181 "graphbot.y"
    {cout<<"Matched RW_HIDE"<<endl;;}
    break;

  case 31:
#line 182 "graphbot.y"
    {cout<<"Matched RW_CLEAN"<<endl;;}
    break;

  case 32:
#line 183 "graphbot.y"
    {cout<<"Matched RW_HOME"<<endl;;}
    break;

  case 33:
#line 184 "graphbot.y"
    {cout<<"Matched RW_GETCOLOR"<<endl;;}
    break;

  case 34:
#line 185 "graphbot.y"
    {cout<<"Matched RW_GETPENSIZE"<<endl;;}
    break;

  case 35:
#line 186 "graphbot.y"
    {cout<<"Matched RW_GETPOS"<<endl;;}
    break;

  case 36:
#line 187 "graphbot.y"
    {cout<<"Matched GETX"<<endl;;}
    break;

  case 37:
#line 188 "graphbot.y"
    {cout<<"Matched GETY"<<endl;;}
    break;

  case 38:
#line 189 "graphbot.y"
    {cout<<"Matched RW_PLAYMUSIC"<<endl;;}
    break;

  case 39:
#line 190 "graphbot.y"
    {cout<<"Matched RW_STOPMUSIC"<<endl;;}
    break;

  case 40:
#line 194 "graphbot.y"
    {cout<<"Matched RW_MOVE"<<endl;;}
    break;

  case 41:
#line 195 "graphbot.y"
    {cout<<"Matched RW_TURN"<<endl;;}
    break;

  case 42:
#line 196 "graphbot.y"
    {cout<<"Matched RW_SETX"<<endl;;}
    break;

  case 43:
#line 197 "graphbot.y"
    {cout<<"Matched RW_SETY"<<endl;;}
    break;

  case 44:
#line 198 "graphbot.y"
    {cout<<"Matched RW_SETPENSIZE"<<endl;;}
    break;

  case 45:
#line 199 "graphbot.y"
    {cout<<"Matched RW_SETBACKGROUNDTXT"<<endl;;}
    break;

  case 46:
#line 200 "graphbot.y"
    {cout<<"Matched RW_CAMERAUP"<<endl;;}
    break;

  case 47:
#line 201 "graphbot.y"
    {cout<<"Matched RW_CAMERADOWN"<<endl;;}
    break;

  case 48:
#line 202 "graphbot.y"
    {cout<<"Matched RW_CAMERALEFT"<<endl;;}
    break;

  case 49:
#line 203 "graphbot.y"
    {cout<<"Matched RW_CAMERARIGHT"<<endl;;}
    break;

  case 50:
#line 207 "graphbot.y"
    {cout<<"Matched COMANDO2 via RW_SETPOS"<<endl;;}
    break;

  case 51:
#line 208 "graphbot.y"
    {cout<<"Matched COMANDO2 via RW_SAVE"<<endl;;}
    break;

  case 52:
#line 212 "graphbot.y"
    {cout<<"Matched RW_SETCOLOR"<<endl;;}
    break;

  case 53:
#line 213 "graphbot.y"
    {cout<<"Matched RW_SETBACKGROUND"<<endl;;}
    break;

  case 54:
#line 217 "graphbot.y"
    {cout<<"Matched SAVE_FLOAT"<<endl;;}
    break;

  case 55:
#line 218 "graphbot.y"
    {cout<<"Matched SAVE_EXPRESION"<<endl;;}
    break;

  case 56:
#line 219 "graphbot.y"
    {cout<<"Matched SAVE_LISTA"<<endl;;}
    break;

  case 57:
#line 223 "graphbot.y"
    {cout<<"Matched RW_FOR"<<endl;;}
    break;

  case 58:
#line 227 "graphbot.y"
    {cout<<"Matched RW_WHILE"<<endl;;}
    break;

  case 59:
#line 231 "graphbot.y"
    {cout<<"Matched RW_IF"<<endl;;}
    break;

  case 60:
#line 235 "graphbot.y"
    {cout<<"Matched LISTA"<<endl;;}
    break;

  case 66:
#line 248 "graphbot.y"
    {cout<<"Matched EXPRESION via EXP"<<endl;;}
    break;

  case 67:
#line 249 "graphbot.y"
    {cout<<"Matched EXPRESION via EXP COMPARADOR EXP"<<endl;;}
    break;

  case 68:
#line 250 "graphbot.y"
    {cout<<"Matched EXPRESION via COMPARACION BOOLEANA"<<endl;;}
    break;

  case 69:
#line 251 "graphbot.y"
    {cout<<"Matched EXPRESION via VALOR BOOLEANO"<<endl;;}
    break;

  case 70:
#line 255 "graphbot.y"
    {cout<<"Matched BOOLEANA via TRUE"<<endl;;}
    break;

  case 71:
#line 256 "graphbot.y"
    {cout<<"Matched BOOLEANA via FALSE"<<endl;;}
    break;

  case 72:
#line 257 "graphbot.y"
    {cout<<"Matched BOOLEANA via ID"<<endl;;}
    break;

  case 73:
#line 261 "graphbot.y"
    {cout<<"Matched <EXP> via <TERMINO>"<<endl;;}
    break;

  case 74:
#line 262 "graphbot.y"
    {cout<<"Matched EXP via TERMINO BASIC_ARITHMETIC TERMINO"<<endl;;}
    break;

  case 75:
#line 266 "graphbot.y"
    {cout<<"Matched <TERMINO> via <FACTOR>"<<endl;;}
    break;

  case 76:
#line 267 "graphbot.y"
    {cout<<"Matched <FACTOR> via <FACTOR> COM_ARITHMETIC <FACTOR>"<<endl;;}
    break;

  case 77:
#line 271 "graphbot.y"
    {cout<<"Matched FACTOR"<<endl;;}
    break;

  case 78:
#line 272 "graphbot.y"
    {cout<<"Matched <FACTOR> via BASIC_ARITHMETIC <varCte>"<<endl;;}
    break;

  case 79:
#line 273 "graphbot.y"
    {cout<<"Matched <FACTOR> via <varCte>"<<endl;;}
    break;

  case 80:
#line 277 "graphbot.y"
    {cout<<"Found ID: "<<(yyvsp[(1) - (1)].sval)<<endl;;}
    break;

  case 81:
#line 278 "graphbot.y"
    {printf("Found FLOAT: %f\n",(yyvsp[(1) - (1)].fval));;}
    break;

  case 82:
#line 282 "graphbot.y"
    {cout<<"Matched COMPARADOR via EQUAL"<<endl;;}
    break;

  case 83:
#line 283 "graphbot.y"
    {cout<<"Matched COMPARADOR via NOT_EQUAL"<<endl;;}
    break;

  case 84:
#line 284 "graphbot.y"
    {cout<<"Matched COMPARADOR via GREAT_EQ_THAN"<<endl;;}
    break;

  case 85:
#line 285 "graphbot.y"
    {cout<<"Matched COMPARADOR via LESS_EQ_THAN"<<endl;;}
    break;

  case 86:
#line 286 "graphbot.y"
    {cout<<"Matched COMPARADOR via GREAT_THAN"<<endl;;}
    break;

  case 87:
#line 287 "graphbot.y"
    {cout<<"Matched COMPARADOR via LESS_THAN"<<endl;;}
    break;

  case 88:
#line 291 "graphbot.y"
    {cout<<"Matched COMP_BOOL via EQUAL"<<endl;;}
    break;

  case 89:
#line 292 "graphbot.y"
    {cout<<"Matched COMP_BOOL via NOT_EQUAL"<<endl;;}
    break;


/* Line 1267 of yacc.c.  */
#line 1935 "graphbot.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 294 "graphbot.y"

int main(int argc, char ** argv) {
	
	// open a file handle to a particular file:
	FILE *myfile = fopen(argv[1], "r");
	// make sure it's valid:
	if (!myfile) {
		cout << "I can't open "<<argv[1]<< endl;
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// parse through the input until there is no more:
	do {
		yyparse();

	} while (!feof(yyin));
}

void yyerror(const char *s) {
	cout << "BANG, parse error! Message: "<<s<<" at line "<<yylineco<< endl;
	// might as well halt now:
	exit(-1);
}

