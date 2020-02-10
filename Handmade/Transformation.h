#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "Matrix4x4.h"
#include "Vec3.h"


namespace Transformation
{
	Mat4x4<float> Translation(Mat4x4<float> mat, Vec3<float>& vec);
	Mat4x4<float> Rotation(Mat4x4<float> angle, Vec3<float>& vec);
	Mat4x4<float> Scale(Mat4x4<float> scaleMat, Vec3<float>& vec);
};


#endif