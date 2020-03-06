#include "PlayerShot.h"
#include "Utility.h"


PlayerShot::PlayerShot()
{

}

PlayerShot::~PlayerShot()
{

}

PlayerShot::PlayerShot(float x, float y, float z)
{
	m_posGLM = glm::vec3(x, y, z);

	m_vel = 0.1f;

	m_model.LoadModel("Assets/Models/Laser_Player.obj", "PLAYERLASER");
	m_model.LoadTexture("Assets/Textures/Laser_Player_Diffuse.png", "PLAYERLASER");

	m_collider.SetPos(m_posGLM);
	m_collider.SetDimension(2.0f, 2.0f, 2.0f);
}

bool PlayerShot::Create()
{
	return false;
}

void PlayerShot::Update()
{

}

void PlayerShot::Draw()
{

	glm::mat4 result;
	glm::mat4 trans = glm::translate(glm::mat4(), glm::vec3(0.5f + m_pos.x, 0.0f + m_pos.y, 0.0f + m_pos.z));
	glm::mat4 rot = glm::rotate(glm::mat4(), Utility::DegToRad(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(0.1, 0.1, 0.1));
	result = trans * rot * scale;
	GameObject::SetMatrix(result);
	// Required when loading costum objs
	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();

	result = trans * rot;
	GameObject::SetMatrix(result);
}

void PlayerShot::Destroy()
{

}

void PlayerShot::OnCollision(GameObject* go)
{
	Utility::Log("Colliding with " + go->GetTag());
}

const AABB& PlayerShot::GetCollider() const
{
	return m_collider;
}

const SphereCollider& PlayerShot::GetSphereCollider() const
{
	return m_sphereCollider;
}
