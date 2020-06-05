#ifndef WIN_STATE_H
#define WIN_STATE_H

#include "GameState.h"
#include "HUDCamera.h"
#include "SplashScreen.h"


class WinState : public GameState
{
public:

	WinState(GameState* state);
	virtual ~WinState() {}

	virtual bool OnEnter();
	virtual bool Update();
	virtual bool Draw();
	virtual void OnExit();

private:

	HUDCamera* m_HUDCamera;
	SplashScreen* m_splashScreen_1;
	SplashScreen* m_splashScreen_2;

};

#endif