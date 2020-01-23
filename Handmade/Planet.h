#ifndef PLANET_H
#define PLANET_H

#include "DebugManager.h"
#include "GameObject.h"
#include <glm.hpp>


class Planet : public GameObject
{
public:
	Planet();
	Planet(float x, float y, float z);

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();


private:
	glm::vec3 m_pos;
	glm::vec3 m_orbitalPos;
	float m_angle;
};



#endif