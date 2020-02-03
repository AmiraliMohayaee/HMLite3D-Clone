#include "DebugManager.h"
#include "EndState.h"
#include "StartState.h"	// Remove later
#include "InputManager.h"
#include "Game.h"
#include "MainState.h"
#include "PipelineManager.h"
#include "ScreenManager.h"
#include "Utility.h"

//------------------------------------------------------------------------------------------------------
//constructor that assigns all default values
//------------------------------------------------------------------------------------------------------
MainState::MainState(GameState* state) : GameState(state)
{
	m_HUD = nullptr;
	m_HUDCamera = nullptr;
	m_mainCamera = nullptr;

	m_player = nullptr;
	m_enemy = nullptr;
	m_player = nullptr;
}
//------------------------------------------------------------------------------------------------------
//function that creates the cameras and HUD objects
//------------------------------------------------------------------------------------------------------
bool MainState::OnEnter()
{
	m_player = new Player();
	m_enemy = new Enemy();
	m_planet = new Planet(1.0f, 1.0f, 1.0f);

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
bool MainState::Update()
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


	m_player->Update();
	//m_enemy->Update();
	m_planet->Update();


	// To-Do: Output log info into files
	Utility::Log("Updating Main State");

	double radian = 4.0;
	double degree = 180.0;

	//Utility::Log(Utility::DegToRad(degree), "Degree is");
	//Utility::Log(Utility::RadToDeg(radian), "Rad is");
	//Utility::Log(Utility::LineDistance(0, 0, 5, 3), "The Pythagorem results are ");

	//Utility::Log(m_player->GetPos().x, "Player's X Value is: ");
	//Utility::Log(m_player->GetPos().y, "Player's Y Value is: ");

	// Checking vector distance between two GOs
	//Utility::Log(Utility::LineDistance(m_player->GetPos(), m_enemy->GetPos()), 
	//	"Distance between the player and enemy is: ");


	
	return true;
}

//------------------------------------------------------------------------------------------------------
//function that displays all active and visible game objects in game state
//------------------------------------------------------------------------------------------------------
bool MainState::Draw()
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
	m_player->Draw();
	//m_enemy->Draw();
	m_planet->Draw();


	//GameObject::SetIdentity();

	//static float xMove = 0.01f;
	//static float zMove = 0.01f;

	//xMove += 0.001f;
	//zMove -= 0.001f;

	//GameObject::Translate(xMove, 0.0f, zMove);
	//GameObject::Rotate(45.0f, 0.0, 1.0, 0.0);
	//TheDebug::Instance()->DrawCube3D(2.0f, 2.0f, 2.0f, 10.0f, 10.0f, 10.0f, 0.5f);

	//GameObject::SetIdentity();	// Resetting the matrix to identity

	//static float angle = 0;
	//angle += 5.0f;

	//GameObject::Rotate(angle, 0.0f, 1.0f, 1.0f);
	//GameObject::Translate(2.0f, 0.0f, 0.0f);
	//TheDebug::Instance()->DrawSphere3D(2.0f, 1.0f, 1.0f, 1.0f, 0.5f);

	//glm::cos(2.0f);


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
void MainState::OnExit()
{

	//destroy the HUD, camera and grid objects
	m_HUD->Destroy();
	delete m_HUD;
	delete m_HUDCamera;
	delete m_mainCamera;
	delete m_player;
	delete m_enemy;
}