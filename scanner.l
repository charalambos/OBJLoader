%option prefix="OBJLoader"
%option noyywrap
%option always-interactive
%{
//////////////////////////////////////////////////////////////////////////////////////
// Copyright © Charalambos "Charis" Poullis, charalambos@poullis.org                //
// http://www.poullis.org                                                           //
//////////////////////////////////////////////////////////////////////////////////////

/* need this for the call to atof() below */
#include <stdio.h>
#include <math.h>
#include "OBJLoader.h"
#include "OBJLoader.yacc.hpp"
%}

_D [0-9]
_E [eE][+-]?{_D}+
_N [+-]?({_D}+|{_D}+"."{_D}*|{_D}*"."{_D}+)({_E})?
_COMMENT "#"[^\n]*
_VERTEX "v"
_VERTEX_TEXTURE "vt"
_VERTEX_NORMAL "vn"
_PARAMETER_SPACE_VERTEX "vp"
_DEGREE "deg"
_BASIS_MATRIX "bmat"
_STEP_SIZE "step"
_CURVE_OR_SURFACE_TYPE "cstype"
_POINT "p"
_LINE "l"
_FACE "f"
_CURVE "curv"
_CURVE_2D "curv2"
_SURFACE "surf"
_PARAMETER_VALUES "parm"
_OUTER_TRIMMING_LOOP "trim"
_INNER_TRIMMING_LOOP "hole"
_SPECIAL_CURVE "scrv"
_SPECIAL_POINT "sp"
_END "end"
_CONNECT "con"
_GROUP_NAME "g"[ \t]+[^\n]*
_SMOOTHING_GROUP "s"[ \t]+[^\n]*
_MERGING_GROUP "mg"
_OBJECT_NAME "o"
_BEVEL_INTERPOLATION "bevel"
_COLOR_INTERPOLATION "c_interp"
_DISSOLVE_INTERPOLATION "d_interp"
_LEVEL_OF_DETAIL "lod"
_MATERIAL_NAME "usemtl"[ \t]+[^\n]*
_MATERIAL_LIBRARY "mtllib"[ \t]+[^\n]*
_SHADOW_CASTING "shadow_obj"
_RAY_TRACING "trace_obj"
_CURVE_APPROX_TECHNIQUE "ctech"
_SURFACE_APPROX_TECHNIQUE "stech"

%%

" "                         {;}
"\t"                        {;}
"\r"                        {;}
"\n"                        {return '\n';}
"/"                         {return '/';}
{_COMMENT}                  {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.comment,yytext); return COMMENT;}
{_N}                        {/*printf("%lf",(double)atof(yytext));*/OBJLoaderlval.number = atof(yytext); return NUMBER;}
{_VERTEX}                   {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.vertex,yytext);return VERTEX;}
{_VERTEX_TEXTURE}           {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.vertexTexture,yytext);return VERTEX_TEXTURE;}
{_VERTEX_NORMAL}            {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.vertexNormal,yytext);return VERTEX_NORMAL;}
{_PARAMETER_SPACE_VERTEX}   {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.parameterSpaceVertex,yytext);return PARAMETER_SPACE_VERTEX;}
{_DEGREE}                   {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.degree,yytext);return DEGREE;}
{_BASIS_MATRIX}             {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.basisMatrix,yytext);return BASIS_MATRIX;}
{_STEP_SIZE}                {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.stepSize,yytext);return STEP_SIZE;}
{_CURVE_OR_SURFACE_TYPE}    {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.curveOrSurfaceType,yytext);return CURVE_OR_SURFACE_TYPE;}
{_POINT}                    {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.point,yytext);return POINT;}
{_LINE}                     {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.line,yytext);return LINE;}
{_FACE}                     {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.face,yytext);return FACE;}
{_CURVE}                    {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.curve,yytext);return CURVE;}
{_CURVE_2D}                 {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.curve2D,yytext);return CURVE_2D;}
{_SURFACE}                  {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.surface,yytext);return SURFACE;}
{_PARAMETER_VALUES}         {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.parameterValues,yytext);return PARAMETER_VALUES;}
{_OUTER_TRIMMING_LOOP}      {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.outerTrimmingLoop,yytext);return OUTER_TRIMMING_LOOP;}
{_INNER_TRIMMING_LOOP}      {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.innerTrimmingLoop,yytext);return INNER_TRIMMING_LOOP;}
{_SPECIAL_CURVE}            {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.specialCurve,yytext);return SPECIAL_CURVE;}
{_SPECIAL_POINT}            {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.specialPoint,yytext);return SPECIAL_POINT;}
{_END}                      {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.end,yytext);return END;}
{_CONNECT}                  {/*printf("%s",yytext);*/strcpy(OBJLoaderlval._connect,yytext);return CONNECT;}
{_GROUP_NAME}               {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.groupName,yytext);return GROUP_NAME;}
{_SMOOTHING_GROUP}          {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.smoothingGroup,yytext);return SMOOTHING_GROUP;}
{_MERGING_GROUP}            {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.mergingGroup,yytext);return MERGING_GROUP;}
{_OBJECT_NAME}              {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.objectName,yytext);return OBJECT_NAME;}
{_BEVEL_INTERPOLATION}      {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.bevelInterpolation,yytext);return BEVEL_INTERPOLATION;}
{_COLOR_INTERPOLATION}      {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.colorInterpolation,yytext);return COLOR_INTERPOLATION;}
{_DISSOLVE_INTERPOLATION}   {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.dissolveInterpolation,yytext);return DISSOLVE_INTERPOLATION;}
{_LEVEL_OF_DETAIL}          {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.levelOfDetail,yytext);return LEVEL_OF_DETAIL;}
{_MATERIAL_NAME}            {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.materialName,yytext);return MATERIAL_NAME;}
{_MATERIAL_LIBRARY}         {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.materialLibrary,yytext);return MATERIAL_LIBRARY;}
{_SHADOW_CASTING}           {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.shadowCasting,yytext);return SHADOW_CASTING;}
{_RAY_TRACING}              {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.rayTracing,yytext);return RAY_TRACING;}
{_CURVE_APPROX_TECHNIQUE}   {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.curveApproxTechnique,yytext);return CURVE_APPROX_TECHNIQUE;}
{_SURFACE_APPROX_TECHNIQUE} {/*printf("%s",yytext);*/strcpy(OBJLoaderlval.surfaceApproxTechnique,yytext);return SURFACE_APPROX_TECHNIQUE;}
.                           {printf("FLEX warning(unexpected character): ignoring ");ECHO;printf("\n");}
%%
