#include "DebugManager.h"
#include "EndState.h"
#include "StartState.h"	// Remove later
#include "InputManager.h"
#include "Game.h"
#include "MainState.h"
#include "PipelineManager.h"
#include "ScreenManager.h"
#include "Utility.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <time.h>


//------------------------------------------------------------------------------------------------------
//constructor that assigns all default values
//------------------------------------------------------------------------------------------------------
MainState::MainState(GameState* state) : GameState(state)
{
	m_HUD = nullptr;
	m_HUDCamera = nullptr;
	m_mainCamera = nullptr;

	m_player = nullptr;
	
	for (size_t i = 0; i < maxEnemies; i++)
	{
		m_enemies[i] = nullptr;
	}

	for (size_t i = 0; i < maxAsteroids; i++)
	{
		m_asteroids[i] = nullptr;
	}

	m_skyBox = nullptr;

	m_asteroidSeed = 0.0f;
	m_enemySeed = 0.0f;
}

//------------------------------------------------------------------------------------------------------
//function that creates the cameras and HUD objects
//------------------------------------------------------------------------------------------------------
bool MainState::OnEnter()
{
	m_player = new Player(0.0f, 0.0f, 1.0f);
	m_player->SetTag("Player");

	srand(time(0));

	//m_enemies[1] = new Enemy(-2.0f, 0.0f, -3.0f);
	//m_enemies[1]->SetTag("Baddies2");

	for (size_t i = 0; i < maxEnemies; i++)
	{
		m_enemies[i] = new Enemy(0.0f, (rand() % 2) + -1.0f, (rand() % -10) + -5.0f);;
		m_enemies[i]->SetTag("Baddies" + i);
	}


	// Setting up seeds for randomizing asteroid pos
	// based on current time as seed for the randomizer


	for (size_t i = 0; i < maxAsteroids; i++)
	{
		m_asteroids[i] = new Asteroid(0.0f, (rand() % 2) + -1.0f, (rand() % -10) + -5.0f);
		m_asteroids[i]->SetTag("Asteroids" + i);
	}


	// To-Do: Add more

	//m_asteroids[0] = new Asteroid(0.0f, 0.0f, -5.0f);	
	//m_asteroids[0]->SetTag("Asteroids");
	//m_asteroids[1] = new Asteroid(0.0f, -3.0f, -5.0f);
	//m_asteroids[1]->SetTag("Asteroids2");
	


	// Spawning Skybox
	m_skyBox = new Skybox(0.0f, 0.0f, 0.0f);

	// Spawning Planet 
	m_planet = new Planet(1.0f, 1.0f, -15.0f);

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


	m_player->Update();
	
	for (size_t i = 0; i < maxEnemies; i++)
	{
		m_enemies[i]->Update();
	}

	for (size_t i = 0; i < maxAsteroids; i++)
	{
		m_asteroids[i]->Update();
	}


	m_planet->Update();
	m_skyBox->Update();


	// Testing Collisions
	//if (m_player->GetCollider().IsColliding
	//	(m_enemies[0]->GetCollider()))
	//{
	//	m_player->OnCollision(m_enemies[0]);
	//}
	//else
	//{
	//	Utility::Log("Not Colliding");
	//}

	if (m_player->GetSphereCollider().IsSphereColliding
		(m_enemies[0]->GetSphereCollider()))
	{
		m_player->OnCollision(m_enemies[0]);
	}
	else
	{
		Utility::Log("Not Colliding");
	}



	// To-Do: Output log info into files
	//Utility::Log("Updating Main State");
	
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


	for (size_t i = 0; i < maxEnemies; i++)
	{
		m_enemies[i]->Draw();
	}

	for (size_t i = 0; i < maxAsteroids; i++)
	{
		m_asteroids[i]->Draw();
	}
	
	m_planet->Draw();
	m_skyBox->Draw();




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

	for (size_t i = 0; i < maxEnemies; i++)
	{
		delete m_enemies[i];
	}

	for (size_t i = 0; i < maxAsteroids; i++)
	{
		delete m_asteroids[i];
	}

	delete m_skyBox;
}