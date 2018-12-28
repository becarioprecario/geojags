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


/* Substitute the variable and function names.  */
#define yyparse         zzparse
#define yylex           zzlex
#define yyerror         zzerror
#define yydebug         zzdebug
#define yynerrs         zznerrs

#define yylval          zzlval
#define yychar          zzchar

/* Copy the first part of user declarations.  */
#line 2 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:339  */

#include <config.h>

#ifdef Win32
#include <windows.h>   /* For getCurrentDirectory */
#include <io.h>        /* For chdir */
#else
#include <unistd.h>    /* For getcwd, chdir */
#endif

//#include <limits.h>

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <list>
#include <iterator>
#include <string>
#include <utility>

#include <dirent.h>
#include <time.h>
#include <errno.h>

#include <Console.h>
#include <module/Module.h>
#include <compiler/ParseTree.h>
#include <util/nainf.h>
#include <cstring>
#include <ltdl.h>

//Required for warning about masked distributions after module loading
#include <deque>
#include <distribution/Distribution.h>
#include <compiler/Compiler.h>

#include "ReadData.h"

    typedef void(*pt2Func)();

    int zzerror(const char *);
    int zzlex();
    int zzlex_destroy();
#define YYERROR_VERBOSE 0
    static jags::Console *console;
    bool interactive;
    extern int command_buffer_count;
    void setName(jags::ParseTree *p, std::string *name);
    std::map<std::string, jags::SArray> _data_table;
    std::deque<lt_dlhandle> _dyn_lib;
    bool open_data_buffer(std::string const *name);
    bool open_command_buffer(std::string const *name);
    void return_to_main_buffer();
    void setMonitor(jags::ParseTree const *var, int thin, std::string const &type);
    void clearMonitor(jags::ParseTree const *var, std::string const &type);
    void doCoda (jags::ParseTree const *var, std::string const &stem);
    void doAllCoda (std::string const &stem);
    void doDump (std::string const &file, jags::DumpType type, unsigned int chain);
    void dumpMonitors(std::string const &file, std::string const &type);
    void doSystem(std::string const *command);
    std::string ExpandFileName(char const *s);

    static bool getWorkingDirectory(std::string &name);
    static void errordump();
    static void updatestar(long niter, long refresh, int width);
	// Run adaptation phase until adapted, regardless of iterations:
    static void autoadaptstar(long maxiter, long refresh, int width);
    static void adaptstar(long niter, long refresh, int width, bool force);
    static void setParameters(jags::ParseTree *p, jags::ParseTree *param1);
    static void setParameters(jags::ParseTree *p, std::vector<jags::ParseTree*> *parameters);
    static void setParameters(jags::ParseTree *p, jags::ParseTree *param1, jags::ParseTree *param2);
    static void loadModule(std::string const &name);
    static void unloadModule(std::string const &name);
    static void dumpSamplers(std::string const &file);
    static void delete_pvec(std::vector<jags::ParseTree*> *);
    static void print_unused_variables(std::map<std::string, jags::SArray> const &table, bool data);
    static void listFactories(jags::FactoryType type);
	static void listModules();
    static void setFactory(std::string const &name, jags::FactoryType type,
                           std::string const &status);
    static void setSeed(unsigned int seed);
    static bool Jtry(bool ok);
	// Needed for update (and adapt) functions to dump variable states:
    static bool Jtry_dump(bool ok);
	// Note: on !ok, Jtry(_dump) only exits if !interactive and otherwise returns ok, 
	// so the parent function should evaluate the value and return; if appriopriate
    

#line 169 "parser.cc" /* yacc.c:339  */

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
#ifndef YY_ZZ_PARSER_HH_INCLUDED
# define YY_ZZ_PARSER_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int zzdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    DOUBLE = 259,
    NAME = 260,
    STRING = 261,
    SYSCMD = 262,
    ENDCMD = 263,
    MODEL = 264,
    DATA = 265,
    IN = 266,
    TO = 267,
    INITS = 268,
    PARAMETERS = 269,
    COMPILE = 270,
    INITIALIZE = 271,
    ADAPT = 272,
    AUTOADAPT = 273,
    FORCEADAPT = 274,
    UPDATE = 275,
    BY = 276,
    MONITORS = 277,
    MONITOR = 278,
    TYPE = 279,
    SET = 280,
    CLEAR = 281,
    THIN = 282,
    CODA = 283,
    STEM = 284,
    EXIT = 285,
    NCHAINS = 286,
    CHAIN = 287,
    LOAD = 288,
    UNLOAD = 289,
    SAMPLER = 290,
    SAMPLERS = 291,
    RNGTOK = 292,
    FACTORY = 293,
    FACTORIES = 294,
    MODULES = 295,
    SEED = 296,
    LIST = 297,
    STRUCTURE = 298,
    DIM = 299,
    NA = 300,
    R_NULL = 301,
    DIMNAMES = 302,
    ITER = 303,
    ARROW = 304,
    ENDDATA = 305,
    ASINTEGER = 306,
    DOTDATA = 307,
    DIRECTORY = 308,
    CD = 309,
    PWD = 310,
    RUN = 311,
    ENDSCRIPT = 312
  };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define NAME 260
#define STRING 261
#define SYSCMD 262
#define ENDCMD 263
#define MODEL 264
#define DATA 265
#define IN 266
#define TO 267
#define INITS 268
#define PARAMETERS 269
#define COMPILE 270
#define INITIALIZE 271
#define ADAPT 272
#define AUTOADAPT 273
#define FORCEADAPT 274
#define UPDATE 275
#define BY 276
#define MONITORS 277
#define MONITOR 278
#define TYPE 279
#define SET 280
#define CLEAR 281
#define THIN 282
#define CODA 283
#define STEM 284
#define EXIT 285
#define NCHAINS 286
#define CHAIN 287
#define LOAD 288
#define UNLOAD 289
#define SAMPLER 290
#define SAMPLERS 291
#define RNGTOK 292
#define FACTORY 293
#define FACTORIES 294
#define MODULES 295
#define SEED 296
#define LIST 297
#define STRUCTURE 298
#define DIM 299
#define NA 300
#define R_NULL 301
#define DIMNAMES 302
#define ITER 303
#define ARROW 304
#define ENDDATA 305
#define ASINTEGER 306
#define DOTDATA 307
#define DIRECTORY 308
#define CD 309
#define PWD 310
#define RUN 311
#define ENDSCRIPT 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 99 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:355  */

  int intval;
  double val;
  std::string *stringptr;
  jags::ParseTree *ptree;
  std::vector<jags::ParseTree*> *pvec;
  std::vector<double> *vec;
  std::vector<long> *ivec;

#line 333 "parser.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE zzlval;

int zzparse (void);

