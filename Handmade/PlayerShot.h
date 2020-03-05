#ifndef PLAYER_SHOT_H
#define PLAYER_SHOT_H


#include "GameObject.h"
#include "Model.h"


class PlayerShot : public GameObject
{
public:
	PlayerShot();
	~PlayerShot();

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void OnCollision(GameObject* go);


	const AABB& GetCollider() const;
	const SphereCollider& GetSphereCollider() const;


private:
	Model m_model;


};

#endif