#include "Enemy.h"
#include <math.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Utility.h"


Enemy::Enemy()
{
	m_pos = Vec3<float>(0.0f, 0.0f, 0.0f);
}

Enemy::Enemy(float x, float y, float z)
{
	m_pos = Vec3<float>(x, y, z);
	m_posGLM = glm::vec3(x, y, z);

	m_model.LoadModel("Assets/Models/EnemyShip.obj", "ENEMY");
	m_model.LoadTexture("Assets/Textures/Enemy_Diffuse.png", "ENEMY");


	m_collider.SetPos(m_posGLM);
	m_collider.SetDimension(1.0f, 1.0f, 1.0f);

	m_sphereCollider.SetRadius(1.0f);
	m_sphereCollider.SetScale(0.5f);
}

bool Enemy::Create()
{
	return false;
}

void Enemy::Update()
{
	//m_xRot = sin(m_xRot) + 0.01f;
	m_collider.SetPos(m_posGLM);
	m_collider.Update();

	m_sphereCollider.SetPos(m_posGLM);
	m_sphereCollider.Update();
}

void Enemy::Draw()
{
	GameObject::SetIdentity();
	//GameObject::Translate(m_xRot * (3.0f + m_pos.x), 1.0f + m_pos.y, 
	//	0.0f + m_pos.z);
	GameObject::Translate(m_pos.x, m_pos.y, m_pos.z);
	//GameObject::Rotate(m_XAngle, 1, 0, 0);

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

void Enemy::Destroy()
{

}

const AABB& Enemy::GetCollider() const
{
	return m_collider;
}

const SphereCollider& Enemy::GetSphereCollider() const
{
	return m_sphereCollider;
}