#endif /* !YY_ZZ_PARSER_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 350 "parser.cc" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  315

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      59,    60,    64,     2,    58,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    65,
       2,    67,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,    66,     2,     2,    68,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   181,   181,   185,   191,   192,   193,   194,   195,   196,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   227,   239,   244,   252,
     258,   264,   276,   282,   308,   322,   325,   329,   335,   344,
     356,   360,   366,   373,   377,   382,   386,   391,   395,   400,
     404,   409,   412,   415,   421,   424,   429,   432,   438,   441,
     442,   445,   448,   451,   454,   457,   461,   465,   471,   474,
     480,   486,   498,   499,   502,   505,   508,   511,   516,   519,
     522,   529,   534,   539,   545,   551,   558,   565,   573,   581,
     584,   587,   592,   595,   600,   608,   609,   610,   615,   616,
     620,   627,   635,   636,   637,   638,   641,   644,   649,   650,
     653,   656,   660,   666,   667,   670,   671,   677,   680,   681,
     684,   685,   688,   689,   690,   691,   692,   693,   696,   697,
     700,   701,   704,   705,   708,   709,   714,   725,   733,   757
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "DOUBLE", "NAME", "STRING",
  "SYSCMD", "ENDCMD", "MODEL", "DATA", "IN", "TO", "INITS", "PARAMETERS",
  "COMPILE", "INITIALIZE", "ADAPT", "AUTOADAPT", "FORCEADAPT", "UPDATE",
  "BY", "MONITORS", "MONITOR", "TYPE", "SET", "CLEAR", "THIN", "CODA",
  "STEM", "EXIT", "NCHAINS", "CHAIN", "LOAD", "UNLOAD", "SAMPLER",
  "SAMPLERS", "RNGTOK", "FACTORY", "FACTORIES", "MODULES", "SEED", "LIST",
  "STRUCTURE", "DIM", "NA", "R_NULL", "DIMNAMES", "ITER", "ARROW",
  "ENDDATA", "ASINTEGER", "DOTDATA", "DIRECTORY", "CD", "PWD", "RUN",
  "ENDSCRIPT", "','", "'('", "')'", "'['", "']'", "':'", "'*'", "';'",
  "'`'", "'='", "'c'", "$accept", "input", "line", "command", "model",
  "data_in", "data_to", "data", "data_clear", "parameters_in",
  "parameters_to", "parameters", "compile", "initialize", "autoadapt",
  "forceadapt", "adapt", "update", "exit", "var", "range_list",
  "range_element", "index", "monitor", "monitor_set", "monitor_clear",
  "monitors_to", "file_name", "coda", "load", "unload", "samplers_to",
  "list_factories", "list_modules", "set_factory", "set_seed",
  "r_assignment_list", "r_assignment", "r_name", "r_data", "r_structure",
  "r_attribute_list", "r_dim", "r_collection", "r_integer_collection",
  "r_value_collection", "r_value_list", "r_value", "r_generic_attribute",
  "r_generic_list", "r_generic_list_element", "r_generic_vector",
  "r_numeric_vector", "r_double_list", "r_character_vector",
  "r_string_list", "get_working_dir", "set_working_dir", "read_dir",
  "run_script", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    44,    40,
      41,    91,    93,    58,    42,    59,    96,    61,    99
};
# endif

#define YYPACT_NINF -206

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-206)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -206,   100,  -206,    97,   104,  -206,    -7,    77,    29,   140,
     -45,  -206,    20,    80,   121,   129,    81,     7,   -13,    15,
    -206,   158,   130,   149,   126,  -206,   158,  -206,   158,   133,
    -206,   161,  -206,  -206,  -206,    21,  -206,  -206,  -206,    21,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,   158,  -206,   158,   158,  -206,
     158,   158,   158,   139,   113,   114,   115,   116,   158,   117,
     170,   170,   118,   162,   174,   122,   123,  -206,  -206,  -206,
    -206,   158,   124,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
     178,    32,  -206,   135,    61,  -206,  -206,  -206,  -206,  -206,
     127,   120,   165,   166,   167,   168,   132,   188,   136,   137,
      75,   187,   191,  -206,   164,   169,  -206,   173,   138,  -206,
      21,  -206,     5,   141,   171,   197,   142,   143,   146,   147,
     183,  -206,   -27,  -206,   145,   182,   186,   152,   153,   155,
     156,   157,   159,   160,  -206,  -206,  -206,  -206,   163,  -206,
     172,   175,  -206,  -206,  -206,  -206,  -206,   185,   176,   177,
     212,   217,   218,   220,   179,   188,  -206,   188,   180,   181,
     219,   222,   202,   203,   158,   158,   108,    26,     4,    39,
     184,   225,  -206,   189,   190,   192,   193,   224,  -206,  -206,
     227,   228,   194,   195,   198,   199,   196,   200,   201,   204,
     205,   206,   -24,  -206,   207,    46,  -206,   229,   208,  -206,
    -206,  -206,  -206,   209,   210,   211,   214,   221,    -8,   213,
    -206,  -206,  -206,  -206,  -206,    17,    85,  -206,  -206,    39,
    -206,   215,  -206,  -206,  -206,  -206,   223,   226,   216,   230,
     231,  -206,   232,   233,    79,  -206,  -206,  -206,  -206,   239,
     241,  -206,  -206,  -206,    18,     2,    85,  -206,   234,   235,
    -206,  -206,   237,   238,  -206,   242,   243,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,    12,    12,     6,   134,
     236,    86,  -206,  -206,    89,   245,   246,  -206,  -206,    90,
     102,    18,    12,  -206,  -206,   240,  -206,   247,  -206,   253,
    -206,  -206,  -206,  -206,  -206
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     4,     0,     0,     0,     0,
      50,    52,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,     0,     0,   148,     0,   146,     0,     0,
       3,     0,    10,    11,    12,    39,    13,    14,    15,    45,
      16,    17,    19,    20,    18,    21,    27,    22,    69,    70,
      23,    24,    25,    26,    31,    32,    33,    34,    35,    29,
      30,    28,     7,     6,     9,     0,    37,     0,     0,    42,
       0,     0,     0,     0,    57,    53,    55,    59,     0,    62,
       0,     0,    73,     0,     0,    86,    84,    82,    83,    88,
      89,     0,     0,    94,   147,   149,     8,     5,   106,   105,
       0,     0,    99,     0,     0,    36,    41,    40,    49,    48,
      46,     0,     0,     0,     0,     0,    80,     0,    71,    78,
       0,     0,     0,    98,     0,     0,    90,     0,     0,    38,
       0,   100,     0,    43,     0,     0,     0,     0,     0,     0,
       0,    68,     0,    64,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   101,   125,   104,     0,   126,
       0,     0,   102,   103,   118,   119,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,    65,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,   123,     0,     0,    58,
      54,    56,    60,     0,     0,     0,    75,    74,     0,     0,
      87,    85,    93,    91,    92,     0,     0,   111,   120,     0,
     122,     0,    47,    81,    72,    79,     0,     0,     0,     0,
       0,   109,     0,     0,     0,   112,   113,   124,    44,     0,
       0,    97,    96,    95,     0,     0,     0,   110,     0,     0,
     138,   142,     0,     0,   137,     0,     0,   127,   132,   134,
     117,   116,   115,   114,    76,    77,     0,     0,     0,     0,
       0,     0,   128,   130,     0,     0,     0,   140,   144,     0,
       0,     0,     0,   135,   136,     0,   133,     0,   139,     0,
     143,   131,   129,   141,   145
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,    -5,
    -206,  -174,    59,  -206,  -206,  -206,  -206,   -26,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,   244,    -9,  -206,  -206,
    -206,  -206,   -19,  -184,  -206,    74,  -206,  -182,    -3,   -21,
     -30,  -205,   -14,  -206,  -206,  -206,  -206,  -206,  -206,  -206
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    82,
     142,   143,   144,    47,    48,    49,    50,    89,    51,    52,
      53,    54,    55,    56,    57,    58,   101,   102,   103,   212,
     162,   254,   255,   163,   164,   165,   215,   166,   256,   291,
     292,   293,   278,   299,   279,   300,    59,    60,    61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      94,   198,    95,   213,    65,   141,   156,   216,   156,   156,
     270,   157,    79,    73,    86,   248,   270,   290,   271,    66,
      79,   156,   270,    74,   271,    83,    98,    99,    84,   249,
     156,   175,    80,    81,   236,   176,   237,    98,    99,   105,
      70,   106,   107,   156,   108,   109,   110,   159,   158,   159,
     159,   251,   116,   160,   272,   273,   160,   257,   274,   277,
     272,   273,   159,   275,   274,   126,    98,    99,   160,   275,
     161,   159,   161,   161,   295,   118,   119,   160,   211,    85,
     276,   281,   129,    75,   159,   161,   276,   100,    67,    68,
     252,   280,   131,    78,   161,   131,   311,   130,   100,   147,
       2,     3,   148,    69,   239,    63,   240,     4,     5,     6,
       7,   133,    64,     8,     9,    10,    11,    12,    13,    14,
      15,   155,    16,    17,    76,    18,   130,   100,    19,   253,
      20,   208,    77,    21,    22,    90,    23,   266,   297,   267,
     298,    96,    24,   209,   302,   210,   303,   302,   307,   304,
     308,    71,    72,    25,    26,    27,    28,    29,   206,   207,
     309,    91,   310,    87,    88,    92,    93,   121,   122,    97,
     111,   112,   113,   114,   115,    79,   120,   123,   117,   135,
     124,   125,   127,   128,   132,   134,   136,   137,   138,   139,
     140,   141,   149,   151,   145,   146,   150,   153,   152,   167,
     169,   170,   171,   168,   154,   172,   173,   174,   177,   178,
     179,   180,   181,   182,   183,   193,   184,   190,   185,   186,
     194,   195,   187,   196,   202,   203,   204,   205,   218,   223,
     224,   188,   241,   225,   189,   191,   199,   192,   197,   200,
     201,   246,   268,   217,   297,   247,   269,   282,   250,   219,
     220,   313,   221,   222,   226,   227,   230,   228,   229,   314,
     231,   232,   214,   283,   233,   234,   294,   238,   242,   243,
     244,   245,   312,   235,   296,   258,   261,     0,     0,     0,
       0,     0,   259,   104,     0,   260,     0,     0,     0,     0,
     262,   263,     0,     0,   284,   285,   286,   287,     0,   264,
     265,   288,   289,   301,   305,     0,   306
};

