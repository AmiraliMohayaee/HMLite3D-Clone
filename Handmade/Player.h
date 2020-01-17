#ifndef PLAYER_H
#define PLAYER_H

#include "DebugManager.h"
#include "GameObject.h"
#include "InputManager.h"


class Player : public GameObject
{
public:
	Player();

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

	float m_angle;
};


#endif