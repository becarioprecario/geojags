/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:339  */

#include <compiler/ParseTree.h>
#include "remap.h"
#include "parser_extra.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>

using std::malloc;
using std::free;
using jags::ParseTree;

  void yyerror(const char *);
  int yylex();
  int yylex_destroy();
  extern int yylineno;
  
#define YYDEBUG 1
  
  static std::vector<ParseTree *> * _pvariables = 0;
  static ParseTree *_pdata = 0;
  static ParseTree *_prelations = 0;
  
  static void setName(ParseTree *p, std::string *name);
  static void setParameters(ParseTree *p, std::vector<ParseTree*> *parameters);
  static void setParameters(ParseTree *p, ParseTree *param1);
  static void setParameters(ParseTree *p, ParseTree *param1, 
			    ParseTree *param2);
  static void setParameters(ParseTree *p, ParseTree *param1, ParseTree *param2,
			    ParseTree *param3);
  static ParseTree *Truncated (ParseTree *left, ParseTree *right);
  static ParseTree *Interval(ParseTree *left, ParseTree *right);
  

#line 105 "parser.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_PARSER_HH_INCLUDED
# define YY_YY_PARSER_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    DATA = 259,
    MODEL = 260,
    NAME = 261,
    FUNC = 262,
    SPECIAL = 263,
    BADCHAR = 264,
    IN = 265,
    ARROW = 266,
    FOR = 267,
    GT = 268,
    GE = 269,
    LT = 270,
    LE = 271,
    EQ = 272,
    NE = 273,
    AND = 274,
    OR = 275,
    LENGTH = 276,
    DIM = 277,
    DOUBLE = 278,
    INT = 279,
    NOT = 280,
    NEG = 281,
    ENDL = 282,
    UREPCHAR = 283
  };
#endif
/* Tokens.  */
#define VAR 258
#define DATA 259
#define MODEL 260
#define NAME 261
#define FUNC 262
#define SPECIAL 263
#define BADCHAR 264
#define IN 265
#define ARROW 266
#define FOR 267
#define GT 268
#define GE 269
#define LT 270
#define LE 271
#define EQ 272
#define NE 273
#define AND 274
#define OR 275
#define LENGTH 276
#define DIM 277
#define DOUBLE 278
#define INT 279
#define NOT 280
#define NEG 281
#define ENDL 282
#define UREPCHAR 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:355  */

  /*
    We can't put any C++ class that requires a constructor in
    union. In particular, we can't have strings.  To get round this
    limitation, we put a pointer to a string in the union, and then
    get the lexical analyzer to return a pointer to a dynamically
    allocated string.  The parser frees the memory when it is done.
    This is tedious, but the alternative is to copy character
    arrays using, e.g. strncpy instead.
  */
  double val;
  std::string *stringptr;
  jags::ParseTree *ptree;
  std::vector<jags::ParseTree*> *pvec;