static const yytype_int16 yycheck[] =
{
      26,   175,    28,   187,    11,     3,     4,   189,     4,     4,
       4,     6,     5,    58,    19,    23,     4,     5,     6,    26,
       5,     4,     4,     3,     6,    38,     5,     6,    41,    37,
       4,    58,    25,    26,    58,    62,    60,     5,     6,    65,
      11,    67,    68,     4,    70,    71,    72,    45,    43,    45,
      45,   235,    78,    51,    42,    43,    51,   239,    46,   264,
      42,    43,    45,    51,    46,    91,     5,     6,    51,    51,
      68,    45,    68,    68,    68,    80,    81,    51,    52,    64,
      68,   265,    50,     3,    45,    68,    68,    66,    11,    12,
       5,   265,   101,    12,    68,   104,   301,    65,    66,    24,
       0,     1,    27,    26,    58,     8,    60,     7,     8,     9,
      10,    50,     8,    13,    14,    15,    16,    17,    18,    19,
      20,   130,    22,    23,     3,    25,    65,    66,    28,    44,
      30,    23,     3,    33,    34,     5,    36,    58,     4,    60,
       6,     8,    42,    35,    58,    37,    60,    58,    58,    60,
      60,    11,    12,    53,    54,    55,    56,    57,   184,   185,
      58,    12,    60,     5,     6,    39,    40,     5,     6,     8,
      31,    58,    58,    58,    58,     5,    58,     3,    61,    59,
      58,    58,    58,     5,    49,    58,    21,    21,    21,    21,
      58,     3,     5,    29,    58,    58,     5,    24,    29,    58,
       3,    59,    59,    32,    66,    59,    59,    24,    63,    27,
      24,    59,    59,    58,    58,     3,    59,    32,    59,    59,
       3,     3,    59,     3,     5,     3,    24,    24,     3,     5,
       3,    59,     3,     5,    59,    59,   177,    60,    59,    59,
      59,    27,     3,    59,     4,    24,     5,   266,    35,    60,
      60,     4,    60,    60,    60,    60,    60,    59,    59,     6,
      60,    60,   188,   266,    60,    60,   287,    60,    60,    60,
      60,    60,   302,    67,   288,    60,    60,    -1,    -1,    -1,
      -1,    -1,    59,    39,    -1,    59,    -1,    -1,    -1,    -1,
      60,    60,    -1,    -1,    60,    60,    59,    59,    -1,    67,
      67,    59,    59,    67,    59,    -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,     0,     1,     7,     8,     9,    10,    13,    14,
      15,    16,    17,    18,    19,    20,    22,    23,    25,    28,
      30,    33,    34,    36,    42,    53,    54,    55,    56,    57,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    92,    93,    94,
      95,    97,    98,    99,   100,   101,   102,   103,   104,   125,
     126,   127,   128,     8,     8,    11,    26,    11,    12,    26,
      11,    11,    12,    58,     3,     3,     3,     3,    12,     5,
      25,    26,    88,    38,    41,    64,    88,     5,     6,    96,
       5,    12,    39,    40,    96,    96,     8,     8,     5,     6,
      66,   105,   106,   107,   105,    96,    96,    96,    96,    96,
      96,    31,    58,    58,    58,    58,    96,    61,    88,    88,
      58,     5,     6,     3,    58,    58,    96,    58,     5,    50,
      65,   106,    49,    50,    58,    59,    21,    21,    21,    21,
      58,     3,    89,    90,    91,    58,    58,    24,    27,     5,
       5,    29,    29,    24,    66,   106,     4,     6,    43,    45,
      51,    68,   109,   112,   113,   114,   116,    58,    32,     3,
      59,    59,    59,    59,    24,    58,    62,    63,    27,    24,
      59,    59,    58,    58,    59,    59,    59,    59,    59,    59,
      32,    59,    60,     3,     3,     3,     3,    59,    90,    91,
      59,    59,     5,     3,    24,    24,    96,    96,    23,    35,
      37,    52,   108,   112,   114,   115,   116,    59,     3,    60,
      60,    60,    60,     5,     3,     5,    60,    60,    59,    59,
      60,    60,    60,    60,    60,    67,    58,    60,    60,    58,
      60,     3,    60,    60,    60,    60,    27,    24,    23,    37,
      35,   112,     5,    44,   110,   111,   117,   116,    60,    59,
      59,    60,    60,    60,    67,    67,    58,    60,     3,     5,
       4,     6,    42,    43,    46,    51,    68,   120,   121,   123,
      90,   112,   111,   117,    60,    60,    59,    59,    59,    59,
       5,   118,   119,   120,   118,    68,   121,     4,     6,   122,
     124,    67,    58,    60,    60,    59,    60,    58,    60,    58,
      60,   120,   119,     4,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    74,    74,
      75,    76,    77,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    83,    83,    84,    84,    85,    85,    86,
      86,    87,    88,    88,    89,    89,    90,    90,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    97,    98,    99,
     100,   101,   101,   101,   102,   103,   103,   103,   104,   105,
     105,   105,   106,   106,   106,   107,   107,   107,   108,   108,
     109,   109,   110,   110,   110,   110,   111,   111,   112,   112,
     113,   114,   114,   115,   115,   116,   116,   117,   118,   118,
     119,   119,   120,   120,   120,   120,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   126,   127,   128
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     1,
       3,     3,     2,     3,     8,     1,     3,     8,     3,     3,
       1,     6,     1,     2,     7,     2,     7,     2,     7,     2,
       7,     1,     1,     4,     1,     3,     1,     3,     1,     1,
       1,     3,     8,     2,     7,     7,    11,    11,     3,     8,
       3,     8,     1,     1,     2,     7,     2,     7,     2,     2,
       3,     7,     7,     7,     2,     9,     9,     9,     3,     1,
       2,     3,     3,     3,     3,     1,     1,     3,     1,     3,
       6,     4,     1,     1,     3,     3,     3,     3,     1,     1,
       4,     1,     4,     1,     3,     1,     1,     3,     1,     3,
       1,     3,     1,     4,     1,     4,     4,     1,     1,     4,
       1,     3,     1,     4,     1,     3,     1,     2,     1,     2
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
        case 2:
#line 181 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    if (interactive && command_buffer_count == 0) 
	std::cout << ". " << std::flush;
}
#line 1656 "parser.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 185 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    if (interactive && command_buffer_count == 0) 
	std::cout << ". " << std::flush;
}
#line 1665 "parser.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 191 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {}
#line 1671 "parser.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 192 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {}
#line 1677 "parser.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 193 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {if(interactive) yyerrok; else exit(1); }
#line 1683 "parser.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 194 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {}
#line 1689 "parser.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 195 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {}
#line 1695 "parser.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 196 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    { doSystem((yyvsp[-1].stringptr)); delete (yyvsp[-1].stringptr);}
#line 1701 "parser.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 227 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    std::FILE *file = std::fopen(ExpandFileName(((yyvsp[0].stringptr))->c_str()).c_str(), "r");
    if (!file) {
	std::cerr << "Failed to open file " << *((yyvsp[0].stringptr)) << std::endl;
	if (!interactive) exit(1);
    }
    else {
	Jtry(console->checkModel(file));
	std::fclose(file);
    }
    delete (yyvsp[0].stringptr);
 }
#line 1718 "parser.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 239 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    console->clearModel();
 }
#line 1726 "parser.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 244 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    std::string rngname;
    readRData((yyvsp[-1].pvec), _data_table, rngname);
    if (rngname.size() != 0) {
	std::cerr << "WARNING: .RNG.name assignment ignored" << std::endl;
    }
    delete_pvec((yyvsp[-1].pvec));
 }
#line 1739 "parser.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 252 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    // Failed to open the data file 
    if (!interactive) exit(1);
  }
