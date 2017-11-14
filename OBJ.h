//////////////////////////////////////////////////////////////////////////////////////
// Copyright © Charalambos "Charis" Poullis, charalambos@poullis.org                //
// http://www.poullis.org                                                           //
//////////////////////////////////////////////////////////////////////////////////////


#ifndef __OBJ_H__
#define __OBJ_H__

#include <stdarg.h>
#include <stdio.h>
#include <Eigen/Eigen>
using namespace Eigen;

#include <vector>
using namespace std;

///Face structure has a set of vertex, normal and texture indices.
typedef struct Face	{
	std::vector<int> vertex_indices;
	std::vector<int> normal_indices;
	std::vector<int> texture_indices;
} Face;

///The OBJ class which is used by the parser to populate the information in the structures.
class OBJ	{
	public:
		OBJ();
		~OBJ();
	
		void AddVertex(double vx,double vy,double vz);
		void AddNormal(double nx, double ny,double nz);
		void AddTextureCoord(double tx,double ty);
		void AddFace(std::vector<int> const &vertexIndices,
			     std::vector<int> const &normalIndices,
			     std::vector<int> const &textureIndices);
	
		void Print(void);

        bool has_tex_coords;
        bool has_normals;

	private:
		//structures
		std::vector<Vector3d>	vertices;
		std::vector<Vector3d>	normals;
		std::vector<Vector2d>	texture_coords;
		std::vector<Face *>	faces;
};
#endif
