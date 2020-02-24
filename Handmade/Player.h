#ifndef PLAYER_H
#define PLAYER_H

#include "DebugManager.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Matrix4x4.h"
#include <glm.hpp>
#include "Model.h"
#include "Transformation.h"
#include "AABB.h"


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


	const AABB& GetCollider() const;


private:
	float m_vel;
	float m_angle;

	Vec3<float> m_drone;

	Vec3<float> m_direction;

	Vec3<float> m_up;
	Vec3<float> m_forward;
	Vec3<float> m_right;

	Vec3<float> m_rotationVec;

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