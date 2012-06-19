/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_INTEGER = 258,
     KW_FLOATING = 259,
     KW_BOOLEAN = 260,
     KW_CHARACTER = 261,
     KW_DECLARE = 262,
     KW_IF = 263,
     KW_THEN = 264,
     KW_ELSE = 265,
     KW_WHILE = 266,
     KW_DO = 267,
     KW_INPUT = 268,
     KW_RETURN = 269,
     KW_OUTPUT = 270,
     OPERATOR_LE = 271,
     OPERATOR_GE = 272,
     OPERATOR_EQ = 273,
     OPERATOR_NE = 274,
     OPERATOR_AND = 275,
     OPERATOR_OR = 276,
     TK_IDENTIFIER = 277,
     LIT_INTEGER = 278,
     LIT_FLOATING = 279,
     LIT_FALSE = 280,
     LIT_TRUE = 281,
     LIT_CHARACTER = 282,
     LIT_STRING = 283,
     TOKEN_ERROR = 284
   };
#endif
/* Tokens.  */
#define KW_INTEGER 258
#define KW_FLOATING 259
#define KW_BOOLEAN 260
#define KW_CHARACTER 261
#define KW_DECLARE 262
#define KW_IF 263
#define KW_THEN 264
#define KW_ELSE 265
#define KW_WHILE 266
#define KW_DO 267
#define KW_INPUT 268
#define KW_RETURN 269
#define KW_OUTPUT 270
#define OPERATOR_LE 271
#define OPERATOR_GE 272
#define OPERATOR_EQ 273
#define OPERATOR_NE 274
#define OPERATOR_AND 275
#define OPERATOR_OR 276
#define TK_IDENTIFIER 277
#define LIT_INTEGER 278
#define LIT_FLOATING 279
#define LIT_FALSE 280
#define LIT_TRUE 281
#define LIT_CHARACTER 282
#define LIT_STRING 283
#define TOKEN_ERROR 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 15 "parser.y"

	ASTREE *astree;
	HASH_ELEMENT *symbol;



/* Line 2068 of yacc.c  */
#line 115 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


