#ifndef UTILITY_H
#define UTILITY_H

#include <string>



namespace Utility
{
	const double PI = 3.14159265359;

	void Log(const std::string& msg);
	void Log(float value, const std::string& label = "");
	void Log(float x, float y, float z = 0.0f, const std::string& label = "");

	double DegToRad(double degree);
	double RadToDeg(double radian);

	float LineDistance(float a, float b, float a2, float b2);
}


#endif