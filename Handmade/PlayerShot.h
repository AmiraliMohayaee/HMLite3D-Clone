#ifndef PLAYER_SHOT_H
#define PLAYER_SHOT_H

#include "GameObject.h"


class PlayerShot : public GameObject
{
public:
	PlayerShot();
	~PlayerShot();

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();


private:

};

#endif