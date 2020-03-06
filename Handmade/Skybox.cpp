#include "Skybox.h"
#include <gtc/matrix_transform.hpp>
#include "Utility.h"


Skybox::Skybox()
{
}

Skybox::Skybox(float x, float y, float z)
{
	m_posGLM = glm::vec3(x, y, z);
	m_objMat = glm::mat4(1.0f);

	m_model.LoadModel("Assets/Models/Skybox.obj", "SKYBOX");
	m_model.LoadTexture("Assets/Textures/Skybox_Color.png", "SKYBOX");

	m_collider.SetPos(m_posGLM);
	m_collider.SetDimension(2.0f, 2.0f, 2.0f);
}

bool Skybox::Create()
{
	return false;
}

void Skybox::Update()
{

}

void Skybox::Draw()
{
	glm::mat4 m_objMat;
	glm::mat4 trans = glm::translate(glm::mat4(), glm::vec3(0.5f + m_pos.x, 0.0f + m_pos.y, 0.0f + m_pos.z));
	glm::mat4 rot = glm::rotate(glm::mat4(), Utility::DegToRad(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(1, 1, 1));
	m_objMat = trans * rot * scale;
	GameObject::SetMatrix(m_objMat);

	// Required when loading costum objs
	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();

	m_objMat = trans * rot;
	GameObject::SetMatrix(m_objMat);
}

void Skybox::Destroy()
{

}

void Skybox::OnCollision(GameObject* go)
{
}
