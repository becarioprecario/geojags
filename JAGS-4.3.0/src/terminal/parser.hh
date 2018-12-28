/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 99 "../../../../../jags-4_patched/src/terminal/parser.yy" /* yacc.c:1909  */

  int intval;
  double val;
  std::string *stringptr;
  jags::ParseTree *ptree;
  std::vector<jags::ParseTree*> *pvec;
  std::vector<double> *vec;
  std::vector<long> *ivec;

#line 178 "parser.hh" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE zzlval;

int zzparse (void);

#endif /* !YY_ZZ_PARSER_HH_INCLUDED  */
