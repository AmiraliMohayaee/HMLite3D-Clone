#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <glm.hpp>
#include "Model.h"
#include "Transform.h"
#include "AABB.h"
#include "SphereCollider.h"
#include "Laser.h"
#include "Enemy.h"
#include "Explosion.h"
#include "Life.h"


class Player : public GameObject
{
public:
	Player();
	Player(float x, float y, float z);

	// For the lifebar 
	void SetLife(unsigned int life);
	const int GetLife();
	void LifeLoss(int lifeLoss);

	// For Player Score
	void SetScore(int score);
	const int GetScore();

	// Getting Laser's collision bounds
	const SphereCollider& GetLaserCollision() const;
	const Laser GetBullet() const;

	bool IsLaserCreated() const;
	bool IsLaserColliding(const SphereCollider& other) const;

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void OnCollision(GameObject* go);

	const SphereCollider& GetSphereCollider() const;


private:
	Laser* m_bullet;
	Explosion* m_explosion;
	Life* m_life;

	int m_health;
	int m_score;

	float m_vel;
	float m_velCap;
	float m_angle;

	glm::vec3 m_velGLM;
	glm::vec3 m_accGLM;
	glm::vec3 m_forceGLM;

	glm::vec3 m_dirGLM;
	glm::vec3 m_upGLM;
	glm::vec3 m_forwardGLM;
	glm::vec3 m_rightGLM;
	glm::vec3 m_rotVecGLM;


	Model m_model;

	SphereCollider m_sphereCollider;
};


#endif