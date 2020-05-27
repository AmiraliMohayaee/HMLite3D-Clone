#ifndef LIFE_H
#define LIFE_H

#include "GameObject.h"
#include "Sprite.h"


class Life : public GameObject
{
public :
	Life();
	virtual ~Life();

	void SetHealthVal(const int val);
	const int CheckLife();

	virtual bool Create() { return true; }
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void OnCollision(GameObject* go) { }

private:
	Sprite m_sprite;
	int m_healthVal;

};

#endif