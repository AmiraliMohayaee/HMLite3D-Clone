#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <glm.hpp>


namespace Utility
{
	const double PI = 3.14159265359;

	void Log(const std::string& msg);
	void Log(float value, const std::string& label = "");
	void Log(float x, float y, float z = 0.0f, const std::string& label = "");

	double DegToRad(double degree);
	double RadToDeg(double radian);

	float LineDistance(float a, float b, float a2, float b2);
	float LineDistance(const glm::vec3& vec1, const glm::vec3& vec2);

	glm::vec3 Normalize(const glm::vec3& vector);
}


#endif