#ifndef VEC4_H
#define VEC4_H


template <class T>


class Vec4
{
	T x, y, z, w;

	//Vec4::Forward = Vec3(0.0f, 0, 0f, -1.0f, 0.0f);
	//Vec4::Backward = Vec3(0.0f, 0.0f, 1.0f, 0.0f);
	//Vec4::Right = Vec3(1.0f, 0.0f, 0.0f, 0.0f);
	//Vec4::Left = Vec3(-1.0f, 0.0f, 0.0f, 0.0f);
	//Vec4::Up = Vec3(0.0f, 1.0f, 0.0f, 0.0f);
	//Vec4::Down = Vec3(0.0f, -1.0f, 0.0f, 0.0f);

	//static Vec4<T> Forward;
	//static Vec4<T> Backward;
	//static Vec4<T> Right;
	//static Vec4<T> Left;
	//static Vec4<T> Up;
	//static Vec4<T> Down;

	Vec4() {}
	Vec4(T xVal, T yVal, T zVal, T wVal) : x(xVal), y(yVal), z(zVal), w(wVal) {}
	// Copy Ctor
	Vec4(const Vec4& vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w) {}

	void ZeroVector()
	{
		// Setting to float by default 
		// Might need to cast to double if 
		// user intents to use doubles
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}
	Vec4& operator= (const T& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = rhs.w;
		return *this;
	}
	bool operator== (const Vec4& rhs) const
	{
		x == rhs.x;
		y == rhs.y;
		z == rhs.z;
		w == rhs.w;
		return *this;
	}
	bool operator!= (const Vec3& rhs) const
	{
		return x != rhs.x || y != rhs.y || z != rhs.z || w != rhs.w;
	}
	Vec4& operator+= (const Vec4& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	}
	Vec4& operator+ (const Vec4& rhs) const
	{
		return Vec4(x + rhs.x, y + rhs.y, z + rhs.y, w + rhs.w);
	}
	Vec4& operator-= (const Vec4& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return *this;
	}
	Vec4& operator- () const
	{
		return Vec4(-x, -y, -z, -w);
	}
	// Essential for Cross-Product
	Vec4& operator* (const T& rhs) const
	{
		return Vec4(x * rhs, y * rhs, z * rhs, w * rhs.w);
	}
	Vec4& operator*= (const Vec4& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		w *= rhs.w;
		return *this;
	}
	Vec4& operator/ (const T& rhs) const
	{
		return Vec3(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
	}
	Vec4& operator/= (const Vec4& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		w /= rhs.w;
		return *this;
	}

	T Distance(const Vec4& a, const Vec4& b)
	{
		Vec4 result = a - b;

		return sqrt((result.x * result.x) +
			(result.y * result.y) +
			(result.z * result.z));
	}

	Vec3& Normalize(const Vec4& vector)
	{
		T length = sqrt(((vector.x * vector.x) +
			(vector.y * vector.y) +
			(vector.z * vector.z)));

		Vec4 product(vector.x / length, vector.y / length,
			vector.z / length);

		return product;
	}

	Vec4& Lerp(const Vec4& start, const Vec4& end, float delta)
	{
		if (Distance(start, end) < 0.02)
		{
			break;
		}

		Vec3 result = (((1 - delta) * start) +
			(end * delta));

		return result;
	}

	T DotProduct(const Vec4& vec1, const Vec4& vec2)
	{
		T result = ((vec1.x * vec2.x) +
			(vec1.y * vec2.y) +
			(vec1.z * vec2.z));

		return result;
	}

};

#endif