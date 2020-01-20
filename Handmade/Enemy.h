#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "DebugManager.h"
#include "InputManager.h"


class Enemy : public GameObject
{
public:
	Enemy();

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();


private:
	float m_xPos;
	float m_yPos;
	float m_zPos;

	float m_xRot;
	float m_yRot;
	float m_zRot;

	float m_XAngle;
	float m_YAngle;
	float m_ZAngle;
};


#endif