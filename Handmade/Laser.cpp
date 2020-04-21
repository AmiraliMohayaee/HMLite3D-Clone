#include "Laser.h"
#include "Utility.h"


Laser::Laser()
{

}

Laser::~Laser()
{

}

Laser::Laser(float x, float y, float z)
{
	m_posGLM = glm::vec3(x, y, z);

	m_vel = 0.1f;

	m_playerLaser.LoadModel("Assets/Models/Laser_Player.obj", "PLAYERLASER");
	m_playerLaser.LoadTexture("Assets/Textures/Laser_Player_Diffuse.png", "PLAYERLASER");

	m_enemyLaser.LoadModel("Assets/Models/Laser_Enemy.obj", "ENEMYLASER");
	m_enemyLaser.LoadTexture("Assets/Textures/Laser_Enemy_Diffuse.png", "ENEMYLASER");


	m_collider.SetPos(m_posGLM);
	m_collider.SetDimension(2.0f, 2.0f, 2.0f);
}

bool Laser::Create()
{
	return false;
}

void Laser::Update()
{
	m_rb.AddForce(0.0f, 0.0f, -1.0f);

	//if (m_rb.GetPos())
	//{

	//}

	m_rb.Update();
}

void Laser::Draw()
{

}

void Laser::Destroy()
{

}

void Laser::OnCollision(GameObject* go)
{
	Utility::Log("Colliding with " + go->GetTag());
}

void Laser::PlayerShotDraw()
{

	glm::mat4 result;
	glm::mat4 trans = glm::translate(glm::mat4(), glm::vec3(0.5f + m_pos.x, 0.0f + m_pos.y, 0.0f + m_pos.z));
	glm::mat4 rot = glm::rotate(glm::mat4(), Utility::DegToRad(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(0.1, 0.1, 0.1));
	result = trans * rot * scale;
	GameObject::SetMatrix(result);
	// Required when loading costum objs
	GameObject::SendToShader(false, true);
	m_playerLaser.SetColor(1, 1, 1, 1);
	m_playerLaser.Draw();

	result = trans * rot;
	GameObject::SetMatrix(result);

	m_collider.DebugDraw();
}

void Laser::EnemyShotDraw()
{

	glm::mat4 result;
	glm::mat4 trans = glm::translate(glm::mat4(), glm::vec3(0.5f + m_pos.x, 0.0f + m_pos.y, 0.0f + m_pos.z));
	glm::mat4 rot = glm::rotate(glm::mat4(), Utility::DegToRad(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(0.1, 0.1, 0.1));
	result = trans * rot * scale;
	GameObject::SetMatrix(result);
	// Required when loading costum objs
	GameObject::SendToShader(false, true);
	m_enemyLaser.SetColor(1, 1, 1, 1);
	m_enemyLaser.Draw();

	result = trans * rot;
	GameObject::SetMatrix(result);

	m_collider.DebugDraw();
}

void Laser::PlayerUpdate()
{

}

void Laser::EnemyUpdate()
{

}

const AABB& Laser::GetCollider() const
{
	return m_collider;
}

const SphereCollider& Laser::GetSphereCollider() const
{
	return m_sphereCollider;
}
