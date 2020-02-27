#ifndef SPHERE_COLLIDER_H
#define SPHERE_COLLIDER_H

#include "Vec3.h"
#include <glm.hpp>


class SphereCollider
{
public:
	SphereCollider();
	~SphereCollider();

	void DebugDraw();
	void Update();

	void SetRadius(float radius);
	void SetPos(float x, float y, float z);
	void SetPos(const glm::vec3& pos);
	void SetScale(float radius);

	bool IsSphereColliding(const SphereCollider& secondSphere) const;

private:
	float m_radius;
	glm::vec3 m_pos;
	float m_radiusScaled;

};

#endif