#line 1748 "parser.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 258 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    doDump(*(yyvsp[0].stringptr), jags::DUMP_DATA, 1);
    delete (yyvsp[0].stringptr);
}
#line 1757 "parser.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 264 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    if(open_data_buffer((yyvsp[0].stringptr))) {
	std::cout << "Reading data file " << *(yyvsp[0].stringptr) << std::endl;
    }
    else {
	std::cerr << "Unable to open file " << *(yyvsp[0].stringptr) << std::endl << std::flush;
	if (!interactive) exit(1);
    }
    delete (yyvsp[0].stringptr);
 }
#line 1772 "parser.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 276 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    std::cout << "Clearing data table " << std::endl;
    _data_table.clear();
}
#line 1781 "parser.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 283 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    std::map<std::string, jags::SArray> parameter_table;
    std::string rngname;
    readRData((yyvsp[-1].pvec), parameter_table, rngname);
    delete_pvec((yyvsp[-1].pvec));
    /* Set all chains to the same state. If the user sets the
       RNG state in addition to the parameter values then all
       chains will be identical!
    */
    if (console->model() == 0) {
	std::cout << "ERROR: Initial values ignored. "
		  <<  "(You must compile the model first)" << std::endl;
	if (!interactive) exit(1);
    }
    for (unsigned int i = 1; i <= console->nchain(); ++i) {
	/* We have to set the name first, because the state or seed
	   might be embedded in the parameter_table */
	if (rngname.size() != 0) {
	    Jtry(console->setRNGname(rngname, i));
	}
	Jtry(console->setParameters(parameter_table, i));
    }
    print_unused_variables(parameter_table, false);

}
#line 1811 "parser.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 309 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    std::map<std::string, jags::SArray> parameter_table;
    std::string rngname;
    readRData((yyvsp[-6].pvec), parameter_table, rngname);
    delete (yyvsp[-6].pvec);
    /* We have to set the name first, because the state or seed
       might be embedded in the parameter_table */
    if (rngname.size() != 0) {
        Jtry(console->setRNGname(rngname, (yyvsp[-1].intval)));
    }
    Jtry(console->setParameters(parameter_table, (yyvsp[-1].intval)));
    print_unused_variables(parameter_table, false);
}
#line 1829 "parser.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 322 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {}
#line 1835 "parser.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 325 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    doDump(*(yyvsp[0].stringptr), jags::DUMP_PARAMETERS, 1);
    delete (yyvsp[0].stringptr);
}
#line 1844 "parser.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 329 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    doDump(*(yyvsp[-5].stringptr), jags::DUMP_PARAMETERS, (yyvsp[-1].intval));
    delete (yyvsp[-5].stringptr);
}
#line 1853 "parser.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 335 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  if(open_data_buffer((yyvsp[0].stringptr))) {
    std::cout << "Reading parameter file " << *(yyvsp[0].stringptr) << std::endl;
  }
  else {
    std::cerr << "Unable to open file " << *(yyvsp[0].stringptr) << std::endl << std::flush;
  }
  delete (yyvsp[0].stringptr);
}
#line 1867 "parser.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 344 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  /* Legacy option to not break existing scripts */
  if(open_data_buffer((yyvsp[0].stringptr))) {
    std::cout << "Reading initial values file " << *(yyvsp[0].stringptr) << std::endl;
  }
  else {
    std::cerr << "Unable to open file " << *(yyvsp[0].stringptr) << std::endl << std::flush;
  }
  delete (yyvsp[0].stringptr);
}
#line 1882 "parser.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 356 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    Jtry(console->compile(_data_table, 1, true));
    print_unused_variables(_data_table, true);
 }
#line 1891 "parser.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 360 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    Jtry(console->compile(_data_table, (yyvsp[-1].intval), true));
    print_unused_variables(_data_table, true);
}
#line 1900 "parser.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 366 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    if (!console->initialize()) {
	errordump();
    }
}
#line 1910 "parser.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 373 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    long refresh = interactive ? (yyvsp[0].intval)/50 : 0;
    autoadaptstar((yyvsp[0].intval), refresh, 50);
}
#line 1919 "parser.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 377 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    autoadaptstar((yyvsp[-5].intval),(yyvsp[-1].intval), 50);
}
#line 1927 "parser.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 382 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    long refresh = interactive ? (yyvsp[0].intval)/50 : 0;
    adaptstar((yyvsp[0].intval), refresh, 50, true);
}
#line 1936 "parser.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 386 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    adaptstar((yyvsp[-5].intval),(yyvsp[-1].intval), 50, true);
}
#line 1944 "parser.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 391 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    long refresh = interactive ? (yyvsp[0].intval)/50 : 0;
    adaptstar((yyvsp[0].intval), refresh, 50, false);
}
#line 1953 "parser.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 395 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    adaptstar((yyvsp[-5].intval),(yyvsp[-1].intval), 50, false);
}
#line 1961 "parser.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 400 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    long refresh = interactive ? (yyvsp[0].intval)/50 : 0;
    updatestar((yyvsp[0].intval), refresh, 50);
}
#line 1970 "parser.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 404 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  updatestar((yyvsp[-5].intval),(yyvsp[-1].intval), 50);
}
#line 1978 "parser.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 409 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    { return 0; }
#line 1984 "parser.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 412 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = new jags::ParseTree(jags::P_VAR); setName((yyval.ptree), (yyvsp[0].stringptr));
}
#line 1992 "parser.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 415 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = new jags::ParseTree(jags::P_VAR); setName((yyval.ptree), (yyvsp[-3].stringptr));
  setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 2001 "parser.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 421 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.pvec) = new std::vector<jags::ParseTree*>(1, (yyvsp[0].ptree)); 
}
#line 2009 "parser.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 424 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.pvec)=(yyvsp[-2].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 2017 "parser.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 429 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = new jags::ParseTree(jags::P_RANGE); setParameters((yyval.ptree), (yyvsp[0].ptree));
}
#line 2025 "parser.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 432 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = new jags::ParseTree(jags::P_RANGE); setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 2033 "parser.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 438 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = new jags::ParseTree(jags::P_VALUE); (yyval.ptree)->setValue((yyvsp[0].intval));}
#line 2039 "parser.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 445 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    { 
    setMonitor((yyvsp[0].ptree), 1, "trace"); delete (yyvsp[0].ptree);
}
#line 2047 "parser.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 448 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    { 
    setMonitor((yyvsp[-5].ptree), (yyvsp[-1].intval), "trace"); delete (yyvsp[-5].ptree);
}
#line 2055 "parser.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 451 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    setMonitor((yyvsp[0].ptree), 1, "trace"); delete (yyvsp[0].ptree);
}
#line 2063 "parser.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 454 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    { 
    setMonitor((yyvsp[-5].ptree), (yyvsp[-1].intval), "trace"); delete (yyvsp[-5].ptree);
}
#line 2071 "parser.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 457 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    setMonitor((yyvsp[-5].ptree), 1, *(yyvsp[-1].stringptr));
    delete (yyvsp[-1].stringptr);
}
#line 2080 "parser.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 461 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    setMonitor((yyvsp[-9].ptree), (yyvsp[-1].intval), *(yyvsp[-5].stringptr)); 
    delete (yyvsp[-5].stringptr);
}
#line 2089 "parser.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 465 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    setMonitor((yyvsp[-9].ptree), (yyvsp[-5].intval), *(yyvsp[-1].stringptr)); 
    delete (yyvsp[-1].stringptr);
}
#line 2098 "parser.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 471 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    clearMonitor((yyvsp[0].ptree), "trace"); delete (yyvsp[0].ptree);
}
#line 2106 "parser.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 474 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    clearMonitor((yyvsp[-5].ptree), *(yyvsp[-1].stringptr));
    delete (yyvsp[-1].stringptr);
}
#line 2115 "parser.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 481 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    dumpMonitors(*(yyvsp[0].stringptr), "trace");
    delete (yyvsp[0].stringptr);
}
#line 2124 "parser.cc" /* yacc.c:1646  */
    break;

  case 81:
#line 486 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    dumpMonitors(*(yyvsp[-5].stringptr), *(yyvsp[-1].stringptr));
    delete (yyvsp[-5].stringptr);
    delete (yyvsp[-1].stringptr); 
}
#line 2134 "parser.cc" /* yacc.c:1646  */
    break;

  case 82:
