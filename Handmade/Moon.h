#ifndef MOON_H
#define MOON_H


#include "GameObject.h"
#include "Model.h"


class Moon : public GameObject
{
public:
	Moon(float x, float y, float z);

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void OnCollision(GameObject* go);


private:
	Model m_model;

};


#endif