#line 217 "parser.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 234 "parser.cc" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   477

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,    28,    26,    36,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    30,    35,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    45,     2,     2,     2,     2,     2,
       2,    37,     2,    38,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,    44,     2,     2,     2,
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
      25,    31,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   106,   107,   108,   109,   112,   113,   116,
     117,   120,   123,   129,   130,   133,   140,   147,   153,   154,
     157,   158,   159,   160,   161,   164,   170,   176,   177,   180,
     184,   200,   204,   208,   214,   219,   229,   234,   243,   244,
     245,   249,   253,   257,   261,   265,   269,   273,   277,   281,
     285,   289,   293,   297,   301,   305,   309,   313,   317,   321,
     324,   325,   328,   329,   332,   333,   339,   344,   354,   355,
     356,   357,   360,   361,   362,   363,   366,   369
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "DATA", "MODEL", "NAME", "FUNC",
  "SPECIAL", "BADCHAR", "IN", "ARROW", "FOR", "GT", "GE", "LT", "LE", "EQ",
  "NE", "AND", "OR", "LENGTH", "DIM", "DOUBLE", "INT", "NOT", "'+'", "'-'",
  "'*'", "'/'", "':'", "NEG", "'^'", "ENDL", "UREPCHAR", "';'", "','",
  "'['", "']'", "'{'", "'}'", "'('", "')'", "'='", "'~'", "'T'", "'I'",
  "$accept", "input", "var_stmt", "dec_list", "node_dec", "dim_list",
  "data_stmt", "model_stmt", "relations", "relation_list", "relation",
  "for_loop", "counter", "assignment", "determ_relation", "stoch_relation",
  "product", "sum", "expression", "expression_list", "range_list",
  "range_element", "distribution", "truncated", "interval", "var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    43,    45,    42,    47,
      58,   281,    94,   282,   283,    59,    44,    91,    93,   123,
     125,    40,    41,    61,   126,    84,    73
};
# endif

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,    -4,   -26,   -21,    21,    78,    39,  -109,    42,   139,
    -109,   149,   149,  -109,    39,  -109,  -109,   160,  -109,    -4,
      63,    -8,    35,     5,  -109,  -109,    65,    76,    92,    -7,
      28,  -109,    79,    91,    96,  -109,   160,   160,   -22,   120,
     114,   376,  -109,  -109,   160,   156,   163,  -109,  -109,   149,
    -109,  -109,  -109,  -109,  -109,   164,   160,  -109,   160,   156,
     156,   141,   176,   160,  -109,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   376,    85,  -109,   134,   170,    86,   144,   133,
     376,   376,    33,   155,   157,  -109,   376,   117,    -3,   106,
     422,   422,   422,   422,   422,   422,   445,   399,    -3,    -3,
     117,   117,   138,   141,   160,  -109,     4,   160,  -109,     1,
     145,   147,  -109,  -109,   160,  -109,  -109,  -109,  -109,   160,
     158,  -109,    36,    74,   136,   376,   376,  -109,  -109,    64,
     326,    67,   351,  -109,   206,   112,  -109,   236,   123,  -109,
    -109,   266,  -109,  -109,   296,  -109,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     3,    11,     7,
       9,     0,     0,     1,     0,     4,     5,     0,     8,     0,
      76,     0,     0,     0,    18,    22,     0,    21,    20,     0,
       0,     6,     0,     0,     0,    39,     0,     0,     0,    43,
      45,    13,    38,    10,    64,     0,     0,    15,    19,     0,
      25,    24,    23,    27,    28,     0,     0,    16,     0,     0,
       0,    47,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,     0,    62,     0,     0,     0,     0,    31,
      29,    60,     0,     0,     0,    59,    14,    35,    37,    58,
      49,    50,    51,    52,    53,    54,    55,    56,    36,    46,
      34,    44,    48,    57,    64,    77,     0,    64,    17,     0,
       0,     0,    32,    33,     0,    42,    40,    41,    63,     0,
       0,    67,     0,     0,     0,    61,    30,    26,    66,     0,
       0,     0,     0,    71,     0,     0,    75,     0,     0,    69,
      70,     0,    73,    74,     0,    68,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,  -109,   179,  -109,   202,   146,  -109,   -11,
     -20,  -109,  -109,    93,  -109,  -109,  -109,  -109,   -17,    94,
    -109,  -108,  -109,  -109,  -109,    54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     9,    10,    38,     6,     7,    50,    23,
      24,    25,    26,    56,    27,    28,    39,    40,    82,    92,
      83,    84,    89,   122,   123,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    30,     8,    48,    53,    67,   128,    20,    32,   130,
      48,    20,    21,    11,    63,    53,    64,    22,    12,    61,
      62,    13,    33,    34,    35,    78,    79,    80,    36,    81,
       1,     2,     3,    45,    20,    21,    54,    55,    87,    90,
      22,    91,    37,   131,     3,    47,    96,    54,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    29,    29,    48,    57,   124,
      20,    32,   124,    20,    32,   125,    46,    29,   138,    17,
      20,    32,     2,     3,    29,    33,    34,    35,    33,    34,
      35,    36,    20,    21,    36,    33,    34,    35,    22,    85,
      44,    36,    91,    29,    49,    37,   143,   135,    37,   146,
     139,    51,   136,    93,    94,    37,   140,   142,    20,    32,
      58,   114,   144,   115,   147,    67,   118,    52,   151,    20,
      32,   154,    59,    33,    34,    35,    80,    60,    81,    36,
      66,    29,    20,    32,    33,    34,    35,    80,    65,    81,
      36,    15,    16,    37,   150,    20,    21,    33,    34,    35,
      31,    22,    20,    36,    37,   153,    20,    32,    -1,    86,
      81,    88,   141,    81,    18,    19,   116,    37,   120,   121,
     117,    33,    34,    35,    67,   119,   133,    36,   134,    68,
      69,    70,    71,    72,    73,    74,    75,   126,    43,   127,
     137,    37,    76,    77,    78,    79,    80,    14,    81,   129,
       0,     0,     0,   132,    67,     0,     0,     0,    95,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,     0,    81,     0,
       0,     0,     0,     0,    67,     0,     0,     0,   149,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,     0,    81,     0,
       0,     0,     0,     0,    67,     0,     0,     0,   152,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,     0,    81,     0,
       0,     0,     0,     0,    67,     0,     0,     0,   155,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,     0,    81,     0,
       0,     0,     0,     0,    67,     0,     0,     0,   156,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,     0,    81,    67,
       0,     0,   145,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,     0,    81,    67,     0,     0,   148,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    67,    81,     0,
       0,     0,    68,    69,    70,    71,    72,    73,    74,     0,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      67,    81,     0,     0,     0,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     0,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    67,    81,     0,     0,     0,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,     0,    81
};

