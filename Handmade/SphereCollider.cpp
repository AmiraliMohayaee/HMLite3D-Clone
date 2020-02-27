#include "SphereCollider.h"
#include "DebugManager.h"
#include "Utility.h"


SphereCollider::SphereCollider()
{
	m_radius = 0.0f;
	m_pos = glm::vec3(0.0f);
	m_radiusScaled = 0.0f;
}

SphereCollider::~SphereCollider()
{
}

void SphereCollider::DebugDraw()
{
	TheDebug::Instance()->DrawSphere3D(m_radius, 1.0f, 0.0f, 0.0f, 0.5f);
}

void SphereCollider::Update()
{

}

void SphereCollider::SetRadius(float radius)
{
	m_radius = radius;
}

void SphereCollider::SetPos(float x, float y, float z)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.z = z;
}

void SphereCollider::SetPos(const glm::vec3& pos)
{
	m_pos = pos;
}

void SphereCollider::SetScale(float radius)
{
	m_radiusScaled = radius;
	m_radius = m_radiusScaled;
}

bool SphereCollider::IsSphereColliding(const SphereCollider& secondSphere) const
{
	float dist = Utility::LineDistance(m_pos, secondSphere.m_pos);

	return (dist <= ((m_radius * m_radiusScaled) + 
		(secondSphere.m_radius * secondSphere.m_radiusScaled)));
}
