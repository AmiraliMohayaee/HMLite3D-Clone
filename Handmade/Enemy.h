#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "DebugManager.h"
#include "InputManager.h"
#include "Model.h"
#include <glm.hpp>


class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(float x, float y, float z);

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();


private:
	
	Model m_model;

};


#endif