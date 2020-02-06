#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "Matrix4x4.h"


class Transformation
{
public:
	Transformation();

	Mat4x4 Translation(Mat4x4 mat, Vec3<float>& vec);
	Mat4x4 Rotation();
	Mat4x4 Scale();


	


};


#endif