#include "RigidBody.h"
#include "Game.h"

RigidBody::RigidBody()
{
	m_vel = Vec3f(0.0f, 0.0f, 0.0f);
	m_acc = Vec3f(0.0f, 0.0f, 0.0f);
	m_pos = Vec3f(0.0f, 0.0f, 0.0f);

	m_velGLM = glm::vec3(0.0f);
	m_posGLM = glm::vec3(0.0f);
	m_accGLM = glm::vec3(0.0f);
}

void RigidBody::Update()
{
	// Setting up Euler integration
	
	// Temp variable for storing velocity and  
	// pos variable to find the new pos of  
	// the object after integration
	glm::vec3 oldPos = m_posGLM;
	glm::vec3 oldVel = m_velGLM;

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
