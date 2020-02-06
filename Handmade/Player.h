#ifndef PLAYER_H
#define PLAYER_H

#include "DebugManager.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Matrix4x4.h"
#include <glm.hpp>


class Player : public GameObject
{
public:
	Player();
	Player(float x, float y, float z);

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();


private:
	float m_vel;

	Vec3<float> m_drone;

	Vec3<float> m_direction;

	Vec3<float> m_up;
	Vec3<float> m_forward;
	Vec3<float> m_right;

	float m_angle;

	Vec3<float> m_rotationVec;

	Mat4x4<float> m_transform;

};


#endif