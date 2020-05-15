#include "Asteroid.h"
#include "Utility.h"
#include "Game.h"


Asteroid::Asteroid(float x, float y, float z)
{
	m_rb.SetPos(x, y, z);
	m_transform.SetPosition(m_rb.GetPos());
	m_rb.SetMass(3.0f);

	m_rotAngle = 0.0f;

	m_vel = 0.1f;

	static bool isAsteroidLoaded = false;

	if (!isAsteroidLoaded)
	{
		m_model.LoadModel("Assets/Models/Asteroid_1.obj", "ASTEROID");
		m_model.LoadTexture("Assets/Textures/Asteroid_1_Diffuse.png", "ASTEROID");
		isAsteroidLoaded = true;
	}
	else
	{
		m_model.SetBuffer("ASTEROID");
		m_model.SetTexture("ASTEROID");
	}

	m_sphereCollider.SetPos(m_rb.GetPos());
	m_sphereCollider.SetRadius(1.0f);
	m_sphereCollider.SetScale(1.0f);
}

bool Asteroid::Create()
{
	return false;
}

void Asteroid::Update()
{
	m_rotAngle += 
		(TheGame::Instance()->GetElapsedTime() / 1000.0f) * 20.0f;

	m_transform.SetRotation(0.0f, m_rotAngle, 0.0f);

	

	m_rb.AddForce(0.0f, 0.0f, +0.5f);

	//forceAdd++;

	m_rb.Update();
	m_transform.SetPosition(m_rb.GetPos());

	m_sphereCollider.SetPos(m_rb.GetPos());
	m_sphereCollider.Update();
}

void Asteroid::Draw()
{
	m_transform.SetScale(0.1f, 0.1f, 0.1f);
	GameObject::SetMatrix(m_transform.GetMatrix());

	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();

	m_transform.SetScale(1, 1, 1);
	GameObject::SetMatrix(m_transform.GetMatrix());
	GameObject::SendToShader(false, true);

	m_sphereCollider.DebugDraw();
}

void Asteroid::Destroy()
{

}

void Asteroid::OnCollision(GameObject* go)
{
	Utility::Log("Colliding with " + go->GetTag());
}

const SphereCollider& Asteroid::GetSphereCollider() const
{
	return m_sphereCollider;
}