static const yytype_int16 yycheck[] =
{
      17,    12,     6,    23,    11,     8,   114,     6,     7,   117,
      30,     6,     7,    39,    36,    11,    38,    12,    39,    36,
      37,     0,    21,    22,    23,    28,    29,    30,    27,    32,
       3,     4,     5,    41,     6,     7,    43,    44,    49,    56,
      12,    58,    41,    42,     5,    40,    63,    43,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    11,    12,    87,    40,    36,
       6,     7,    36,     6,     7,    42,    41,    23,    42,    37,
       6,     7,     4,     5,    30,    21,    22,    23,    21,    22,
      23,    27,     6,     7,    27,    21,    22,    23,    12,    45,
      37,    27,   119,    49,    39,    41,    42,   124,    41,    42,
      36,    35,   129,    59,    60,    41,   133,   134,     6,     7,
      41,    36,   139,    38,   141,     8,    40,    35,   145,     6,
       7,   148,    41,    21,    22,    23,    30,    41,    32,    27,
      26,    87,     6,     7,    21,    22,    23,    30,    28,    32,
      27,     5,     6,    41,    42,     6,     7,    21,    22,    23,
      14,    12,     6,    27,    41,    42,     6,     7,    30,     6,
      32,     7,    36,    32,    35,    36,    42,    41,    45,    46,
      10,    21,    22,    23,     8,    41,    41,    27,    41,    13,
      14,    15,    16,    17,    18,    19,    20,    42,    19,    42,
      42,    41,    26,    27,    28,    29,    30,     5,    32,   116,
      -1,    -1,    -1,   119,     8,    -1,    -1,    -1,    42,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    42,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    42,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    42,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    42,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    -1,    32,     8,
      -1,    -1,    36,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    -1,    32,     8,    -1,    -1,    36,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,     8,    32,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
       8,    32,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,     8,    32,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    48,    49,    53,    54,     6,    50,
      51,    39,    39,     0,    53,    54,    54,    37,    35,    36,
       6,     7,    12,    56,    57,    58,    59,    61,    62,    72,
      56,    54,     7,    21,    22,    23,    27,    41,    52,    63,
      64,    65,    72,    51,    37,    41,    41,    40,    57,    39,
      55,    35,    35,    11,    43,    44,    60,    40,    41,    41,
      41,    65,    65,    36,    38,    28,    26,     8,    13,    14,
      15,    16,    17,    18,    19,    20,    26,    27,    28,    29,
      30,    32,    65,    67,    68,    72,     6,    56,     7,    69,
      65,    65,    66,    72,    72,    42,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    36,    38,    42,    10,    40,    41,
      45,    46,    70,    71,    36,    42,    42,    42,    68,    60,
      68,    42,    66,    41,    41,    65,    65,    42,    42,    36,
      65,    36,    65,    42,    65,    36,    42,    65,    36,    42,
      42,    65,    42,    42,    65,    42,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    54,    55,    56,    56,
      57,    57,    57,    57,    57,    58,    59,    60,    60,    61,
      61,    62,    62,    62,    63,    63,    64,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    71,    71,    71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     2,     3,     2,     3,     1,
       3,     1,     4,     1,     3,     4,     4,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     6,     1,     1,     3,
       6,     3,     4,     4,     3,     3,     3,     3,     1,     1,
       4,     4,     4,     1,     3,     1,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     3,     0,     1,     4,     3,     6,     5,
       5,     4,     6,     5,     5,     4,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 7:
#line 112 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { _pvariables = (yyvsp[0].pvec); }
#line 1478 "parser.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { _pvariables = (yyvsp[-1].pvec); }
#line 1484 "parser.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 116 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[0].ptree)); }
#line 1490 "parser.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 117 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { (yyval.pvec) = (yyvsp[-2].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree)); }
#line 1496 "parser.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 120 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_VAR, yylineno); setName((yyval.ptree), (yyvsp[0].stringptr)); 
}
#line 1504 "parser.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 123 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_VAR, yylineno); setName((yyval.ptree), (yyvsp[-3].stringptr));
    setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 1513 "parser.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 129 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[0].ptree)); }
