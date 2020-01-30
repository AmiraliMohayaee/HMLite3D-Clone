#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <glm.hpp>
#include "Vec3.h"


namespace Utility
{
	const double PI = 3.14159265359;

	void Log(const std::string& msg);
	void Log(float value, const std::string& label = "");
	void Log(float x, float y, float z = 0.0f, const std::string& label = "");

	float DegToRad(float degree);
	float RadToDeg(float radian);

	float LineDistance(float a, float b, float a2, float b2);
	float LineDistance(const glm::vec3& vec1, const glm::vec3& vec2);

	const Vec3<float>& CrossProduct(const Vec3<float>& vec1, const Vec3<float>& vec2);

}


#endif