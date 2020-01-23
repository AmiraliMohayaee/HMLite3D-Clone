#ifndef PLAYER_H
#define PLAYER_H

#include "DebugManager.h"
#include "GameObject.h"
#include "InputManager.h"
#include <glm.hpp>


class Player : public GameObject
{
public:
	Player();

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();


private:
	float m_xRot;
	float m_yRot;
	float m_zRot;

	float m_XAngle;
	float m_YAngle;
	float m_ZAngle;
};


#endif