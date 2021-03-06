#include "TestState.h"
#include "DebugManager.h"
#include "EndState.h"
#include "StartState.h"	// Remove later
#include "InputManager.h"
#include "Game.h"
#include "PipelineManager.h"
#include "ScreenManager.h"
#include "Utility.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>


//------------------------------------------------------------------------------------------------------
//constructor that assigns all default values
//------------------------------------------------------------------------------------------------------
TestState::TestState(GameState* state) : GameState(state)
{
	m_HUD = nullptr;
	m_HUDCamera = nullptr;
	m_mainCamera = nullptr;
	m_testObject = nullptr;

}

//------------------------------------------------------------------------------------------------------
//function that creates the cameras and HUD objects
//------------------------------------------------------------------------------------------------------
bool TestState::OnEnter()
{
	m_testObject = new TestObject(0.0f, 0.0f, 0.0f);
	m_testObject->SetTag("TestObject");

	//create the main camera to control the main view
	m_mainCamera = new MainCamera();

	//create the 2D camera for HUDs and sprite objects
	m_HUDCamera = new HUDCamera();

	//create a heads-up display object
	m_HUD = new HUD();
	m_HUD->Create();

	return true;
}

//------------------------------------------------------------------------------------------------------
//function that updates all active game objects in game state
//------------------------------------------------------------------------------------------------------
bool TestState::Update()
{

	//store keyboard key states in a temp variable for processing below
	const Uint8* keyState = TheInput::Instance()->GetKeyStates();

	//update main camera
	m_mainCamera->Update();

	//if ESCAPE key was pressed, return flag to end game 
	if (keyState[SDL_SCANCODE_ESCAPE])
	{
		m_isActive = m_isAlive = false;
		TheGame::Instance()->ChangeState(new EndState(this));
	}

	if (keyState[SDL_SCANCODE_SPACE])
	{
		m_isActive = false;	// We'll keep things in memory 
		TheGame::Instance()->ChangeState(new StartState(this));
	}

	m_testObject->Update();

	return true;
}

//------------------------------------------------------------------------------------------------------
//function that displays all active and visible game objects in game state
//------------------------------------------------------------------------------------------------------
bool TestState::Draw()
{
	//first set up camera which sets the view accordingly
	//make sure this is called BEFORE displaying the grid
	m_mainCamera->Draw();

#ifdef GAME_3D

	TheScreen::Instance()->Set3DScreen(60.0f, 0.1f, 1000.0f);


#ifdef DEBUG

	TheDebug::Instance()->DrawGrid3D();
	TheDebug::Instance()->DrawCoordSystem3D(15.0f);

#endif

#endif

#ifdef GAME_2D

	TheScreen::Instance()->Set2DScreen(ScreenManager::BOTTOM_LEFT);

#ifdef DEBUG

	TheDebug::Instance()->DrawGrid2D();
	TheDebug::Instance()->DrawCoordSystem2D(15.0f);

#endif

#endif
	
	// Make GOs here
	m_testObject->Draw();


#ifdef DEBUG

	//set the 2D camera and render the heads-up display last
	m_HUDCamera->Draw();
	m_HUD->Draw();

#endif

	return true;

}
//------------------------------------------------------------------------------------------------------
//function that destroys all the game objects for the state
//------------------------------------------------------------------------------------------------------
void TestState::OnExit()
{

	//destroy the HUD, camera and grid objects
	m_HUD->Destroy();
	delete m_HUD;
	delete m_HUDCamera;
	delete m_mainCamera;
}