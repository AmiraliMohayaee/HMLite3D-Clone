#include "Moon.h"
#include "Utility.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>


Moon::Moon(float x, float y, float z)
{
	m_pos = Vec3<float>(0.0f, 0.0f, 0.0f);
	m_posGLM = glm::vec3(0.0f);

	m_objMat = glm::mat4(1.0f);

	m_model.LoadModel("Assets/Models/Planet.obj", "MOON");
	m_model.LoadTexture("Assets/Textures/Planet_Diffuse.png", "MOON");
}

bool Moon::Create()
{
	return false;
}

void Moon::Update()
{
	GameObject::SetIdentity();

	GameObject::Translate(m_pos.x, m_pos.y, m_pos.z);


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

	m_collider.DebugDraw();
	//m_sphereCollider.DebugDraw();
}

void Moon::Draw()
{

}

void Moon::Destroy()
{
}

void Moon::OnCollision(GameObject* go)
{
}

const AABB& Moon::GetCollider() const
{
	return m_collider;
}

const SphereCollider& Moon::GetSphereCollider() const
{
	return m_sphereCollider;
}
