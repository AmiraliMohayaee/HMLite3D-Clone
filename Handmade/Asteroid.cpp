#include "Asteroid.h"
#include "Utility.h"


Asteroid::Asteroid(float x, float y, float z)
{
	m_pos = Vec3<float>(x, y, z);
	m_posGLM = glm::vec3(x, y, z);

	m_vel = 0.1f;

	m_objMat = glm::mat4(1.0f);

	m_transformMat = glm::mat4(1.0f);
	m_rotMat = glm::mat4(1.0f);
	m_scaleMat = glm::mat4(1.0f);


	m_model.LoadModel("Assets/Models/Asteroid_1.obj", "ASTEROID");
	m_model.LoadTexture("Assets/Textures/Asteroid_1_Diffuse.png", "ASTEROID");
}

bool Asteroid::Create()
{
	return false;
}

void Asteroid::Update()
{
	m_rb.Update();

	m_sphereCollider.SetPos(m_posGLM);
	m_sphereCollider.Update();
}

void Asteroid::Draw()
{
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

	//m_collider.DebugDraw();
	m_sphereCollider.DebugDraw();
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
