#ifndef MATRIX_4X4_H
#define MATRIX_4X4_H

#include <vector>
#include <iostream>
#include "Vec3.h"
//#include "Vec4.h"


template <class T>

class Mat4x4
{
public:
	// Likely better for 
	//std::vector<std::vector<T>> matrix;
	//static const int rows = 4;
	//static const int columns = 4;

	// Plain Array Method
	float mat[16] = { 0.0f };

	// Sets everything to zero by default
	// Make sure you set to identity before using
	Mat4x4() 
	{
		mat[0] = 0.0f;
		mat[4] = 0.0f;
		mat[8] = 0.0f;
		mat[12] = 0.0f;

		mat[1] = 0.0f;
		mat[5] = 0.0f;
		mat[9] = 0.0f;
		mat[13] = 0.0f;

		mat[2] = 0.0f;
		mat[6] = 0.0f; 
		mat[10] = 0.0f; 
		mat[14] = 0.0f;

		mat[3] = 0.0f;
		mat[7] = 0.0f;
		mat[10] = 0.0f;
		mat[15] = 0.0f;
	}
	Mat4x4(float m0, float m4, float m8, float m12,
		float m1, float m5, float m9, float m13,
		float m2, float m6, float m10, float m14,
		float m3, float m7, float m11, float m15)
	{
		// Individually populating the matrix
		mat[0] = m0;
		mat[4] = m4;
		mat[8] = m8;
		mat[12] = m12;

		mat[1] = m1;
		mat[5] = m5;
		mat[9] = m8;
		mat[13] = m13;

		mat[2] = m2;
		mat[6] = m6;
		mat[10] = m10;
		mat[14] = m14;

		mat[3] = m3;
		mat[7] = m7;
		mat[10] = m10;
		mat[15] = m15;
	}

	~Mat4x4();

	void SetIdentity()
	{
		// Setting the matrix to identity by default
		for (int i = 0; i < 16; i++)
		{
			mat[i] = 0.0f;
		}

		mat[0] = 1.0f;
		mat[5] = 1.0f;
		mat[10] = 1.0f;
		mat[15] = 1.0f;
	}
	void DrawMatrix()
	{
		std::cout << "[" << mat[0] << ", " << mat[4] << ", " << mat[8] << ", " << mat[12] << std::endl;
		std::cout << mat[1] << ", " << mat[5] << ", " << mat[9] << ", " << mat[13] << std::endl;
		std::cout << mat[2] << ", " << mat[6] << ", " << mat[10] << ", " << mat[14] << std::endl;
		std::cout << mat[3] << ", " << mat[7] << ", " << mat[11] << ", " << mat[15] << "]" << std::endl;
	}
	void ZeroTranslate()
	{
		mat[12], mat[13], mat[14] = 0.0f;
	}

	Mat4x4& operator= (const Mat4x4& rhs)
	{
		Mat4x4 result;

		result.mat[0] = rhs.mat[0];
		result.mat[4] = rhs.mat[4];
		result.mat[8] = rhs.mat[8];
		result.mat[12] = rhs.mat[12];

		result.mat[1] = rhs.mat[1];
		result.mat[5] = rhs.mat[5];
		result.mat[9] = rhs.mat[9];
		result.mat[13] = rhs.mat[13];

		result.mat[2] = rhs.mat[2];
		result.mat[6] = rhs.mat[6];
		result.mat[10] = rhs.mat[10];
		result.mat[14] = rhs.mat[14];

		result.mat[3] = rhs.mat[3];
		result.mat[7] = rhs.mat[7];
		result.mat[10] = rhs.mat[10];
		result.mat[15] = rhs.mat[15];

		return result;
	}
	Mat4x4& operator+ (const Mat4x4& rhs)
	{
		Mat4x4 result;

		result.mat[0] = mat[0] + rhs.mat[0];
		result.mat[4] = mat[4] + rhs.mat[4];
		result.mat[8] = mat[8] + rhs.mat[8];
		result.mat[12] = mat[12] + rhs.mat[12];

		result.mat[1] = mat[1] + rhs.mat[1];
		result.mat[5] = mat[5] + rhs.mat[5];
		result.mat[9] = mat[9] + rhs.mat[9];
		result.mat[13] = mat[13] + rhs.mat[13];

		result.mat[2] = mat[2] + rhs.mat[2];
		result.mat[6] = mat[6] + rhs.mat[6];
		result.mat[10] = mat[10] + rhs.mat[10];
		result.mat[14] = mat[14] + rhs.mat[14];

		result.mat[3] = mat[3] + rhs.mat[3];
		result.mat[7] = mat[7] + rhs.mat[7];
		result.mat[10] = mat[10] + rhs.mat[10];
		result.mat[15] = mat[15] + rhs.mat[15];

		return result;
	}
	Mat4x4& operator+= (const Mat4x4& rhs)
	{
		result.mat[0] += rhs.mat[0];
		result.mat[4] += rhs.mat[4];
		result.mat[8] += rhs.mat[8];
		result.mat[12] += rhs.mat[12];

		result.mat[1] += rhs.mat[1];
		result.mat[5] += rhs.mat[5];
		result.mat[9] += rhs.mat[9];
		result.mat[13] += rhs.mat[13];

		result.mat[2] += rhs.mat[2];
		result.mat[6] += rhs.mat[6];
		result.mat[10] += rhs.mat[10];
		result.mat[14] += rhs.mat[14];

		result.mat[3] += rhs.mat[3];
		result.mat[7] += rhs.mat[7];
		result.mat[10] += rhs.mat[10];
		result.mat[15] += rhs.mat[15];
	}
	// Multiplication by scalar
	const Mat4x4& operator* (const float rhs)
	{
		Mat4x4 result;

		result.mat[0] = mat[0] * rhs;
		result.mat[4] = mat[4] * rhs;
		result.mat[8] = mat[8] * rhs;
		result.mat[12] = mat[12] * rhs;

		result.mat[1] = mat[1] * rhs;
		result.mat[5] = mat[5] * rhs;
		result.mat[9] = mat[9] * rhs;
		result.mat[13] = mat[13] * rhs;

		result.mat[2] = mat[2] * rhs;
		result.mat[6] = mat[6] * rhs;
		result.mat[10] = mat[10] * rhs;
		result.mat[14] = mat[14] * rhs;

		result.mat[3] = mat[3] * rhs;
		result.mat[7] = mat[7] * rhs;
		result.mat[10] = mat[10] * rhs;
		result.mat[15] = mat[15] * rhs;

		return result;
	}
	Mat4x4& operator*= (const Mat4x4& rhs)
	{
		mat[0] *= rhs;
		mat[4] *= rhs;
		mat[8] *= rhs;
		mat[12] *= rhs;

		mat[1] *=  rhs;
		mat[5] *=  rhs;
		mat[9] *=  rhs;
		mat[13] *= rhs;

		mat[2] *= rhs;
		mat[6] *= rhs;
		mat[10] *= rhs;
		mat[14] *= rhs;

		mat[3] *= rhs;
		mat[7] *= rhs;
		mat[10] *= rhs;
		mat[15] *= rhs;
	}

	Mat4x4& Multiply(const Mat4x4& mat)
	{

	}

protected:
	// For when needing to implement functions such as 
	// range checks done within matrices or when multiplying
};


#endif