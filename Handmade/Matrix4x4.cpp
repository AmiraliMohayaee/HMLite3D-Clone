#include "Matrix4x4.h"
#include <iostream>
#include "Vec3.h"
//#include "Vec4.h"


template<class T>
Mat4x4<T>& Mat4x4<T>::ZeroTranslate()
{
	mat[12], mat[13], mat[14] = 0.0f;
}

template<class T>
Mat4x4<T>& Mat4x4<T>::Inverse()
{
	// TODO: insert return statement here
}



template<class T>
Mat4x4<T>& Mat4x4<T>::operator+(const Mat4x4& rhs)
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


template<class T>
Mat4x4<T>& Mat4x4<T>::operator+=(const Mat4x4& rhs)
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


template<class T>
const Mat4x4<T>& Mat4x4<T>::operator*(const T rhs)
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


template<class T>
Mat4x4<T>& Mat4x4<T>::operator*=(const Mat4x4& rhs)
{
	mat[0] *= rhs;
	mat[4] *= rhs;
	mat[8] *= rhs;
	mat[12] *= rhs;

	mat[1] *= rhs;
	mat[5] *= rhs;
	mat[9] *= rhs;
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

template<class T>
Mat4x4<T>& Mat4x4<T>::ScalarMultiply(const Mat4x4& mat)
{

}