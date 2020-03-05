#ifndef ASTEROID_H
#define ASTEROID_H


#include "GameObject.h"
#include "Model.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "AABB.h"
#include "SphereCollider.h"


class Asteroid : public GameObject
{
public:
	Asteroid(float x, float y, float z);

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

	SphereCollider m_SPcollider;
};


#endif