#include "Asteroid.h"
#include "Utility.h"


Asteroid::Asteroid(float x, float y, float z)
{
	m_pos = Vec3<float>(0.0f, 0.0f, 0.0f);
	m_vel = 0.1f;


	m_model.LoadModel("Assets/Models/Asteroid.obj", "SPACESHIP");
	m_model.LoadTexture("Assets/Textures/Asteroid_Diffuse.png", "SPACESHIP");
}

bool Asteroid::Create()
{
	return false;
}

void Asteroid::Update()
{

}

void Asteroid::Draw()
{

}

void Asteroid::Destroy()
{

}

void Asteroid::OnCollision(GameObject* go)
{
	Utility::Log("Colliding with " + go->GetTag());
}

const AABB& Asteroid::GetCollider() const
{
	return m_collider;
}

const SphereCollider& Asteroid::GetSphereCollider() const
{
	return m_sphereCollider;
}
