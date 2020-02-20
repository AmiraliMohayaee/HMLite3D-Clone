#include "Transformation.h"

namespace Transformation
{
	// To-do change all the return types as they don't fully comply 
	// to the templated matrix for some reason
	Mat4x4<float> Transformation::Translation(Mat4x4<float> mat, Vec3<float>& vec)
	{
		Mat4x4<float> result(mat);

		result.mat[12] = mat.mat[12] * vec.x;
		result.mat[13] = mat.mat[13] * vec.y;
		result.mat[14] = mat.mat[14] * vec.z;

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