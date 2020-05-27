#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "GameObject.h"
#include "Audio.h"
#include "Animation.h"


class Explosion : public GameObject
{
public:
	Explosion(float x, float y, float z, const std::string& ID);
	virtual ~Explosion();

	virtual bool Create() { return true; }
	virtual void Update();
	virtual void Draw();
	virtual void Destroy() {}


private:
	Audio m_sfx;
	Animation m_animation;

};


#endif