#include "Enemy.h"
#include <math.h>

Enemy::Enemy()
{
	m_pos = glm::vec3(0.0f);

	m_xRot = 0.0f;
	m_yRot = 0.0f;
	m_zRot = 0.0f;

	m_XAngle = 0.0f;
	m_YAngle = 0.0f;
	m_ZAngle = 0.0f;
}

bool Enemy::Create()
{
	return false;
}

void Enemy::Update()
{
	m_xRot = sin(m_xRot) + 0.01f;
}

void Enemy::Draw()
{
	GameObject::SetIdentity();
	GameObject::Translate(m_xRot * (3.0f + m_pos.x), 1.0f + m_pos.y, 
		0.0f + m_pos.z);
	//GameObject::Rotate(m_XAngle, 1, 0, 0);
	TheDebug::Instance()->DrawSphere3D(1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
}

void Enemy::Destroy()
{

}
