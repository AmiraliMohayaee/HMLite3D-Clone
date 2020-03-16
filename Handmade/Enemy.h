#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "DebugManager.h"
#include "InputManager.h"
#include "Model.h"
#include "AABB.h"
#include "SphereCollider.h"
#include <glm.hpp>
#include "Player.h"
#include "PlayerShot.h"


class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(float x, float y, float z);

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	const AABB& GetCollider() const;
	const SphereCollider& GetSphereCollider() const;



private:
	Model m_model;

	glm::vec3 m_acc;
	glm::vec3 m_vel;

	Player* playerPtr;
};


#endif