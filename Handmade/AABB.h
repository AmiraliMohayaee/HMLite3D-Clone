#ifndef AABB_H
#define AABB_H

#include "Vec3.h"
#include "SphereCollider.h"
#include <glm.hpp>

class AABB
{
public:
	AABB();
	~AABB();

public:
	void DebugDraw();
	void Update();

	void SetPos(float x, float y, float z);
	void SetPos(const glm::vec3& pos);
	void SetScale(float x, float y, float z);

	void SetDimension(float width, float height, float depth);

	bool IsColliding(const AABB& secondBox) const;
	bool IsColliding(const SphereCollider& sphere);


private:
	glm::vec3 m_pos;
	glm::vec3 m_dimention;
	glm::vec3 m_scale;
	glm::vec3 m_min;
	glm::vec3 m_max;
};


#endif