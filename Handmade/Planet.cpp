#include "Planet.h"
#include <gtc/matrix_transform.hpp>
#include "Utility.h"


Planet::Planet()
{

}

Planet::Planet(float x, float y, float z)
{
	m_angle = 0.0f;

	m_rb.SetPos(x, y, z);

	m_transform.SetPosition(m_rb.GetPos());

	m_model.LoadModel("Assets/Models/Planet.obj", "PLANET");
	m_model.LoadTexture("Assets/Textures/Planet_Diffuse.png", "PLANET");
}

void Planet::Update()
{
	// The Planet does not have any collision properties

	m_angle += 0.01f;
	m_orbitalPos.x = cos(m_angle) * sin(m_angle) * 2.0f;
	m_orbitalPos.z = sin(m_angle);
}

void Planet::Draw()
{
	GameObject::SetIdentity();

	m_transform.SetScale(0.1f, 0.1f, 0.1f);
	GameObject::SetMatrix(m_transform.GetMatrix());

	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();

	GameObject::SetMatrix(m_transform.GetMatrix());
}

void Planet::Destroy()
{
	delete m_moon;
}
