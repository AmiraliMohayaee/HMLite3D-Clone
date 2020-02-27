#pragma once

#include "Vec3.h"
#include "GameObject.h"


class TestObject : public GameObject
{
public:
	TestObject();
	TestObject(float x, float y, float z);

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void OnCollision(GameObject* go);




private:
	

};