#line 1519 "parser.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 130 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { (yyval.pvec)=(yyvsp[-2].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree)); }
#line 1525 "parser.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 133 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    ParseTree *p = new ParseTree(jags::P_RELATIONS, yylineno);
    setParameters(p, (yyvsp[-1].pvec));
    _pdata = p;
}
#line 1535 "parser.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 140 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { 
    ParseTree *p = new ParseTree(jags::P_RELATIONS, yylineno);
    setParameters(p, (yyvsp[-1].pvec));
    _prelations = p;
}
#line 1545 "parser.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 147 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_RELATIONS, yylineno);
    setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 1554 "parser.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 153 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[0].ptree)); }
#line 1560 "parser.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 154 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { (yyval.pvec)=(yyvsp[-1].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree)); }
#line 1566 "parser.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 164 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FOR, yylineno);
    setParameters((yyval.ptree), (yyvsp[-1].ptree), (yyvsp[0].ptree));
}
#line 1575 "parser.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 170 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_COUNTER, yylineno); setName((yyval.ptree), (yyvsp[-3].stringptr));
    setParameters((yyval.ptree), (yyvsp[-1].ptree));
}
#line 1584 "parser.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 180 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_DETRMREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1593 "parser.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 184 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {

  /* 
     The link function is given using an S-style replacement function
     notation.  We need to turn this round so the inverse link
     function is applied to the RHS of the deterministic relation
  */
     
    ParseTree *p = new ParseTree(jags::P_LINK, yylineno); setName(p, (yyvsp[-5].stringptr));
    setParameters(p, (yyvsp[0].ptree));
    
    (yyval.ptree) = new ParseTree(jags::P_DETRMREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[-3].ptree), p);
}
#line 1612 "parser.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 200 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_STOCHREL, yylineno); 
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1621 "parser.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 204 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_STOCHREL, yylineno); 
    setParameters((yyval.ptree), (yyvsp[-3].ptree), (yyvsp[-1].ptree), (yyvsp[0].ptree));
}
#line 1630 "parser.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 208 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_STOCHREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[-3].ptree), (yyvsp[-1].ptree), (yyvsp[0].ptree));
}
#line 1639 "parser.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 214 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
  (yyval.pvec) = new std::vector<ParseTree*>;
  (yyval.pvec)->push_back((yyvsp[-2].ptree));
  (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 1649 "parser.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 219 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
  //  This creates a shift-reduce conflict because in the expression
  //  A*B*C, (A*B) is a valid expression. By default, bison shifts,
  //  which is what we want. The warning is suppressed with the %expect
  //  declaration (See also sum: below).
  (yyval.pvec) = (yyvsp[-2].pvec);
  (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 1662 "parser.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 229 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
  (yyval.pvec) = new std::vector<ParseTree*>;
  (yyval.pvec)->push_back((yyvsp[-2].ptree));
  (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 1672 "parser.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 234 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
  //  This creates a shift-reduce conflict. By default, bison shifts,
  //  which is what we want. The warning is suppressed with the %expect
  //  declaration (See also product: above).
  (yyval.pvec) = (yyvsp[-2].pvec);
  (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 1684 "parser.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 244 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = new ParseTree(jags::P_VALUE, yylineno); (yyval.ptree)->setValue((yyvsp[0].val));}
#line 1690 "parser.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 245 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_LENGTH, yylineno);
    setParameters((yyval.ptree),(yyvsp[-1].ptree));
}
#line 1699 "parser.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 249 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_DIM, yylineno);
    setParameters((yyval.ptree),(yyvsp[-1].ptree));
}
#line 1708 "parser.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 253 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); setName((yyval.ptree), (yyvsp[-3].stringptr));
  setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 1717 "parser.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 257 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("*");
    setParameters((yyval.ptree), (yyvsp[0].pvec));
}
#line 1726 "parser.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 261 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("/");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1735 "parser.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 265 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("+");
    setParameters((yyval.ptree), (yyvsp[0].pvec));
}
#line 1744 "parser.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 269 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("-");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1753 "parser.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 273 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("NEG");
    setParameters((yyval.ptree), (yyvsp[0].ptree));
}
#line 1762 "parser.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 277 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName(":");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1771 "parser.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 281 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName(">");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1780 "parser.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 285 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName(">=");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1789 "parser.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 289 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("<");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1798 "parser.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 293 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("<=");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1807 "parser.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 297 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("==");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1816 "parser.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 301 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("!=");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1825 "parser.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 305 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("&&");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1834 "parser.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 309 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("||");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1843 "parser.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 313 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("^");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
  }
