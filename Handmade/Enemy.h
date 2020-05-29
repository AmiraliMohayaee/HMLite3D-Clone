#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "DebugManager.h"
#include "InputManager.h"
#include "Model.h"
#include "AABB.h"
#include <glm.hpp>
#include "Player.h"
#include "Laser.h"
#include "SphereCollider.h"


class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(float x, float y, float z);

	virtual bool Create() { return true;  }
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	const SphereCollider& GetSphereCollider() const;



private:
	Model m_model;

	glm::vec3 m_startPos;

	SphereCollider m_sphereCollider;
};


#endif