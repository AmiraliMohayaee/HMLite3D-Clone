#include "Moon.h"
#include "Utility.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>


Moon::Moon(float x, float y, float z)
{
	m_transform.SetPosition(x, y, z);

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

	GameObject::SetMatrix(m_transform.GetMatrix());

	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();

	GameObject::SetMatrix(m_transform.GetMatrix());

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
