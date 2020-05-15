#include "AABB.h"
#include "Utility.h"
#include "DebugManager.h"


AABB::AABB()
{
	m_pos = glm::vec3(0.0f);
	m_dimention = glm::vec3(1.0f);
	m_scale = glm::vec3(1.0f);
	m_min = glm::vec3();
	m_max = glm::vec3();
}

AABB::~AABB()
{

}

void AABB::DebugDraw()
{
	TheDebug::Instance()->DrawCube3D(m_dimention.x, m_dimention.y, m_dimention.z, 0.0f, 1.0f, 0.0f, 0.4f);
}

void AABB::Update()
{
	glm::vec3 halfDim = (m_dimention * m_scale) * 0.5f;

	m_min.x = (m_pos.x - halfDim.x);
	m_min.y = (m_pos.y - halfDim.y);
	m_min.z = (m_pos.z - halfDim.z);

	m_max.x = (m_pos.x + halfDim.x);
	m_max.y = (m_pos.y + halfDim.y);
	m_max.z = (m_pos.z + halfDim.z);
}

void AABB::SetPos(float x, float y, float z)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.z = z;
}

void AABB::SetDimension(float width, float height, float depth)
{
	m_dimention.x = width;
	m_dimention.y = height;
	m_dimention.z = depth;
}

void AABB::SetPos(const glm::vec3& pos)
{
	m_pos = pos;
}

void AABB::SetScale(float x, float y, float z)
{
	m_scale.x = x;
	m_scale.y = y;
	m_scale.z = z;
}

bool AABB::IsColliding(const AABB& secondBox) const
{
	if ((m_max.x > secondBox.m_min.x && secondBox.m_max.x > m_min.x) && 
		(m_max.y > secondBox.m_min.y && secondBox.m_max.y > m_min.y) &&
		(m_max.z > secondBox.m_min.z && secondBox.m_max.z > m_min.z))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool AABB::IsColliding(const SphereCollider& sphere) const
{
	// Getting dimentions of the are for checking collision
	glm::vec3 halfDim = (m_dimention * m_scale) * 0.5f;

	// Getting the distance between sphere and box
	glm::vec3 dist = this->m_pos - sphere.GetPos();

	//Utility::LineDistance(m_min, m_max);

	// Clamping the value
	dist = Utility::Clamp(dist, -halfDim, halfDim);

	// Get the pos of the edge on the box
	glm::vec3 edge = m_pos - dist;
	float edgeDist = Utility::LineDistance(edge, sphere.GetPos());


	if (sphere.GetRadius() >= edgeDist)
	{
		return false;
	}
	else
	{
		return true;
	}
}