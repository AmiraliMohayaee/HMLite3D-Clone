#ifndef ENEMY_SHOT_H
#define ENEMY_SHOT_H


#include "GameObject.h"
#include "Model.h"
#include "AABB.h"


class EnemyShot : public GameObject
{
	EnemyShot(float x, float y, float z);

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void OnCollision(GameObject* go);


	const AABB& GetCollider() const;
	const SphereCollider& GetSphereCollider() const;


private:
	float m_vel;

	glm::mat4 m_transformMat;
	glm::mat4 m_rotMat;
	glm::mat4 m_scaleMat;


	Model m_model;
};


#endif
