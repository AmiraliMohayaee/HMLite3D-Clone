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

	float Clamp(float val, float min, float max);
	const glm::vec3& Clamp(glm::vec3& vec, glm::vec3& min, glm::vec3& max);
	const Vec3<float> Clamp(Vec3<float>& vec, Vec3<float>& min, Vec3<float>& max);
	float LineDistance(float a, float b, float a2, float b2);
	float LineDistance(const glm::vec3& start, const glm::vec3& dest);
	float LineDistance(const Vec3<float>& vec1, const Vec3<float> vec2);

	const Vec3<float>& CrossProduct(const Vec3<float>& vec1, const Vec3<float>& vec2);

}


#endif