#line 498 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    { (yyval.stringptr) = (yyvsp[0].stringptr);}
#line 2140 "parser.cc" /* yacc.c:1646  */
    break;

  case 83:
#line 499 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    { (yyval.stringptr) = (yyvsp[0].stringptr); }
#line 2146 "parser.cc" /* yacc.c:1646  */
    break;

  case 84:
#line 502 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  doCoda ((yyvsp[0].ptree), "CODA"); delete (yyvsp[0].ptree);
}
#line 2154 "parser.cc" /* yacc.c:1646  */
    break;

  case 85:
#line 505 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  doCoda ((yyvsp[-5].ptree), *(yyvsp[-1].stringptr)); delete (yyvsp[-5].ptree); delete (yyvsp[-1].stringptr);
}
#line 2162 "parser.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 508 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  doAllCoda ("CODA"); 
}
#line 2170 "parser.cc" /* yacc.c:1646  */
    break;

  case 87:
#line 511 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  doAllCoda (*(yyvsp[-1].stringptr)); delete (yyvsp[-1].stringptr); 
}
#line 2178 "parser.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 516 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    { loadModule(*(yyvsp[0].stringptr)); }
#line 2184 "parser.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 519 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    { unloadModule(*(yyvsp[0].stringptr)); }
#line 2190 "parser.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 523 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    dumpSamplers(*(yyvsp[0].stringptr));
    delete (yyvsp[0].stringptr);
}
#line 2199 "parser.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 530 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    listFactories(jags::SAMPLER_FACTORY);
}
#line 2207 "parser.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 535 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    listFactories(jags::RNG_FACTORY);
}
#line 2215 "parser.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 540 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    listFactories(jags::MONITOR_FACTORY);
}
#line 2223 "parser.cc" /* yacc.c:1646  */
    break;

  case 94:
#line 546 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    listModules();
}
#line 2231 "parser.cc" /* yacc.c:1646  */
    break;

  case 95:
#line 552 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    setFactory(*(yyvsp[-6].stringptr), jags::SAMPLER_FACTORY, *(yyvsp[-5].stringptr));
    delete (yyvsp[-6].stringptr);
    delete (yyvsp[-5].stringptr);
}
#line 2241 "parser.cc" /* yacc.c:1646  */
    break;

  case 96:
#line 559 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    setFactory(*(yyvsp[-6].stringptr), jags::RNG_FACTORY, *(yyvsp[-5].stringptr));
    delete (yyvsp[-6].stringptr);
    delete (yyvsp[-5].stringptr);
}
#line 2251 "parser.cc" /* yacc.c:1646  */
    break;

  case 97:
#line 566 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    setFactory(*(yyvsp[-6].stringptr), jags::MONITOR_FACTORY, *(yyvsp[-5].stringptr));
    delete (yyvsp[-6].stringptr);
    delete (yyvsp[-5].stringptr);
}
#line 2261 "parser.cc" /* yacc.c:1646  */
    break;

  case 98:
#line 574 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    setSeed((yyvsp[0].intval));
}
#line 2269 "parser.cc" /* yacc.c:1646  */
    break;

  case 99:
#line 581 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.pvec) = new std::vector<jags::ParseTree*>(1, (yyvsp[0].ptree));
}
#line 2277 "parser.cc" /* yacc.c:1646  */
    break;

  case 100:
#line 584 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.pvec) = (yyvsp[-1].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 2285 "parser.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 587 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.pvec) = (yyvsp[-2].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 2293 "parser.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 592 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = (yyvsp[0].ptree); setName((yyval.ptree), (yyvsp[-2].stringptr));
}
#line 2301 "parser.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 595 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = new jags::ParseTree(jags::P_ARRAY);
  setName((yyval.ptree), (yyvsp[-2].stringptr));
  setParameters((yyval.ptree), (yyvsp[0].ptree));
}
#line 2311 "parser.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 600 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  /* Allow this for setting the NAME of the random number generator */
  (yyval.ptree) = new jags::ParseTree(jags::P_VAR); setName((yyval.ptree), (yyvsp[-2].stringptr));
  jags::ParseTree *p = new jags::ParseTree(jags::P_VAR); setName(p, (yyvsp[0].stringptr));
  setParameters((yyval.ptree), p);
}
#line 2322 "parser.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 610 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    /* R >= 2.4.0 uses backticks for quoted names */
    (yyval.stringptr) = (yyvsp[-1].stringptr);
}
#line 2331 "parser.cc" /* yacc.c:1646  */
    break;

  case 109:
#line 616 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = (yyvsp[0].ptree);
}
#line 2339 "parser.cc" /* yacc.c:1646  */
    break;

  case 110:
#line 620 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = new jags::ParseTree(jags::P_ARRAY); 
  if ((yyvsp[-1].ptree)) 
    setParameters((yyval.ptree), (yyvsp[-3].ptree), (yyvsp[-1].ptree));
  else
    setParameters((yyval.ptree), (yyvsp[-3].ptree));
}
#line 2351 "parser.cc" /* yacc.c:1646  */
    break;

  case 111:
#line 627 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    (yyval.ptree) = new jags::ParseTree(jags::P_ARRAY);
    setParameters((yyval.ptree), (yyvsp[-1].ptree));
}
#line 2360 "parser.cc" /* yacc.c:1646  */
    break;

  case 113:
#line 636 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree)=0;}
#line 2366 "parser.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 638 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree)=(yyvsp[0].ptree);}
#line 2372 "parser.cc" /* yacc.c:1646  */
    break;

  case 116:
#line 641 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = (yyvsp[0].ptree);
}
#line 2380 "parser.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 644 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = (yyvsp[0].ptree);
}
#line 2388 "parser.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 653 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = (yyvsp[-1].ptree);}
#line 2394 "parser.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 656 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    { 
  (yyval.ptree) = new jags::ParseTree(jags::P_VECTOR); 
  setParameters((yyval.ptree), (yyvsp[0].ptree));
}
#line 2403 "parser.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 660 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
  (yyval.ptree) = new jags::ParseTree(jags::P_VECTOR);
  setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 2412 "parser.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 666 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {(yyval.pvec) = new std::vector<jags::ParseTree*>(1, (yyvsp[0].ptree)); }
#line 2418 "parser.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 667 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {(yyval.pvec) = (yyvsp[-2].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree));}
#line 2424 "parser.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 670 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = new jags::ParseTree(jags::P_VALUE); (yyval.ptree)->setValue((yyvsp[0].val));}
#line 2430 "parser.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 671 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {(yyval.ptree) = new jags::ParseTree(jags::P_VALUE); (yyval.ptree)->setValue(JAGS_NA);}
#line 2436 "parser.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 677 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2442 "parser.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 680 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2448 "parser.cc" /* yacc.c:1646  */
    break;

  case 129:
#line 681 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2454 "parser.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 684 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2460 "parser.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 685 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2466 "parser.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 688 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2472 "parser.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 689 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2478 "parser.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 690 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2484 "parser.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 691 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2490 "parser.cc" /* yacc.c:1646  */
    break;

  case 136:
#line 692 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2496 "parser.cc" /* yacc.c:1646  */
    break;

  case 137:
#line 693 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2502 "parser.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 696 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2508 "parser.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 700 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2514 "parser.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 701 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2520 "parser.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 704 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2526 "parser.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 705 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2532 "parser.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 708 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2538 "parser.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 709 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {;}
#line 2544 "parser.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 715 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    std::string name;
    if (getWorkingDirectory(name)) {
	std::cout << name << std::endl;
    }
    else {
	std::cout << "ERROR: " << name << std::endl;
    }
}
#line 2558 "parser.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 726 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    if (chdir(((yyvsp[0].stringptr))->c_str()) == -1) {
	std::cout << "ERROR: Cannot change working directory" << std::endl;
    }
    delete (yyvsp[0].stringptr);
}
#line 2569 "parser.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 734 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    std::string name;
    if (!getWorkingDirectory(name)) {
	std::cerr << "ERROR: Unable to get working directory name\n"
		  << name << std::endl;
	return 0;
    }
	
    DIR *dir;
    struct dirent *de;
    if ((dir = opendir(name.c_str())) != 0) {
	while ((de = readdir(dir)) != 0) {
	    if (std::strcmp(de->d_name, ".") && std::strcmp(de->d_name, "..")) {
		std::cout << de->d_name << "\n";
	    }
	}
	closedir(dir);
    }
    else {
	std::cerr << "Unable to open working directory" << std::endl;
    }
}
#line 2596 "parser.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 757 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1646  */
    {
    if(open_command_buffer((yyvsp[0].stringptr))) {
	std::cout << "Running script file " << *(yyvsp[0].stringptr) << std::endl;
    }
    else {
	std::cerr << "Unable to open script file " << *(yyvsp[0].stringptr) << std::endl;
    }
    delete (yyvsp[0].stringptr);
 }
