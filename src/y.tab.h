/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOLEAN = 258,
    CHAR = 259,
    BYTE = 260,
    SHORT = 261,
    INT = 262,
    LONG = 263,
    FLOAT = 264,
    DOUBLE = 265,
    VOID = 266,
    EXTENDS = 267,
    SUPER = 268,
    STRING = 269,
    THIS = 270,
    VAR = 271,
    INSTANCEOF = 272,
    FINAL = 273,
    NEW = 274,
    CHARACTERLITERAL = 275,
    STRINGLITERAL = 276,
    TEXTBLOCK = 277,
    NULLLITERAL = 278,
    CLASS = 279,
    PACKAGE = 280,
    IMPORT = 281,
    STATIC = 282,
    DO = 283,
    INTEGERLITERAL = 284,
    FLOATINGPOINTLITERAL = 285,
    BOOLEANLITERAL = 286,
    JAVALETTER = 287,
    JAVALETTERORDIGIT = 288,
    OPEN = 289,
    MODULE = 290,
    REQUIRES = 291,
    EXPORTS = 292,
    OPENS = 293,
    USES = 294,
    PROVIDES = 295,
    TO = 296,
    WITH = 297,
    TRANSITIVE = 298,
    LEFTSQUAREBRACKET = 299,
    RIGHTSQUAREBRACKET = 300,
    LEFTCURLYBRACKET = 301,
    RIGHTCURLYBRACKET = 302,
    LEFTPARENTHESIS = 303,
    RIGHTPARENTHESIS = 304,
    SEMICOLON = 305,
    COMMA = 306,
    DOT = 307,
    ELLIPSIS = 308,
    AT = 309,
    DOUBLECOLON = 310,
    ASSIGN = 311,
    GRT = 312,
    LSS = 313,
    NOT = 314,
    TIL = 315,
    QUES = 316,
    COL = 317,
    ARW = 318,
    EQUAL = 319,
    GEQ = 320,
    IMPLEMENTS = 321,
    LEQ = 322,
    NEQUAL = 323,
    AND = 324,
    OR = 325,
    INCRE = 326,
    DECRE = 327,
    PLUS = 328,
    MINUS = 329,
    MULT = 330,
    DIV = 331,
    BAND = 332,
    BOR = 333,
    BXOR = 334,
    MOD = 335,
    LSHIFT = 336,
    RSHIFT = 337,
    UNRSHIFT = 338,
    PLUSEQUAL = 339,
    MINUSEQUAL = 340,
    MULTEQUAL = 341,
    DIVEQUAL = 342,
    BANDEQUAL = 343,
    BOREQUAL = 344,
    BXOREQUAL = 345,
    MODEQUAL = 346,
    LSHIFTEQUAL = 347,
    RSHIFTEQUAL = 348,
    UNRSHIFTEQUAL = 349,
    IF = 350,
    ELSE = 351,
    WHILE = 352,
    FOR = 353,
    RETURN = 354,
    CONTINUE = 355,
    BREAK = 356,
    YIELD = 357,
    SEALED = 358,
    PROTECTED = 359,
    PUBLIC = 360,
    PRIVATE = 361,
    STRICTFP = 362,
    ABSTRACT = 363,
    DEFAULT = 364,
    INTERFACE = 365,
    PERMITS = 366,
    NONSEALED = 367,
    TRANSIENT = 368,
    VOLATILE = 369,
    NATIVE = 370,
    SYNCHRONIZED = 371,
    THROWS = 372,
    ASSERT = 373,
    IDENTIFIER = 374,
    RECORD = 375,
    LRSQUAREBRACKET = 376,
    SYSTEMOUTPRINTLN = 377
  };
#endif
/* Tokens.  */
#define BOOLEAN 258
#define CHAR 259
#define BYTE 260
#define SHORT 261
#define INT 262
#define LONG 263
#define FLOAT 264
#define DOUBLE 265
#define VOID 266
#define EXTENDS 267
#define SUPER 268
#define STRING 269
#define THIS 270
#define VAR 271
#define INSTANCEOF 272
#define FINAL 273
#define NEW 274
#define CHARACTERLITERAL 275
#define STRINGLITERAL 276
#define TEXTBLOCK 277
#define NULLLITERAL 278
#define CLASS 279
#define PACKAGE 280
#define IMPORT 281
#define STATIC 282
#define DO 283
#define INTEGERLITERAL 284
#define FLOATINGPOINTLITERAL 285
#define BOOLEANLITERAL 286
#define JAVALETTER 287
#define JAVALETTERORDIGIT 288
#define OPEN 289
#define MODULE 290
#define REQUIRES 291
#define EXPORTS 292
#define OPENS 293
#define USES 294
#define PROVIDES 295
#define TO 296
#define WITH 297
#define TRANSITIVE 298
#define LEFTSQUAREBRACKET 299
#define RIGHTSQUAREBRACKET 300
#define LEFTCURLYBRACKET 301
#define RIGHTCURLYBRACKET 302
#define LEFTPARENTHESIS 303
#define RIGHTPARENTHESIS 304
#define SEMICOLON 305
#define COMMA 306
#define DOT 307
#define ELLIPSIS 308
#define AT 309
#define DOUBLECOLON 310
#define ASSIGN 311
#define GRT 312
#define LSS 313
#define NOT 314
#define TIL 315
#define QUES 316
#define COL 317
#define ARW 318
#define EQUAL 319
#define GEQ 320
#define IMPLEMENTS 321
#define LEQ 322
#define NEQUAL 323
#define AND 324
#define OR 325
#define INCRE 326
#define DECRE 327
#define PLUS 328
#define MINUS 329
#define MULT 330
#define DIV 331
#define BAND 332
#define BOR 333
#define BXOR 334
#define MOD 335
#define LSHIFT 336
#define RSHIFT 337
#define UNRSHIFT 338
#define PLUSEQUAL 339
#define MINUSEQUAL 340
#define MULTEQUAL 341
#define DIVEQUAL 342
#define BANDEQUAL 343
#define BOREQUAL 344
#define BXOREQUAL 345
#define MODEQUAL 346
#define LSHIFTEQUAL 347
#define RSHIFTEQUAL 348
#define UNRSHIFTEQUAL 349
#define IF 350
#define ELSE 351
#define WHILE 352
#define FOR 353
#define RETURN 354
#define CONTINUE 355
#define BREAK 356
#define YIELD 357
#define SEALED 358
#define PROTECTED 359
#define PUBLIC 360
#define PRIVATE 361
#define STRICTFP 362
#define ABSTRACT 363
#define DEFAULT 364
#define INTERFACE 365
#define PERMITS 366
#define NONSEALED 367
#define TRANSIENT 368
#define VOLATILE 369
#define NATIVE 370
#define SYNCHRONIZED 371
#define THROWS 372
#define ASSERT 373
#define IDENTIFIER 374
#define RECORD 375
#define LRSQUAREBRACKET 376
#define SYSTEMOUTPRINTLN 377

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 309 "parser.yacc"

    struct Node* node;
	char* lexeme;

#line 306 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
