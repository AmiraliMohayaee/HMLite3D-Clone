#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Vec3.h"

class RigidBody
{
public:
	RigidBody();

	void Update();
	void SetVel(const glm::vec3& vel);
	void SetVel(float x, float y, float z);
	void SetPos(const glm::vec3& pos);
	void SetPos(float x, float y, float z);
	void SetAcc(const glm::vec3& acc);
	void SetAcc(float x, float y, float z);
	void SetForce(const glm::vec3& force);
	void SetForce(float x, float y, float z);
	void SetMass(float mass);
	void AddForce(const glm::vec3& addForce);
	void AddForce(float x, float y, float z);
	const glm::vec3& GetVel();
	const glm::vec3& GetPos();
	const glm::vec3& GetAcc();
	const glm::vec3& GetForce();


public:
	//void VecUpdate();
	//void SetVel(Vec3f& vel);
	//void SetPos(Vec3f& pos);
	//void SetAcc(Vec3f& acc);
	//void SetForce(Vec3f& force);
	//void AddForce(Vec3f& addForce);
	//const Vec3f& GetVec3Vel();
	//const Vec3f& GetVec3Pos();
	//const Vec3f& GetVec3Acc();
	//const Vec3f& GetVec3Force();


private:
	float m_mass;

	glm::vec3 m_velGLM;
	glm::vec3 m_posGLM;
	glm::vec3 m_accGLM;
	glm::vec3 m_forceGLM;

	Vec3f m_vel;
	Vec3f m_pos;
	Vec3f m_acc;
	Vec3f m_force;

};

#endif