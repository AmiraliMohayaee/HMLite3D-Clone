#ifndef SKY_BOX_H
#define SKY_BOX_H

#include "GameObject.h"
#include "Model.h"
#include "Audio.h"

class Skybox : public GameObject
{
public:
	Skybox();
	Skybox(float x, float y, float z);

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void OnCollision(GameObject* go);


private:
	Model m_model;
	Audio m_music;

	float m_rotAngle;
};


#endif