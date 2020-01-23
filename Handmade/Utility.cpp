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

	double DegToRad(double degree)
	{
		double result = (degree / 180.0) * PI;

		return result;
	}

	double RadToDeg(double radian)
	{
		double result = (radian / PI) * 180.0;

		return result;
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

		return sqrt((result.x * result.x) +
			(result.y * result.y) +
			(result.z * result.z));
	}

	glm::vec3 Normalize(const glm::vec3& vector)
	{
		float length = sqrt((vector.x * vector.x) +
			(vector.y * vector.y) +
			(vector.z * vector.z));

		glm::vec3 product(vector.x / length, vector.y / length,
			vector.z / length);

		return product;
	}
}