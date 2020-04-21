#ifndef PLAYER_H
#define PLAYER_H

#include "DebugManager.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Matrix4x4.h"
#include <glm.hpp>
#include "Vec3.h"
#include "Model.h"
#include "Transformation.h"
#include "AABB.h"
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


	//void CheckCollision(const Enemy& enemy);

	const AABB& GetCollider() const;
	const SphereCollider& GetSphereCollider() const;


private:
	Laser* m_bullet[10];

	float m_vel;
	float m_velCap;
	float m_angle;


	Vec3f m_direction;
		
	Vec3f m_up;
	Vec3f m_forward;
	Vec3f m_right;
	Vec3f m_rotationVec;

	glm::vec3 m_velGLM;
	glm::vec3 m_accGLM;
	glm::vec3 m_forceGLM;

	glm::vec3 m_dirGLM;
	glm::vec3 m_upGLM;
	glm::vec3 m_forwardGLM;
	glm::vec3 m_rightGLM;
	glm::vec3 m_rotVecGLM;

	// Transform will include everything from the 
	// three other matrices combined (or should 
	// if you do it right)
	Mat4x4<float> m_transform;
	Mat4x4<float> m_translateMat;
	Mat4x4<float> m_rotateMat;
	Mat4x4<float> m_scaleMat;

	Model m_model;

	AABB m_collider;
};


#endif