#ifndef MATRIX_4X4_H
#define MATRIX_4X4_H

#include <vector>
#include "Vec3.h"
#include "Vec4.h"


template <class T>

class Mat4x4
{
public:
	std::vector<std::vector<T>> matrix;
	static const int rows = 4;
	static const int columns = 4;

	float mat[4][4] = 
	{
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44
	};

	Mat4x4();
	~Mat4x4();


	Mat4x4& operator= (const Mat4x4& rhs)
	{

	}

	Mat4x4& Multiply(const Mat4x4& rhs)
	{

	}


protected:
	void RangeCheck(

};


#endif