#line 2610 "parser.cc" /* yacc.c:1646  */
    break;


#line 2614 "parser.cc" /* yacc.c:1646  */
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
#line 768 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1906  */


int zzerror (const char *s)
{
    return_to_main_buffer();
    std::cerr << s << std::endl;
    return 0;
}

static jags::Range getRange(jags::ParseTree const *var)
{
  /* 
     Blank arguments, e.g. foo[] or bar[,1]  are not allowed.
  */
  unsigned int size = var->parameters().size();

  std::vector<int>  ind_lower(size), ind_upper(size);
  for (unsigned int i = 0; i < size; ++i) {
    jags::ParseTree const *range_element = var->parameters()[i];
    switch(range_element->parameters().size()) {
    case 1:
      ind_lower[i] = (int) (range_element->parameters()[0]->value() + 1.0E-6);
      ind_upper[i] = ind_lower[i];
      break;
    case 2:
      ind_lower[i] = (int) (range_element->parameters()[0]->value() + 1.0E-6);  
      ind_upper[i] = (int) (range_element->parameters()[1]->value() + 1.0E-6);
      break;
    default:
      //Error! FIXME
      break;
    }
  }
  return jags::SimpleRange(ind_lower, ind_upper);
}

void setMonitor(jags::ParseTree const *var, int thin, std::string const &type)
{
    std::string const &name = var->name();
    if (var->parameters().empty()) {
	/* Requesting the whole node */
	console->setMonitor(name, jags::Range(), thin, type);
    }
    else {
	/* Requesting subset of a multivariate node */
	console->setMonitor(name, getRange(var), thin, type);
    }
}

void clearMonitor(jags::ParseTree const *var, std::string const &type)
{
    std::string const &name = var->name();
    if (var->parameters().empty()) {
	/* Requesting the whole node */
	console->clearMonitor(name, jags::Range(), type);
    }
    else {
	/* Requesting subset of a multivariate node */
	console->clearMonitor(name, getRange(var), type);
    }
}

void doAllCoda (std::string const &stem)
{
    console->coda(stem);
}

void doCoda (jags::ParseTree const *var, std::string const &stem)
{
    //FIXME: Allow list of several nodes

    std::vector<std::pair<std::string, jags::Range> > dmp;
    if (var->parameters().empty()) {
	/* Requesting the whole node */
	dmp.push_back(std::pair<std::string,jags::Range>(var->name(), jags::Range()));
    }
    else {
	/* Requesting subset of a multivariate node */
	dmp.push_back(std::pair<std::string,jags::Range>(var->name(), getRange(var)));
    }
    console->coda(dmp, stem);
}

/* Helper function for doDump that handles all the special cases
   (missing values etc) when writing a double value */
static void writeValue(double x, std::ostream &out, bool isdiscrete)
{
  using namespace std;

  if (x == JAGS_NA) {
    out << "NA";
  }
  else if (jags_isnan(x)) {
    out << "NaN";
  }
  else if (!jags_finite(x)) {
    if (x > 0)
      out << "Inf";
    else
      out << "-Inf";
  }
  else if (isdiscrete) {
      out << static_cast<int>(x) << "L";
  }
  else {
    out << x;
  }
}

void doDump(std::string const &file, jags::DumpType type, unsigned int chain)
{
    std::map<std::string,jags::SArray> data_table;
    std::string rng_name;
    if (!console->dumpState(data_table, rng_name, type, chain)) {
	return;
    }

    /* Open output file */
    std::ofstream out(file.c_str());
    if (!out) {
	std::cerr << "Failed to open file " << file << std::endl;
	return;
    }
  
    if (rng_name.size() != 0) {
	out << "`.RNG.name` <- \"" << rng_name << "\"\n";
    }

    for (std::map<std::string, jags::SArray>::const_iterator p = data_table.begin();
	 p != data_table.end(); ++p) {
	std::string const &name = p->first;
	jags::SArray const &sarray = p->second;
	std::vector<double> const &value = sarray.value();
	long length = sarray.length();
	out << "`" << name << "` <- " << std::endl;
	std::vector<unsigned int> const &dim = sarray.dim(false);
	bool discrete = sarray.isDiscreteValued();

	if (dim.size() == 1) {
	    // Vector 
	    if (dim[0] == 1) {
		// Scalar
		writeValue(value[0], out, discrete);
	    }
	    else {
		// Vector of length > 1
		out << "c(";
		for (int i = 0; i < length; ++i) {
		    if (i > 0) {
			out << ",";
		    }
		    writeValue(value[i], out, discrete);
		}
		out << ")";
	    }
	}
	else {
	    // Array 
	    out << "structure(c(";
	    for (int i = 0; i < length; ++i) {
		if (i > 0) {
		    out << ",";
		}
		writeValue(value[i], out, discrete);
	    }
	    out << "), .Dim = c(";
	    for (unsigned int j = 0; j < dim.size(); ++j) {
		if (j > 0) {
		    out << ",";
		}
		out << dim[j] << "L";
	    }
	    out << "))";
	}
	out << "\n";
    }
    out.close();
}  

void dumpMonitors(std::string const &file, std::string const &type)
{
    std::map<std::string,jags::SArray> data_table;

    if (!console->dumpMonitors(data_table, type, false)) {
	return;
    }

    /* Open output file */
    std::ofstream out(file.c_str());
    if (!out) {
	std::cerr << "Failed to open file " << file << std::endl;
	return;
    }

    out << "`" << type << "` <-\nstructure(list(";

    std::map<std::string, jags::SArray>::const_iterator p;
    for (p = data_table.begin(); p != data_table.end(); ++p) {
	std::string const &name = p->first;
	jags::SArray const &sarray = p->second;
	std::vector<double> const &value = sarray.value();
	long length = sarray.length();

	if (p != data_table.begin()) {
	    out << ", \n";
	}
	out << "\"" << name << "\" = ";
	std::vector<unsigned int> const &dim = sarray.dim(false);
	bool discrete = sarray.isDiscreteValued();
	bool named = !sarray.dimNames().empty();

	if (dim.size() == 1 && !named) {
	    // Vector 
	    if (dim[0] == 1) {
		// Scalar
		writeValue(value[0], out, discrete);
	    }
	    else {
		// Vector of length > 1
		out << "c(";
		for (int i = 0; i < length; ++i) {
		    if (i > 0) {
			out << ",";
		    }
		    writeValue(value[i], out, discrete);
		}
		out << ")";
	    }
	}
	else {
	    // Array 
	    out << "structure(c(";
	    for (int i = 0; i < length; ++i) {
		if (i > 0) {
		    out << ",";
		}
		writeValue(value[i], out, discrete);
	    }
	    out << "), .Dim = ";
	    if (named) {
		out << "structure(";
	    }
	    out << "c(";
	    for (unsigned int j = 0; j < dim.size(); ++j) {
		if (j > 0) {
		    out << ",";
		}
		out << dim[j] << "L";
	    }
	    out << ")";
	    if (named) {
		std::vector<std::string> const &dnames = sarray.dimNames();
		out << ", .Names = c(";
		for (unsigned int k = 0; k < dnames.size(); ++k) {
		    if (k > 0) {
			out << ",";
		    }
		    out << "\"" << dnames[k] << "\"";
		}
		out << "))";
	    }
	    out << ")";
	}
    }

    out << "), \n.Names = c(";
    for (p = data_table.begin(); p != data_table.end(); ++p) {
	if (p != data_table.begin()) {
	    out << ", ";
	}
	std::string const &name = p->first;
	out << "\"" << name << "\"";
    }
    out << "))";
    out.close();
}

