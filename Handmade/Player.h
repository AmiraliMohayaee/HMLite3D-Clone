#ifndef PLAYER_H
#define PLAYER_H

#include "DebugManager.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Matrix4x4.h"
#include <glm.hpp>
#include "Vec3.h"
#include "Model.h"
#include "Transform.h"
#include "SphereCollider.h"
#include "Laser.h"
#include "Enemy.h"


class Player : public GameObject
{
public:
	Player();
	Player(float x, float y, float z);

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void OnCollision(GameObject* go);

	const SphereCollider& GetSphereCollider() const;


private:
	Laser* m_bullet;

	float m_vel;
	float m_velCap;
	float m_angle;

	glm::vec3 m_velGLM;
	glm::vec3 m_accGLM;
	glm::vec3 m_forceGLM;

	glm::vec3 m_dirGLM;
	glm::vec3 m_upGLM;
	glm::vec3 m_forwardGLM;
	glm::vec3 m_rightGLM;
	glm::vec3 m_rotVecGLM;


	Model m_model;

	SphereCollider m_sphereCollider;
};


#endif