#ifndef LIFE_H
#define LIFE_H

#include "GameObject.h"
#include "Sprite.h"


class Life : public GameObject
{
public :
	Life();
	virtual ~Life();

	virtual bool Create() { return true; }
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void OnCollision(GameObject* go);


private:
	Sprite m_sprite;
	

};

#endif