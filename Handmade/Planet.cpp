#include "Planet.h"
#include <gtc/matrix_transform.hpp>
#include "Utility.h"


Planet::Planet()
{

}

Planet::Planet(float x, float y, float z)
{
	m_angle = 0.0f;
	m_pos = Vec3<float>(x, y, z);

	m_posGLM = glm::vec3(x, y, z);

	m_model.LoadModel("Assets/Models/Planet.obj", "PLANET");
	m_model.LoadTexture("Assets/Textures/Planet_Diffuse.png", "PLANET");
}

bool Planet::Create()
{
	return false;
}

void Planet::Update()
{
	// The Planet does not have any collision properties

	m_angle += 0.01f;
	m_orbitalPos.x = cos(m_angle) * sin(m_angle) * 2.0f;
	m_orbitalPos.z = sin(m_angle);
}

void Planet::Draw()
{
	GameObject::SetIdentity();

	glm::mat4 result;
	glm::mat4 trans = glm::translate(glm::mat4(), glm::vec3(0.5f + m_pos.x, 0.0f + m_pos.y, 0.0f + m_pos.z));
	glm::mat4 rot = glm::rotate(glm::mat4(), Utility::DegToRad(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(0.1, 0.1, 0.1));
	result = trans * rot * scale;
	GameObject::SetMatrix(result);

	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();

	result = trans;
	GameObject::SetMatrix(result);
}


void Planet::Destroy()
{
	delete m_moon;
}
