%define api.prefix OBJParser
%{
//////////////////////////////////////////////////////////////////////////////////////
// Copyright © Charalambos "Charis" Poullis, charalambos@poullis.org                //
// http://www.poullis.org                                                           //
// This work is under the Creative Commons Attribution-Noncommercial-Share          //
// Alike 3.0 United States License:                                                 //
// http://creativecommons.org/licenses/by-nc-sa/3.0/us/                             //
////////////////////////////////////////////////////////////////////////////////////// 

#include <stdio.h>
#include <string>
#include "OBJParser.h"
#include "OBJ.h"

extern char *yytext;         // The text of most recent token from the scanner.
int yylex( );                // Prototype for yylex,produced by the scanner.
void yyerror(char * s);      // Function to print an error message

OBJ *obj_model;
std::vector<int> vertexIndices,normalIndices,textureIndices;
int line_number=1;
//GRAMMAR DEFINITION
%}

%union {
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
}

%start parsedLine

%type<line_number>	inputLine
%token <number>		NUMBER
%token <comment>	COMMENT
%token <vertex>		VERTEX  
%token <vertexTexture>	VERTEX_TEXTURE  
%token <vertexNormal>	VERTEX_NORMAL  
%token <parameterSpaceVertex>	PARAMETER_SPACE_VERTEX  
%token <degree>	DEGREE  
%token <basisMatrix>	BASIS_MATRIX  
%token <stepSize>	STEP_SIZE  
%token <curveOrSurfaceType>	CURVE_OR_SURFACE_TYPE  
%token <point>	POINT  
%token <line>	LINE  
%token <face>	FACE  
%token <curve>	CURVE  
%token <curve2D>	CURVE_2D  
%token <surface>	SURFACE  
%token <parameterValues>	PARAMETER_VALUES  
%token <outerTrimmingLoop>	OUTER_TRIMMING_LOOP  
%token <innerTrimmingLoop>	INNER_TRIMMING_LOOP  
%token <specialCurve>	SPECIAL_CURVE  
%token <specialPoint>	SPECIAL_POINT  
%token <end>	END  
%token <_connect>	CONNECT  
%token <groupName>	GROUP_NAME  
%token <smoothingGroup>	SMOOTHING_GROUP  
%token <mergingGroup>	MERGING_GROUP  
%token <objectName>	OBJECT_NAME		 
%token <bevelInterpolation>	BEVEL_INTERPOLATION  
%token <colorInterpolation>	COLOR_INTERPOLATION  
%token <dissolveInterpolation>	DISSOLVE_INTERPOLATION  
%token <levelOfDetail>	LEVEL_OF_DETAIL  
%token <materialName>	MATERIAL_NAME  
%token <materialLibrary>	MATERIAL_LIBRARY  
%token <shadowCasting>	SHADOW_CASTING  
%token <rayTracing>	RAY_TRACING  
%token <curveApproxTechnique>	CURVE_APPROX_TECHNIQUE  
%token <surfaceApproxTechnique>	SURFACE_APPROX_TECHNIQUE  

%%
parsedLine   :	parsedLine inputLine			{ /*printf("YACC: Parsed line: %d\n",$2);*/}
            |	inputLine 				{ /*printf("YACC: Parsed line: %d\n",$1);*/}
	    |	parsedLine error '\n'			{ printf("YACC: The file appears to have the wrong format. Quiting on line %d.\n",line_number); return -1; yyerrok;}
            |	error '\n'				{ printf("YACC: The file appears to have the wrong format. Quiting on line %d.\n",line_number); return -1; yyerrok;}
	    |	parsedLine	'\n'			{ ; }
	    |  	'\n'					{ ; }
	    ; 
