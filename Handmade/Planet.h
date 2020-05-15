#ifndef PLANET_H
#define PLANET_H

#include "DebugManager.h"
#include "GameObject.h"
#include <glm.hpp>
#include "Model.h"
#include "Moon.h"


class Planet : public GameObject
{
public:
	Planet();
	Planet(float x, float y, float z);

	virtual bool Create() { return false; }
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();


private:
	Vec3<float> m_orbitalPos;
	float m_angle;

	Model m_model;

	Moon* m_moon;
};



#endif