#line 1852 "parser.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 317 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); setName((yyval.ptree), (yyvsp[-1].stringptr));
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1861 "parser.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 321 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { (yyval.ptree) = (yyvsp[-1].ptree); }
#line 1867 "parser.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 324 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[0].ptree)); }
#line 1873 "parser.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 325 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { (yyval.pvec)=(yyvsp[-2].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree)); }
#line 1879 "parser.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 328 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[0].ptree)); }
#line 1885 "parser.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 329 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    { (yyval.pvec)=(yyvsp[-2].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree)); }
#line 1891 "parser.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 332 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = new ParseTree(jags::P_RANGE, yylineno);}
#line 1897 "parser.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 333 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new ParseTree(jags::P_RANGE, yylineno); 
    setParameters((yyval.ptree),(yyvsp[0].ptree));
}
#line 1906 "parser.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 340 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = new ParseTree(jags::P_DENSITY, yylineno); setName((yyval.ptree), (yyvsp[-3].stringptr));
  setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 1915 "parser.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 345 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
    //BUGS has a dflat() distribution with no parameters
    (yyval.ptree) = new ParseTree(jags::P_DENSITY, yylineno); setName((yyval.ptree), (yyvsp[-2].stringptr));
}
#line 1924 "parser.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 354 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = Truncated((yyvsp[-3].ptree),(yyvsp[-1].ptree));}
#line 1930 "parser.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 355 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = Truncated(0,(yyvsp[-1].ptree));}
#line 1936 "parser.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 356 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = Truncated((yyvsp[-2].ptree),0);}
#line 1942 "parser.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 357 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = Truncated(0,0);}
#line 1948 "parser.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 360 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = Interval((yyvsp[-3].ptree),(yyvsp[-1].ptree));}
#line 1954 "parser.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 361 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = Interval(0,(yyvsp[-1].ptree));}
#line 1960 "parser.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 362 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = Interval((yyvsp[-2].ptree),0);}
#line 1966 "parser.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 363 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = Interval(0,0);}
#line 1972 "parser.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 366 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = new ParseTree(jags::P_VAR, yylineno); setName((yyval.ptree), (yyvsp[0].stringptr));
}
#line 1980 "parser.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 369 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = new ParseTree(jags::P_VAR, yylineno); setName((yyval.ptree), (yyvsp[-3].stringptr));
  setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 1989 "parser.cc" /* yacc.c:1646  */
    break;


