#include "RigidBody.h"
#include "Game.h"

RigidBody::RigidBody()
{
	m_vel = Vec3f(0.0f, 0.0f, 0.0f);
	m_acc = Vec3f(0.0f, 0.0f, 0.0f);
	m_pos = Vec3f(0.0f, 0.0f, 0.0f);
	m_force = Vec3f(0.0f, 0.0f, 0.0f);

	m_velGLM = glm::vec3(0.0f);
	m_posGLM = glm::vec3(0.0f);
	m_accGLM = glm::vec3(0.0f);
	m_forceGLM = glm::vec3(0.0f);

	m_mass = 0.0f;
}

void RigidBody::Update()
{
	// Setting up Euler integration
	
	// Temp variable for storing velocity and  
	// pos variable to find the new pos of  
	// the object after integration
	glm::vec3 oldPos = m_posGLM;
	glm::vec3 oldVel = m_velGLM;

	if (m_mass > 0)
	{
		m_accGLM = m_forceGLM / m_mass;
	}

	float deltaTime = TheGame::Instance()->GetElapsedTime() / 1000.0f;

	// Setting up 
	m_velGLM += m_accGLM * deltaTime;
	m_posGLM += ((oldVel + m_velGLM) * 0.5f) * deltaTime;
}

void RigidBody::SetVel(glm::vec3& vel)
{
	m_velGLM = vel;
}

void RigidBody::VecUpdate()
{
	// Setting up Euler integration for the custom Vec3s

	// Temp variable for storing velocity and  
	// pos variable to find the new pos of  
	// the object after integration
	Vec3f oldPos = m_pos;
	Vec3f oldVel = m_vel;

	//if (m_mass > 0)
	//{
	//	m_acc = m_force / m_mass;
	//}

	
	float deltaTime = TheGame::Instance()->GetElapsedTime() / 1000.0f;

	// Setting up 
	m_vel += m_acc * deltaTime;
	// **********************************
	// TO-DO LATER
	// **********************************
	//m_pos += ((oldVel + m_vel) * 0.5f) * deltaTime;
}

void RigidBody::SetVel(Vec3f& vel)
{
	m_vel = vel;
}

void RigidBody::SetVel(float x, float y, float z)
{
	m_vel.x = x;
	m_vel.y = y;
	m_vel.z = z;

	m_velGLM.x = x;
	m_velGLM.y = y;
	m_velGLM.z = z;
}

void RigidBody::SetPos(Vec3f& pos)
{
	m_pos = pos;
}

void RigidBody::SetPos(glm::vec3& pos)
{
	m_posGLM = pos;
}

void RigidBody::SetPos(float x, float y, float z)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.z = z;

	m_posGLM.x = x;
	m_posGLM.y = y;
	m_posGLM.z = z;
}

void RigidBody::SetAcc(Vec3f& acc)
{
	m_acc = acc;
}

void RigidBody::SetForce(Vec3f& force)
{
	m_force = force;
}

void RigidBody::AddForce(Vec3f& addForce)
{
	m_force += addForce;
}

void RigidBody::SetAcc(glm::vec3& acc)
{
	m_accGLM = acc;
}

void RigidBody::SetAcc(float x, float y, float z)
{
	m_acc.x = x;
	m_acc.y = y;
	m_acc.z = z;

	m_accGLM.x = x;
	m_accGLM.y = y;
	m_accGLM.z = z;
}

void RigidBody::SetForce(glm::vec3& force)
{
	m_forceGLM = force;
}

void RigidBody::SetForce(float x, float y, float z)
{
	m_forceGLM.x = x;
	m_forceGLM.y = y;
	m_forceGLM.z = z;
}

void RigidBody::SetMass(float mass)
{
	m_mass = mass;
}

void RigidBody::AddForce(glm::vec3& addForce)
{
	m_forceGLM += addForce;
}

void RigidBody::AddForce(float x, float y, float z)
{
	m_forceGLM.x = x;
	m_forceGLM.y = y;
	m_forceGLM.z = z;
}

const Vec3f& RigidBody::GetVec3Vel()
{
	return m_vel;
}

const Vec3f& RigidBody::GetVec3Pos()
{
	return m_pos;
}

const Vec3f& RigidBody::GetVec3Acc()
{
	return m_acc;
}

const Vec3f& RigidBody::GetVec3Force()
{
	return m_force;
}

const glm::vec3& RigidBody::GetVel()
{
	return m_velGLM;
}

const glm::vec3& RigidBody::GetPos()
{
	return m_posGLM;
}

const glm::vec3& RigidBody::GetAcc()
{
	return m_accGLM;
}

const glm::vec3& RigidBody::GetForce()
{
	return m_forceGLM;
}
