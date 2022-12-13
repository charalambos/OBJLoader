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

#ifndef YY_OBJLOADER_OBJLOADER_YACC_HPP_INCLUDED
# define YY_OBJLOADER_OBJLOADER_YACC_HPP_INCLUDED
/* Debug traces.  */
#ifndef OBJLOADERDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define OBJLOADERDEBUG 1
#  else
#   define OBJLOADERDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define OBJLOADERDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined OBJLOADERDEBUG */
#if OBJLOADERDEBUG
extern int OBJLoaderdebug;
#endif

/* Token kinds.  */
#ifndef OBJLOADERTOKENTYPE
# define OBJLOADERTOKENTYPE
  enum OBJLoadertokentype
  {
    OBJLOADEREMPTY = -2,
    OBJLOADEREOF = 0,              /* "end of file"  */
    OBJLOADERerror = 256,          /* error  */
    OBJLOADERUNDEF = 257,          /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    COMMENT = 259,                 /* COMMENT  */
    VERTEX = 260,                  /* VERTEX  */
    VERTEX_TEXTURE = 261,          /* VERTEX_TEXTURE  */
    VERTEX_NORMAL = 262,           /* VERTEX_NORMAL  */
    PARAMETER_SPACE_VERTEX = 263,  /* PARAMETER_SPACE_VERTEX  */
    DEGREE = 264,                  /* DEGREE  */
    BASIS_MATRIX = 265,            /* BASIS_MATRIX  */
    STEP_SIZE = 266,               /* STEP_SIZE  */
    CURVE_OR_SURFACE_TYPE = 267,   /* CURVE_OR_SURFACE_TYPE  */
    POINT = 268,                   /* POINT  */
    LINE = 269,                    /* LINE  */
    FACE = 270,                    /* FACE  */
    CURVE = 271,                   /* CURVE  */
    CURVE_2D = 272,                /* CURVE_2D  */
    SURFACE = 273,                 /* SURFACE  */
    PARAMETER_VALUES = 274,        /* PARAMETER_VALUES  */
    OUTER_TRIMMING_LOOP = 275,     /* OUTER_TRIMMING_LOOP  */
    INNER_TRIMMING_LOOP = 276,     /* INNER_TRIMMING_LOOP  */
    SPECIAL_CURVE = 277,           /* SPECIAL_CURVE  */
    SPECIAL_POINT = 278,           /* SPECIAL_POINT  */
    END = 279,                     /* END  */
    CONNECT = 280,                 /* CONNECT  */
    GROUP_NAME = 281,              /* GROUP_NAME  */
    SMOOTHING_GROUP = 282,         /* SMOOTHING_GROUP  */
    MERGING_GROUP = 283,           /* MERGING_GROUP  */
    OBJECT_NAME = 284,             /* OBJECT_NAME  */
    BEVEL_INTERPOLATION = 285,     /* BEVEL_INTERPOLATION  */
    COLOR_INTERPOLATION = 286,     /* COLOR_INTERPOLATION  */
    DISSOLVE_INTERPOLATION = 287,  /* DISSOLVE_INTERPOLATION  */
    LEVEL_OF_DETAIL = 288,         /* LEVEL_OF_DETAIL  */
    MATERIAL_NAME = 289,           /* MATERIAL_NAME  */
    MATERIAL_LIBRARY = 290,        /* MATERIAL_LIBRARY  */
    SHADOW_CASTING = 291,          /* SHADOW_CASTING  */
    RAY_TRACING = 292,             /* RAY_TRACING  */
    CURVE_APPROX_TECHNIQUE = 293,  /* CURVE_APPROX_TECHNIQUE  */
    SURFACE_APPROX_TECHNIQUE = 294 /* SURFACE_APPROX_TECHNIQUE  */
  };
  typedef enum OBJLoadertokentype OBJLoadertoken_kind_t;
#endif

/* Value type.  */
#if ! defined OBJLOADERSTYPE && ! defined OBJLOADERSTYPE_IS_DECLARED
union OBJLOADERSTYPE
{
#line 24 "parser.y"

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

#line 152 "OBJLoader.yacc.hpp"

};
typedef union OBJLOADERSTYPE OBJLOADERSTYPE;
# define OBJLOADERSTYPE_IS_TRIVIAL 1
# define OBJLOADERSTYPE_IS_DECLARED 1
#endif


extern OBJLOADERSTYPE OBJLoaderlval;


int OBJLoaderparse (void);


#endif /* !YY_OBJLOADER_OBJLOADER_YACC_HPP_INCLUDED  */