#line 1993 "parser.cc" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
  return yyresult;
}
#line 375 "../../../../../../jags-4_patched/src/lib/compiler/parser.yy" /* yacc.c:1906  */


static std::string error_buf;

void yyerror (const char *s)
{
    extern char * yytext;
    extern int yylineno;

    std::ostringstream msg;
    msg << std::string(s) << " on line " << yylineno << " near \"" << 
           std::string(yytext) << "\"";
    error_buf = msg.str();
}

static ParseTree *Truncated (ParseTree *left, ParseTree *right)
{
    //JAGS-Style truncation notation
    ParseTree *p = new ParseTree(jags::P_BOUNDS, yylineno);
    setParameters(p, left, right);
    return p;
}

static ParseTree *Interval (ParseTree *left, ParseTree *right)
{
    //BUGS-Style interval censoring notation
    ParseTree *p = new ParseTree(jags::P_INTERVAL, yylineno);
    setParameters(p, left, right);
    return p;
}

void setName(ParseTree *p, std::string *name)
{
  /* 
     The scanner cannot return a string, because a string cannot be
     part of a union.  So instead the scanner returns a pointer to
     a newly allocated string.  This memory must be freed as soon
     as it is used.
  */
  p->setName(*name);
  delete name;
}
	

void setParameters(ParseTree *p, std::vector<ParseTree*> *parameters)
{
  /* 
     Same as setName (above).  The parser dynamically allocates
     vectors of (pointers to) parameters. These vectors must be
     deleted when we are done with them.
  */
  p->setParameters(*parameters);
  delete parameters; 
}

void setParameters(ParseTree *p, ParseTree *param1)
{
  /*
    Wrapper function that creates a vector containing param1
    to be passed to ParseTree::setParameters.
  */
  std::vector<ParseTree *> parameters(1, param1);
  p->setParameters(parameters);
}

void setParameters(ParseTree *p, ParseTree *param1, ParseTree *param2)
{
  /*
    Wrapper function that creates a vector containing param1
    and param2, to be passed to ParseTree::setParameters
  */
  std::vector<ParseTree *> parameters;
  parameters.push_back(param1);
  parameters.push_back(param2);
  p->setParameters(parameters);
}

void setParameters(ParseTree *p, ParseTree *param1, ParseTree *param2,
		   ParseTree *param3)
{
  /*
    Wrapper function that creates a vector containing param1, param2
    and param3, to be passed to ParseTree::setParameters
  */
  std::vector<ParseTree *> parameters;
  parameters.push_back(param1);
  parameters.push_back(param2);
  parameters.push_back(param3);
  p->setParameters(parameters);
}

int parse_bugs (std::FILE *file, std::vector<ParseTree*> * &dec_list, 
                ParseTree * &data, ParseTree * &relations,
		std::string &message)
{
    extern std::FILE *yyin;
    yyin = file;
    
    int val = 0;
    error_buf.clear();

    if (yyparse() == 0) {
	dec_list = _pvariables; 
	data = _pdata; 
	relations = _prelations;
    }
    else {
	message = error_buf;
	delete _pvariables; 
	delete _prelations; 
	delete _pdata;
	val = 1;
    }
    _pvariables = 0;
    _prelations = 0;
    _pdata = 0;

    yylex_destroy();

    return val;
}
