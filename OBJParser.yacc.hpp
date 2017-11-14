/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_OBJPARSER_OBJPARSER_YACC_HPP_INCLUDED
# define YY_OBJPARSER_OBJPARSER_YACC_HPP_INCLUDED
/* Enabling traces.  */
#ifndef OBJPARSERDEBUG
# if defined YYDEBUG
#  if YYDEBUG
#   define OBJPARSERDEBUG 1
#  else
#   define OBJPARSERDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define OBJPARSERDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined OBJPARSERDEBUG */
#if OBJPARSERDEBUG
extern int OBJParserdebug;
#endif

/* Tokens.  */
#ifndef OBJPARSERTOKENTYPE
# define OBJPARSERTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum OBJParsertokentype {
     NUMBER = 258,
     COMMENT = 259,
     VERTEX = 260,
     VERTEX_TEXTURE = 261,
     VERTEX_NORMAL = 262,
     PARAMETER_SPACE_VERTEX = 263,
     DEGREE = 264,
     BASIS_MATRIX = 265,
     STEP_SIZE = 266,
     CURVE_OR_SURFACE_TYPE = 267,
     POINT = 268,
     LINE = 269,
     FACE = 270,
     CURVE = 271,
     CURVE_2D = 272,
     SURFACE = 273,
     PARAMETER_VALUES = 274,
     OUTER_TRIMMING_LOOP = 275,
     INNER_TRIMMING_LOOP = 276,
     SPECIAL_CURVE = 277,
     SPECIAL_POINT = 278,
     END = 279,
     CONNECT = 280,
     GROUP_NAME = 281,
     SMOOTHING_GROUP = 282,
     MERGING_GROUP = 283,
     OBJECT_NAME = 284,
     BEVEL_INTERPOLATION = 285,
     COLOR_INTERPOLATION = 286,
     DISSOLVE_INTERPOLATION = 287,
     LEVEL_OF_DETAIL = 288,
     MATERIAL_NAME = 289,
     MATERIAL_LIBRARY = 290,
     SHADOW_CASTING = 291,
     RAY_TRACING = 292,
     CURVE_APPROX_TECHNIQUE = 293,
     SURFACE_APPROX_TECHNIQUE = 294
   };
#endif


#if ! defined OBJPARSERSTYPE && ! defined OBJPARSERSTYPE_IS_DECLARED
typedef union OBJPARSERSTYPE
{
/* Line 2058 of yacc.c  */
#line 26 "parser.y"

    int     line_number;
  double	number;
  char		comment[1024];
  char		vertex[1024];
  char		vertexTexture[1024];
  char		vertexNormal[1024];
  char		parameterSpaceVertex[1024];
  char		degree[1024];
  char		basisMatrix[1024];
  char		stepSize[1024];
  char		curveOrSurfaceType[1024];
  char		point[1024];
  char		line[1024];
  char		face[1024];
  char		curve[1024];
  char		curve2D[1024];
  char		surface[1024];
  char		parameterValues[1024];
  char		outerTrimmingLoop[1024];
  char		innerTrimmingLoop[1024];
  char		specialCurve[1024];
  char		specialPoint[1024];
  char		end[1024];
  char		_connect[1024];
  char		groupName[1024];
  char		smoothingGroup[1024];
  char		mergingGroup[1024];
  char		objectName[1024];
  char		bevelInterpolation[1024];
  char		colorInterpolation[1024];
  char		dissolveInterpolation[1024];
  char		levelOfDetail[1024];
  char		materialName[1024];
  char		materialLibrary[1024];
  char		shadowCasting[1024];
  char		rayTracing[1024];
  char		curveApproxTechnique[1024];
  char		surfaceApproxTechnique[1024];


/* Line 2058 of yacc.c  */
#line 146 "OBJParser.yacc.hpp"
} OBJPARSERSTYPE;
# define OBJPARSERSTYPE_IS_TRIVIAL 1
# define OBJParserstype OBJPARSERSTYPE /* obsolescent; will be withdrawn */
# define OBJPARSERSTYPE_IS_DECLARED 1
#endif

extern OBJPARSERSTYPE OBJParserlval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int OBJParserparse (void *YYPARSE_PARAM);
#else
int OBJParserparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int OBJParserparse (void);
#else
int OBJParserparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_OBJPARSER_OBJPARSER_YACC_HPP_INCLUDED  */