inputLine    :	VERTEX	NUMBER	NUMBER	NUMBER	'\n'			{/*printf(" v %lf %lf %lf\n",$2,$3,$4);*/$$=line_number++;obj_model->AddVertex($2,$3,$4);}
             |	VERTEX_TEXTURE	NUMBER	NUMBER	'\n'			{/*printf(" vt %lf %lf\n",$2,$3);*/$$=line_number++;obj_model->has_tex_coords=true; obj_model->AddTextureCoord($2,$3);}
             |	VERTEX_NORMAL	NUMBER	NUMBER	NUMBER	'\n'		{/*printf(" vn %lf %lf %lf\n",$2,$3,$4);*/$$=line_number++;obj_model->has_normals=true; obj_model->AddNormal($2,$3,$4);}
             |	face	'\n'				            	{$$=line_number++;obj_model->AddFace(vertexIndices,normalIndices,textureIndices); vertexIndices.clear();normalIndices.clear();textureIndices.clear();}
             |	materialName	'\n'				        {line_number++;}
             |	materialLibrary	'\n'				        {line_number++;}
             |	groupName	'\n'			            	{line_number++;}
             |	smoothingGroup	'\n'					{line_number++;}
             |	COMMENT	'\n'						{line_number++; printf("Comment: %s\n",$1);}
             ;
face	     : singleFace						{/*printf("\n");*/}
             | pairFace							{/*printf("\n");*/}
             | tripletFace						{/*printf("\n");*/}
             ;
tripletFace	 :	tripletFace	NUMBER	'/'	NUMBER	'/'	NUMBER		{/*printf("%lf/%lf/%lf",$2,$4,$6);*/vertexIndices.push_back(int($2)-1);normalIndices.push_back(int($4)-1);textureIndices.push_back(int($6)-1);}
	        |	pairFace	'/'	NUMBER				        {/*printf("/%lf",$3);*/textureIndices.push_back(int($3)-1);}
		;
pairFace	 :	pairFace	NUMBER	'/''/'	NUMBER				{printf("The format appears to be slightly wrong. Fixing...\n"); vertexIndices.push_back(int($2)-1);if (obj_model->has_normals) {normalIndices.push_back(int($5)-1);} else {if (obj_model->has_tex_coords)	{textureIndices.push_back(int($5)-1);}}}
             	 |	singleFace	'/''/'	NUMBER						{printf("The format appears to be slightly wrong. Fixing...\n"); if (obj_model->has_normals) {normalIndices.push_back(int($4)-1);} else {if (obj_model->has_tex_coords)	{textureIndices.push_back(int($4)-1);}}}
             	 |	pairFace	NUMBER	'/'	NUMBER					{/*printf("%lf/%lf",$2,$4);*/vertexIndices.push_back($2-1);if (obj_model->has_normals) {normalIndices.push_back(int($4)-1);} else {if (obj_model->has_tex_coords)	{textureIndices.push_back(int($4)-1);}}}
	         |	singleFace	'/'	NUMBER						{/*printf("/%lf",$3);*/if (obj_model->has_normals) {normalIndices.push_back(int($3)-1);} else {if (obj_model->has_tex_coords)	{textureIndices.push_back(int($3)-1);}}}
			 ;
singleFace	 :	singleFace	NUMBER				{/*printf(" %lf",$2);*/vertexIndices.push_back(int($2)-1);}
             |	FACE	NUMBER					{/*printf("f %lf", $2);*/vertexIndices.push_back(int($2)-1);}
             ;
materialLibrary: MATERIAL_LIBRARY					{/*printf("Unsupported command: %s\n",$1);*/}
	   	        ;
materialName : MATERIAL_NAME						{/*printf("Unsupported command: %s\n",$1);*/}
		        ;
groupName	 : GROUP_NAME						{/*printf("Unsupported command: %s\n",$1);*/}
		        ;
smoothingGroup:	SMOOTHING_GROUP						{/*printf("Unsupported command: %s\n",$1);*/}
		        ;
			   
%%

void yyerror (char *s) {fprintf(stderr, "%s\n", s);}
