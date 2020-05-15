#ifndef MATRIX_4X4_H
#define MATRIX_4X4_H



template <class T>

class Mat4x4
{
public:
	// Likely better for 
	//std::vector<std::vector<T>> matrix;
	//static const int rows = 4;
	//static const int columns = 4;

	// Plain Array Method
	T mat[16] = { 0 };

	// Sets everything to zero by default
	// Make sure you set to identity before using
	Mat4x4()
	{
		mat[0] = 0;
		mat[4] = 0;
		mat[8] = 0;
		mat[12] = 0;

		mat[1] = 0;
		mat[5] = 0;
		mat[9] = 0;
		mat[13] = 0;

		mat[2] = 0;
		mat[6] = 0;
		mat[10] = 0;
		mat[14] = 0;

		mat[3] = 0;
		mat[7] = 0;
		mat[10] = 0;
		mat[15] = 0;
	}
	Mat4x4(T id)
	{
		mat[0] = 1;
		mat[5] = 1;
		mat[10] = 1;
		mat[15] = 1;
	}

	Mat4x4(T m0, T m4, T m8, T m12,
		T m1, T m5, T m9, T m13,
		T m2, T m6, T m10, T m14,
		T m3, T m7, T m11, T m15)
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

	~Mat4x4() {}

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
	void PrintMatrix()
	{
		std::cout << "[" << mat[0] << ", " << mat[4] << ", " << mat[8] << ", " << mat[12] << std::endl;
		std::cout << mat[1] << ", " << mat[5] << ", " << mat[9] << ", " << mat[13] << std::endl;
		std::cout << mat[2] << ", " << mat[6] << ", " << mat[10] << ", " << mat[14] << std::endl;
		std::cout << mat[3] << ", " << mat[7] << ", " << mat[11] << ", " << mat[15] << "]" << std::endl;
	}
	Mat4x4& ZeroTranslate();
	Mat4x4& Inverse();	
	Mat4x4& ScalarMultiply(const Mat4x4& mat);

public:
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
	Mat4x4& operator+ (const Mat4x4& rhs);
	Mat4x4& operator+= (const Mat4x4& rhs);
	// Multiplication by scalar
	const Mat4x4& operator* (const T rhs);
	Mat4x4& operator*= (const Mat4x4& rhs);



protected:
	// For when needing to implement functions such as 
	// range checks done within matrices or when multiplying
};


#endif

