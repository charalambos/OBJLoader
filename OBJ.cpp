//////////////////////////////////////////////////////////////////////////////////////
// Copyright © Charalambos "Charis" Poullis, charalambos@poullis.org                //
// http://www.poullis.org                                                           //
//////////////////////////////////////////////////////////////////////////////////////


#ifndef __OBJ_CPP__
#define __OBJ_CPP__

#include "OBJ.h"

OBJ::OBJ()	{
	faces.clear();
	normals.clear();
	texture_coords.clear();
	vertices.clear();
	has_tex_coords = false;
	has_normals = false;
}

OBJ::~OBJ()	{
	for (unsigned int i=0;i<faces.size();i++)	{
		delete faces[i];
	}	
	faces.clear();
	normals.clear();
	texture_coords.clear();
	vertices.clear();
}

void OBJ::AddFace(std::vector<int> const &vertexIndices,
		  std::vector<int> const &normalIndices,
		  std::vector<int> const &textureIndices)	{
	Face *face = new Face;
	face->vertex_indices = vertexIndices;
	face->normal_indices = normalIndices;
	face->texture_indices = textureIndices;
	faces.push_back(face);
	return;
}

void OBJ::AddNormal(double nx,double ny,double nz)	{
	normals.push_back(Vector3d(nx,ny,nz));
	return;
}

void OBJ::AddTextureCoord(double tx, double ty)	{
	texture_coords.push_back(Vector2d(tx,ty));
	return;
}

void OBJ::AddVertex(double vx,double vy, double vz)	{
	vertices.push_back(Vector3d(vx,vy,vz));
	return;
}

void OBJ::Print(void)	{
	for (int i=0;i<vertices.size();i++)	{
		printf("v %lf %lf %lf\n",vertices[i](0),vertices[i](1),vertices[i](2));
	}
	for (int i=0;i<normals.size();i++)	{
		printf("vn %lf %lf %lf\n",normals[i](0),normals[i](1),normals[i](2));
	}
	for (int i=0;i<texture_coords.size();i++)	{
		printf("vt %lf %lf\n",texture_coords[i](0),texture_coords[i](1));
	}
	std::vector<int> vertexIndices;
	std::vector<int> normalIndices;
	std::vector<int> textureIndices;
	printf("Faces: %d\n",faces.size());

	for (int i=0;i<faces.size();i++)	{
		vertexIndices = faces[i]->vertex_indices;
		normalIndices = faces[i]->normal_indices;
		textureIndices = faces[i]->texture_indices;
		printf("f ");
		for (int j=0;j<vertexIndices.size();j++)	{
			printf("%d",vertexIndices[j]+1);
			if (normalIndices.size()!=0)	{
				printf("/%d",normalIndices[j]);
			}
			if (textureIndices.size()!=0)	{
				printf("/%d",textureIndices[j]);
			}
			printf(" ");
		}
		printf("\n");
	}

    printf("Vertices: %d\n", vertices.size());
    printf("Normals: %d\n", normals.size());
    printf("Faces: %d\n", faces.size());
    printf("Texture coordinates: %d\n", texture_coords.size());
	return;
}
#endif
