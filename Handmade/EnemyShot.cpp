#include "EnemyShot.h"
#include "Utility.h"


EnemyShot::EnemyShot(float x, float y, float z)
{
	m_pos = Vec3<float>(x, y, z);
	m_posGLM = glm::vec3(x, y, z);

	m_vel = 0.1f;


	m_model.LoadModel("Assets/Models/Laser_Enemy.obj", "LASER");
	m_model.LoadTexture("Assets/Textures/Laser_Enemy_Diffuse.png", "LASER");

	m_collider.SetPos(m_posGLM);
	m_collider.SetDimension(2.0f, 2.0f, 2.0f);
}

bool EnemyShot::Create()
{
	return false;
}

void EnemyShot::Update()
{

}

void EnemyShot::Draw()
{

}

void EnemyShot::Destroy()
{

}

void EnemyShot::OnCollision(GameObject* go)
{

}

const AABB& EnemyShot::GetCollider() const
{
	return m_collider;
}

const SphereCollider& EnemyShot::GetSphereCollider() const
{
	return m_sphereCollider;
}
