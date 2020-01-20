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
}