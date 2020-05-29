#ifndef LASER_H
#define LASER_H


#include "GameObject.h"
#include "Model.h"
#include "Audio.h"


class Laser : public GameObject
{
public:
	Laser();
	virtual ~Laser();

	Laser(const glm::vec3& pos, const glm::vec3& vel);

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void OnCollision(GameObject* go);

	void PlayerShotDraw();
	void EnemyShotDraw();
	void PlayerUpdate();
	void EnemyUpdate();


	//const AABB& GetCollider() const;
	const SphereCollider& GetSphereCollider() const;

	
private:
	float m_followPos;

	glm::mat4 m_matrix;
	
	Model m_playerLaser;
	Model m_enemyLaser;

	Audio m_sfx;

	//AABB m_collider;
	SphereCollider m_sphereCollider;
};

#endif