void setParameters(jags::ParseTree *p, std::vector<jags::ParseTree*> *parameters)
{
  /* 
     The parser dynamically allocates vectors of (pointers to)
     parameters. These vectors must be deleted when we are done with
     them.
  */
  p->setParameters(*parameters);
  delete parameters; 
}

void setParameters(jags::ParseTree *p, jags::ParseTree *param1)
{
  /*
    Wrapper function that creates a vector containing param1
    to be passed to jags::ParseTree::setParameters.
  */
  std::vector<jags::ParseTree *> parameters(1, param1);
  p->setParameters(parameters);
}

void setParameters(jags::ParseTree *p, jags::ParseTree *param1, jags::ParseTree *param2)
{
  /*
    Wrapper function that creates a vector containing param1
    and param2, to be passed to jags::ParseTree::setParameters
  */
  std::vector<jags::ParseTree *> parameters;
  parameters.push_back(param1);
  parameters.push_back(param2);
  p->setParameters(parameters);
}

void setName(jags::ParseTree *p, std::string *name)
{
  p->setName(*name);
  delete name;
}

static void errordump()
{
    if (console->model()) {
	std::ostringstream fname;
	for (unsigned int i = 1; i <= console->nchain(); ++i) {
	    fname << "jags.dump" << i << ".R";
	    std::cout << "Dumping chain " << i << " at iteration " 
		      << console->iter() << " to file " << fname.str() 
		      << std::endl;
	    doDump(fname.str(), jags::DUMP_ALL, i);
	    fname.str("");
	}
	// Moved clearModel from Console.cc CATCH_ERRORS to here
	// to allow doDump to work as described in the manual:
	console->clearModel();
    }
    if (!interactive) exit(1);
}

static void updatestar(long niter, long refresh, int width)
{
    std::cout << "Updating " << niter << std::endl;

    bool adapt = console->isAdapting();
    if (adapt && console->iter() > 0) {
	//Turn off iteration immediately if we have some burn-in
	if (console->adaptOff()) {
	    adapt = false;
	}
	else {
	    std::cout << std::endl;
	    errordump();
	    return;
	}
    }

    if (refresh == 0) {
	if( !Jtry_dump(console->update(niter/2)) ) return;
	bool status = true;
	if (adapt) {
	    if (!console->checkAdaptation(status)) {
		errordump();
		return;
	    }
	    if (!console->adaptOff()) {
		errordump();
		return;
	    }
	}
	if( !Jtry_dump(console->update(niter - niter/2)) ) return;
	if (!status) {
	    std::cerr << "WARNING: Adaptation incomplete\n";
	}
	return;
    }

    if (width > niter / refresh + 1)
	width = niter / refresh + 1;

    for (int i = 0; i < width - 1; ++i) {
	std::cout << "-";
    }
    std::cout << "| " << std::min(width * refresh, niter) << std::endl 
	      << std::flush;

    int col = 0;
    bool status = true;
    for (long n = niter; n > 0; n -= refresh) {
	if (adapt && n <= niter/2) {
	    // Turn off adaptive mode half way through burnin
	    if (!console->checkAdaptation(status)) {
		std::cout << std::endl;
		errordump();
		return;
	    }
	    if (console->adaptOff()) {
		adapt = false;
	    }
	    else {
		std::cout << std::endl;
		errordump();
		return;
	    }
	}
	long nupdate = std::min(n, refresh);
	if(Jtry_dump(console->update(nupdate))) {
	    std::cout << "*" << std::flush;
	}
	else {
	    std::cout << std::endl;
	    return;
	}
	col++;
	if (col == width || n <= nupdate) {
	    int percent = 100 - (n-nupdate) * 100/niter;
	    std::cout << " " << percent << "%" << std::endl;
	    if (n > nupdate) {
		col = 0;
	    }
	}
    }
    if (!status) {
	std::cerr << "WARNING: Adaptation incomplete\n";
    }
}

static void autoadaptstar(long maxiter, long refresh, int width)
{
    if (!console->isAdapting()) {
        std::cout << "Adaptation skipped: model is not in adaptive mode.\n";
		return;
    }
    std::cout << "Autoadapting up to " << maxiter << " iterations" << std::endl;
	
    if (width > maxiter / refresh + 1)
		width = maxiter / refresh + 1;
	
	long i = 0;
	bool status = false;
	
	if ( refresh == 0 ) {
		for (i = 0; i < maxiter; i++) {
			if (!console->checkAdaptation(status)) {
			    errordump();
			    return;
			}
			if(status)
				break;

			if( !Jtry_dump(console->update(1)) ) {
				std::cout << std::endl;
				return;
			}
		}
	}
	else {
	    for (int j = 0; j < width - 1; ++j) {
			std::cout << "-";
	    }
	    std::cout << "| " << std::min(width * refresh, maxiter) << std::endl 
		      << std::flush;

		int col = 0;
	    for (long n = maxiter; n > 0; n -= refresh) {
		    long nupdate = std::min(n, refresh);
			for (long j = 0; j < nupdate; j++) {
				if (!console->checkAdaptation(status)) {
				    errordump();
				    return;
				}
				if(status)
					break;

				if( !Jtry_dump(console->update(1)) ) {
					std::cout << std::endl;
					return;
				}
				i++;
			}
			if(status){
		    	std::cout << std::endl;
				break;
			}

	        std::cout << "+" << std::flush;
	    	col++;
	    	if (col == width || n <= nupdate) {
	    	    int percent = 100 - (n-nupdate) * 100/maxiter;
	    	    std::cout << " " << percent << "%" << std::endl;
	    	    if (n > nupdate) {
	        		col = 0;
		        }
		    }
	    }
	}
		
	if (!console->checkAdaptation(status)) {
	    errordump();
	    return;
	}
	
	if (!status) {
	    std::cerr << "Adaptation incomplete\n";
	}
	else {
		std::cout << "Adaptation completed in " << i << " iterations" << std::endl;
		if (!console->adaptOff()) {
			std::cout << std::endl;
			errordump();
			return;
	    }
	}
    return;
}

static void adaptstar(long niter, long refresh, int width, bool force)
{
    if (!console->isAdapting()) {
	    if( force ) {
			// Missing endl is deliberate - updatestar will write to the same line:
		    std::cout << "Model not in adaptive mode: ";
			updatestar(niter, refresh, width);			
		}
		else {
	        std::cerr << "Adaptation skipped: model is not in adaptive mode.\n";
		}
		return;
    }
    std::cout << "Adapting " << niter << std::endl;
    
    bool status = true;
    if (refresh == 0) {
	if( !Jtry_dump(console->update(niter)) ) return;
	if (!console->checkAdaptation(status)) {
	    errordump();
	    return;
	}
	if (!status) {
	    std::cerr << "Adaptation incomplete\n";
	    return;
	}
	else {
	    std::cerr << "Adaptation successful\n";
	    return;
	}
    }

    if (width > niter / refresh + 1)
	width = niter / refresh + 1;

    for (int i = 0; i < width - 1; ++i) {
	std::cout << "-";
    }
    std::cout << "| " << std::min(width * refresh, niter) << std::endl 
	      << std::flush;

    int col = 0;
    for (long n = niter; n > 0; n -= refresh) {
	long nupdate = std::min(n, refresh);
	if(Jtry_dump(console->update(nupdate)))
	    std::cout << "+" << std::flush;
	else {
	    std::cout << std::endl;
	    return;
	}
	col++;
	if (col == width || n <= nupdate) {
	    int percent = 100 - (n-nupdate) * 100/niter;
	    std::cout << " " << percent << "%" << std::endl;
	    if (n > nupdate) {
		col = 0;
	    }
	}
    }
    if (!console->checkAdaptation(status)) {
	std::cout << std::endl;
	errordump();
	return;
    }
    if (!status) {
	std::cerr << "Adaptation incomplete.\n";
    }
    else {
	std::cerr << "Adaptation successful\n";
    }
}

static void loadModule(std::string const &name)
{
    std::cout << "Loading module: " << name;
    lt_dlhandle mod = lt_dlopenext(name.c_str());
    if (mod == NULL) {
	std::cout << ": " << lt_dlerror() << std::endl;
    }
    else {
	std::cout << ": ok" << std::endl;
	_dyn_lib.push_front(mod);
	jags::Console::loadModule(name);
    }
}

static void unloadModule(std::string const &name)
{
    std::cout << "Unloading module: " << name << std::endl;
    jags::Console::unloadModule(name);
}

