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
	void SetVel(glm::vec3& vel);
	void SetVel(float x, float y, float z);
	void SetPos(glm::vec3& pos);
	void SetPos(float x, float y, float z);
	void SetAcc(glm::vec3& acc);
	void SetAcc(float x, float y, float z);
	const glm::vec3& GetVel();
	const glm::vec3& GetPos();
	const glm::vec3& GetAcc();


public:
	void VecUpdate();
	void SetVel(Vec3f& vel);
	void SetPos(Vec3f& pos);
	void SetAcc(Vec3f& acc);
	const Vec3f& GetVec3Vel();
	const Vec3f& GetVec3Pos();
	const Vec3f& GetVec3Acc();


private:
	glm::vec3 m_velGLM;
	glm::vec3 m_posGLM;
	glm::vec3 m_accGLM;


	Vec3f m_vel;
	Vec3f m_pos;
	Vec3f m_acc;

};

#endif