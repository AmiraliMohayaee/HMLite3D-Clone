#ifndef LASER_H
#define LASER_H


#include "GameObject.h"
#include "Model.h"


class Laser : public GameObject
{
public:
	Laser();
	~Laser();

	Laser(float x, float y, float z);

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void OnCollision(GameObject* go);

	void PlayerShotDraw();
	void EnemyShotDraw();
	void PlayerUpdate();
	void EnemyUpdate();


	const AABB& GetCollider() const;
	const SphereCollider& GetSphereCollider() const;

	
private:
	float m_vel;
	
	Model m_playerLaser;
	Model m_enemyLaser;
};

#endif