int main (int argc, char **argv)
{
  extern std::FILE *zzin;

  std::FILE *cmdfile = 0;
  if (argc > 2) {
    std::cerr << "Too many arguments" << std::endl;
  }
  else if (argc == 2) {
    interactive = false;
    cmdfile = std::fopen(ExpandFileName(argv[1]).c_str(),"r");
    if (cmdfile) {
      zzin = cmdfile;
    }
    else {
      std::cerr << "Unable to open command file " << argv[1] << std::endl;
      return 1;
    }
  }
  else {
    interactive = true;
  }

#ifndef _WIN32
  /* 
     - Allows emulation of dynamic loading on platforms that do not
     support it by preloading modules. 
     - Causes build failures on mingw-w64 (as at 21 April 2010) so
     not used on Windows platform.
  */
  LTDL_SET_PRELOADED_SYMBOLS();
#endif

  if(lt_dlinit()) {
      std::cerr << lt_dlerror() << std::endl;
      return 1;
  }

  /*
  pt2Func load_base = (pt2Func)(lt_dlsym(base, "load"));
  if (load_base == NULL) {
      std::cout << lt_dlerror() << std::endl;
      return 1;
  }
  else{
      (*load_base)();
  }
  */
  
  time_t t;
  time(&t);
  std::cout << "Welcome to " << PACKAGE_STRING << " on " << ctime(&t);
  std::cout << "JAGS is free software and comes with ABSOLUTELY NO WARRANTY" 
            << std::endl;
  loadModule("basemod");
  loadModule("bugs");

  console = new jags::Console(std::cout, std::cerr);

  zzparse();
  zzlex_destroy();

  if (argc==2) {
      std::fclose(cmdfile);
  }
  
  //Unload modules
  std::vector<std::string> mods = jags::Console::listModules();
  for (unsigned int i = 0; i < mods.size(); ++i) {
      jags::Console::unloadModule(mods[i]);
  }
  delete console;
  //Release dynamic libraries. 
  for (unsigned int i = 0; i < _dyn_lib.size(); ++i) {
      lt_dlclose(_dyn_lib[i]);
  }
  lt_dlexit();
}

static bool getWorkingDirectory(std::string &name)
{
    char buf[FILENAME_MAX];
#ifdef Win32
    if (getCurrentDirectory(FILENAME_MAX, buf)) {
	name = buf;
	return true;
    }
    else {
	name = "Error in getCurrentDirectory";
	return false;
    }
#else
    if (getcwd(buf, FILENAME_MAX)) {
	name = buf;
	return true;
    }
    else {
	switch(errno) {
	case EACCES:
	    name = "Access denied";
	    break;
	case ENOENT:
	    name = "Not found";
	    break;
	case ERANGE:
	    name = "Directory name too long";
	    break;
	default:
	    name = "Error in getcwd";
	    break;
	}
	return false;
    }
#endif
}

static void dumpSamplers(std::string const &file)
{
    std::ofstream out(file.c_str());
    if (!out) {
	std::cerr << "Failed to open file " << file << std::endl;
	return;
    }

    std::vector<std::vector<std::string> > sampler_list;
    console->dumpSamplers(sampler_list);
    for (unsigned int i = 0; i < sampler_list.size(); ++i) {
	for (unsigned int j = 1; j < sampler_list[i].size(); ++j) {
	    out << i + 1 << "\t" 
		<< sampler_list[i][0] << "\t" //First element is sampler name
		<< sampler_list[i][j] << "\n"; //Rest are node names
	}
    }

    out.close();
}

static void delete_pvec(std::vector<jags::ParseTree*> *pv)
{
    for (unsigned int i = 0; i < pv->size(); ++i) {
	delete (*pv)[i];
    }
    delete pv;
}

static void print_unused_variables(std::map<std::string, jags::SArray> const &table,
				   bool data)
{
    std::vector<std::string> supplied_vars;
    for (std::map<std::string, jags::SArray>::const_iterator p = table.begin();
	 p != table.end(); ++p)
    {
	supplied_vars.push_back(p->first);
    }
    
    std::vector<std::string> unused_vars;
    std::vector<std::string> model_vars = console->variableNames();
    if (!data) {
	// Initial values table may legitimately contain these names
	model_vars.push_back(".RNG.name");
	model_vars.push_back(".RNG.seed");
	model_vars.push_back(".RNG.state");
    }
	
	// Make sure both vectors are sorted to avoid false positive WARNINGs:
	std::sort(model_vars.begin(), model_vars.end());
	std::sort(supplied_vars.begin(), supplied_vars.end());
	
	/*  Test code to check vectors:
	if(data){
		std::cout << "Variables in model:\n";
		std::copy(model_vars.begin(), model_vars.end(),
			  std::ostream_iterator<std::string>(std::cout, ", "));
		std::cout << "\n";

		std::cout << "Supplied vars:\n";
		std::copy(supplied_vars.begin(), supplied_vars.end(),
			  std::ostream_iterator<std::string>(std::cout, ", "));
		std::cout << "\n";
	}  
	*/
	
    std::set_difference(supplied_vars.begin(), supplied_vars.end(),
			model_vars.begin(), model_vars.end(),
			std::inserter(unused_vars, unused_vars.begin()));

    if (!unused_vars.empty()) {
	std::cerr << "\nWARNING: Unused variable(s) in ";
	if (data) {
	    std::cerr << "data table:\n";
	}
	else {
	    std::cerr << "initial value table:\n";
	}
	std::copy(unused_vars.begin(), unused_vars.end(),
		  std::ostream_iterator<std::string>(std::cerr, "\n"));
	std::cerr << "\n";
    }

}

std::string ExpandFileName(char const *s)
{
    if(s[0] != '~') return s;
    std::string name = s;
    if(name.size() > 1 && s[1] != '/') return s;

    char const *p = getenv("HOME");
    if (p) {
	std::string UserHOME = p;
	if (!UserHOME.empty()) {
	    if (name.size() == 1) 
		return UserHOME;
	    else
		return UserHOME + name.substr(1);
	}
    }
    return name;
}


void doSystem(std::string const *command)
{
    std::system(command->c_str());
}

void listModules(){
  std::vector<std::string> mods = jags::Console::listModules();
  std::cout << "Modules:" << std::endl;
  for (unsigned int i = 0; i < mods.size(); ++i) {
      std::cout << "  " << mods[i] << std::endl;
  }
}


void listFactories(jags::FactoryType type)
{
    std::vector<std::pair<std::string, bool> > faclist = 
	jags::Console::listFactories(type);

    std::vector<std::pair<std::string, bool> >::const_iterator p;
    unsigned int max_strlen = 0;
    for (p = faclist.begin(); p != faclist.end(); ++p) {
	if (p->first.length() > max_strlen)
	    max_strlen = p->first.length();
    }
    if (max_strlen < 4)
	max_strlen = 4;

    //Header
    std::cout << "Name";
    for (int i = max_strlen - 4; i >=0; --i) {
	std::cout << " ";
    }
    std::cout << "Status\n";

    //Body
    for (p = faclist.begin(); p != faclist.end(); ++p) {
	std::cout << p->first << " ";
	for (int i = max_strlen - p->first.length(); i >= 0; --i) {
	    std::cout << " ";
	}
	if (p->second) {
	    std::cout << "on";
	}
	else {
	    std::cout << "off";
	}
	std::cout << "\n";
    }
}

void setFactory(std::string const &name, jags::FactoryType type, 
		std::string const &status)
{
    if (status == "on") {
	jags::Console::setFactoryActive(name, type, true);
    }
    else if (status == "off") {
	jags::Console::setFactoryActive(name, type, false);
    }
    else {
	std::cout << "status should be \"on\" or \"off\"";
    }
}

void setSeed(unsigned int seed)
{
    if (seed == 0) {
	std::cout << "seed must be non-zero";
    }
    else {
	jags::Console::setRNGSeed(seed);
    }
}
	    
bool Jtry(bool ok)
{
    if (!ok && !interactive) 
	exit(1);
    else
	return ok;
}

bool Jtry_dump(bool ok)
{
	// Allows doDump to work as described in the manual:
	if (!ok) {
	errordump();
	console->clearModel();
    if (!interactive) 
	exit(1);
	}
	return ok;
}
