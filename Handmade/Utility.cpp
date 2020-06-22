#include "Utility.h"
#include <iostream>
#include <math.h>


namespace Utility
{
	void Utility::Log(const std::string& msg)
	{
		std::cout << msg << std::endl;
	}

	void Utility::Log(float value, const std::string& label)
	{
		if (!label.empty())
		{
			std::cout << "[" << label << "]";
		}

		std::cout << value << std::endl;
	}

	void Utility::Log(float x, float y, float z, const std::string& label)
	{
		if (!label.empty())
		{
			std::cout << "[" << label << "]";
		}
		
		std::cout << x << ", " << y << ", " << z << std::endl;
	}

	float DegToRad(float degree)
	{
		float result = (degree / 180.0f) * PI;

		return result;
	}

	float RadToDeg(float radian)
	{
		float result = (radian / PI) * 180.0f;

		return result;
	}

	float Clamp(float val, float min, float max)
	{
		if (val > max)
		{
			val = max;
		}
		else if (val < min)
		{
			val = min;
		}
		return val;
	}

	const glm::vec3& Clamp(glm::vec3& vec, glm::vec3& min, glm::vec3& max)
	{
		if (vec.x > max.x)
		{
			vec.x = max.x;
		}
		else if (vec.y > max.y)
		{
			vec.y = max.y;
		}
		else if(vec.z > max.z)
		{
			vec.z = max.z;
		}

		if (vec.x < min.x)
		{
			vec.x = min.x;
		}
		else if (vec.y < min.y)
		{
			vec.y = min.y;
		}
		else if (vec.z < min.z)
		{
			vec.z = min.z;
		}

		return vec;
	}

	const Vec3<float> Clamp(Vec3<float>& vec, Vec3<float>& min, Vec3<float>& max)
	{
		if (vec.x > max.x)
		{
			vec.x = max.x;
		}
		else if (vec.y > max.y)
		{
			vec.y = max.y;
		}
		else if (vec.z > max.z)
		{
			vec.z = max.z;
		}

		if (vec.x < min.x)
		{
			vec.x = min.x;
		}
		else if (vec.y < min.y)
		{
			vec.y = min.y;
		}
		else if (vec.z < min.z)
		{
			vec.z = min.z;
		}

		return vec;
	}



	// Get the distance between two points by performing
	// a pythagorem equation
	float LineDistance(float a1, float b1, float a2, float b2)
	{
		return sqrt(((a2 * a2) + (b2 * b2)) - ((a1 * a1) + (b1 * b1)));
	}

	float LineDistance(const glm::vec3& start, const glm::vec3& dest)
	{
		glm::vec3 result = start - dest;

		float sqrtResult = sqrt((result.x * result.x) +
			(result.y * result.y) +
			(result.z * result.z));

		return sqrtResult;
	}

	float LineDistance(const Vec3<float>& start, const Vec3<float> dest)
	{
		Vec3<float> result = start - dest;

		float sqrtResult = sqrt((result.x * result.x) +
			(result.y * result.y) +
			(result.z * result.z));

		return sqrtResult;
	}

	const Vec3<float>& Utility::CrossProduct(const Vec3<float>& vec1, const Vec3<float>& vec2)
	{
		{
			Vec3<float> result(((vec1.y * vec2.z) - (vec1.z * vec2.y)),
				((vec1.z * vec2.x) - (vec1.x * vec2.z)),
				((vec1.x * vec2.y) - (vec1.y * vec2.x)));

			return result;
		}
	}
}