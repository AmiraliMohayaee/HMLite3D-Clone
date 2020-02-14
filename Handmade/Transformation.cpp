#include "Transformation.h"

namespace Transformation
{
	// To-do change all the return types as they don't fully comply 
	// to the templated matrix for some reason
	Mat4x4<float> Transformation::Translation(Mat4x4<float> mat, Vec3<float>& vec)
	{
		Mat4x4<float> result(mat);

		result.mat[3] = mat.mat[0] * vec.x +
			mat.mat[12] * vec.y +
			mat.mat[13] * vec.z +
			mat.mat[14];

		return result;
	}

	Mat4x4<float> Transformation::Rotation(const float angle, Vec3<float>& vec)
	{
		//float const a = angle;

		return Mat4x4<float>();
	}

	Mat4x4<float> Transformation::Scale(Mat4x4<float> scaleMat, Vec3<float>& vec)
	{


		return Mat4x4<float>();
	}
}