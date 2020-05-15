#ifndef TEST_STATE_H
#define TEST_STATE_H

#include "GameState.h"
#include "HUD.h"
#include "HUDCamera.h"
#include "MainCamera.h"
#include "Player.h"
#include "Enemy.h"
#include "Planet.h"
#include "TestObject.h"



class TestState : public GameState
{
public:

	TestState(GameState* state);
	virtual ~TestState() {}

public:

	virtual bool OnEnter();
	virtual bool Update();
	virtual bool Draw();
	virtual void OnExit();

private:

	HUD* m_HUD;
	HUDCamera* m_HUDCamera;
	MainCamera* m_mainCamera;

	TestObject* m_testObject;
};

#endif


