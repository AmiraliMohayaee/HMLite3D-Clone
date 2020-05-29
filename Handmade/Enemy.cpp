#include "Enemy.h"
#include <math.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Utility.h"


Enemy::Enemy()
{

}

Enemy::Enemy(float x, float y, float z)
{
 	m_rb.SetPos(x, y, z);
	m_rb.SetMass(3.0f);
	m_transform.SetPosition(m_rb.GetPos());

	m_startPos = m_rb.GetPos();

	static bool isEnemyLoaded = false;

	if (!isEnemyLoaded)
	{
		m_model.LoadModel("Assets/Models/EnemyShip.obj", "ENEMY");
		m_model.LoadTexture("Assets/Textures/Enemy_Diffuse.png", "ENEMY");
		isEnemyLoaded = true;
	}
	else
	{
		m_model.SetBuffer("ENEMY");
		m_model.SetTexture("ENEMY");
	}

	//m_collider.SetPos(m_rb.GetPos());
	//m_collider.SetDimension(1.5f, 1.5f, 1.5f);
	//m_collider.SetScale(1.5f, 1.5f, 1.5f);

	m_sphereCollider.SetPos(m_rb.GetPos());
	m_sphereCollider.SetRadius(1.0f);
	m_sphereCollider.SetScale(1.0f);
}

void Enemy::Update()
{
	//m_xRot = sin(m_xRot) + 0.01f;
	m_rb.AddForce(+0.1f, 0.0f, +1.0f);

	m_rb.Update();
	m_transform.SetPosition(m_rb.GetPos());

	//m_rb.SetPos(m_player->GetPosition());

	if (m_rb.GetPos().z >= 3)
	{
		m_rb.SetPos(m_startPos);
	}

	m_sphereCollider.SetPos(m_rb.GetPos());
	m_sphereCollider.Update();
}

void Enemy::Draw()
{
	m_transform.SetScale(0.1f, 0.1f, 0.1f);
	GameObject::SetMatrix(m_transform.GetMatrix());

	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();

	m_transform.SetScale(1, 1, 1);
	GameObject::SetMatrix(m_transform.GetMatrix());
	GameObject::SendToShader(false, true);

#ifdef DEBUG
	//m_collider.DebugDraw();
	m_sphereCollider.DebugDraw();
#endif
}

void Enemy::Destroy()
{
	m_model.UnloadModel("ENEMY");
	m_model.UnloadTexture("ENEMY");
}

const SphereCollider& Enemy::GetSphereCollider() const
{
	return m_sphereCollider;
}