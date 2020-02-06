#ifndef VEC3_H
#define VEC3_H

#include <math.h>

const double PI = 3.14159265359;

template <class T>


class Vec3
{
public:
	T x, y, z;

	//Vec3::Backward<T> = Vec3<float>;
	//Vec3::Right<T> = Vec3(1.0f, 0.0f, 0.0f);
	//Vec3::Left<T> = Vec3(-1.0f, 0.0f, 0.0f);
	//Vec3::Up<T> = Vec3(0.0f, 1.0f, 0.0f);
	//Vec3::Down<T> = Vec3(0.0f, -1.0f, 0.0f);

	//static const Vec3<float> Forward(0.0f, 0.0f, -1.0f);
	//static const Vec3<float> Backward(0.0f, 0.0f, 1.0f);
	//static const Vec3<float> Right(1.0f, 0.0f, 0.0f);
	//static const Vec3<float> Left(-1.0f, 0.0f, 0.0f);
	//static const Vec3<float> Up(0.0f, 1.0f, 0.0f);
	//static const Vec3<float> Down(0.0f, -1.0f, 0.0f);

	Vec3() {}
	Vec3(T xVal, T yVal, T zVal) : x(xVal), y(yVal), z(zVal) {}
	// Copy Ctor
	Vec3(const Vec3& vec) : x(vec.x), y(vec.y), z(vec.z) {}

	void ZeroVector()
	{
		// Setting to float by default 
		// Might need to cast to double if 
		// user intents to use doubles
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	Vec3& operator= (const T& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}
	bool operator== (const Vec3& rhs) const
	{
		x == rhs.x;
		y == rhs.y;
		z == rhs.z;
		return *this;
	}
	bool operator!= (const Vec3& rhs) const
	{
		return x != rhs.x || y != rhs.y || z != rhs.z;
	}
	Vec3& operator+= (const Vec3& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}
	Vec3& operator+ (const Vec3& rhs) const
	{
		return Vec3(x + rhs.x, y + rhs.y, z + rhs.y);
	}
	Vec3& operator-= (const Vec3& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}
	Vec3& operator- () const
	{
		return Vec3(-x, -y, -z);
	}
	// Essential for Cross-Product
	Vec3& operator* (const T& rhs) const
	{
		return Vec3(x * rhs, y * rhs, z * rhs);
	}
	Vec3& operator*= (const Vec3& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}
	Vec3& operator/ (const T& rhs) const
	{
		return Vec3(x / rhs.x, y / rhs.y, z / rhs.z);
	}
	Vec3& operator/= (const Vec3& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return *this;
	}

	T Distance(const Vec3& a, const Vec3& b)
	{
		Vec3 result = a - b;

		return sqrt((result.x * result.x) +
			(result.y * result.y) +
			(result.z * result.z));
	}

	Vec3& Normalize(const Vec3& vector)
	{
		T length = sqrt(((vector.x * vector.x) +
			(vector.y * vector.y) +
			(vector.z * vector.z)));

		Vec3 product(vector.x / length, vector.y / length,
			vector.z / length);

		return product;
	}

	T DegreeToRadian(T degree)
	{
		T result = (degree / 180.0) * PI;

		return result;
	}
	T RadianToDegree(T radian)
	{
		T result = (radian / PI) * 180.0;

		return result;
	}

	Vec3& Lerp(const Vec3& start, const Vec3& end, float delta)
	{
		if (Distance(start, end) < 0.02)
		{
			break;
		}

		Vec3 result = (((1 - delta) * start) +
			(end * delta));

		return result;
	}

	T DotProduct(const Vec3& vec1, const Vec3& vec2)
	{
		T result = ((vec1.x * vec2.x) +
			(vec1.y * vec2.y) +
			(vec1.z * vec2.z));

		return result;
	}

};





#endif