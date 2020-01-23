#include "Planet.h"

Planet::Planet()
{

}

Planet::Planet(float x, float y, float z)
{
	m_angle = 0.0f;
	m_pos = (glm::vec3(x, y, z));
}

bool Planet::Create()
{
	return false;
}

void Planet::Update()
{
	m_angle += 0.01f;
	m_orbitalPos.x = cos(m_angle) * sin(m_angle) * 2.0f;
	m_orbitalPos.z = sin(m_angle);
}

void Planet::Draw()
{
	GameObject::SetIdentity();

	glm::vec3 finalPos = m_pos + m_orbitalPos;
	GameObject::Translate(finalPos.x, finalPos.y, finalPos.z);

	TheDebug::Instance()->DrawSphere3D(1.0f, 200.0f, 300.0f, 100.0f, 1.0f);
}


void Planet::Destroy()
{

}
