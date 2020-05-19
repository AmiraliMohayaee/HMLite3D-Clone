#include "DebugManager.h"
#include "EndState.h"
#include "StartState.h"	
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
	m_testText = nullptr;
	m_HUD = nullptr;
	m_HUDCamera = nullptr;
	m_mainCamera = nullptr;

	m_player = nullptr;
	
	// Setting up 
	for (size_t i = 0; i < maxEnemies; i++)
	{
		m_enemies[i] = nullptr;
	}

	for (size_t i = 0; i < maxAsteroids; i++)
	{
		m_asteroids[i] = nullptr;
	}

	m_skyBox = nullptr;
}

//------------------------------------------------------------------------------------------------------
//function that creates the cameras and HUD objects
//------------------------------------------------------------------------------------------------------
bool MainState::OnEnter()
{
	m_testText = new TextBox(10, 10, 0, 100, "TEXT_1");
	m_testText->SetText("Hello!");

	m_scoreText = new TextBox(10, 600, 0, 50, "SCORETEXT");
	//m_scoreText->SetText("Current Score is: " + std::to_string());

	m_player = new Player(0.0f, 0.0f, 0.0f);
	m_player->SetTag("Player");

	srand(time(0));

	for (size_t i = 0; i < maxEnemies; i++)
	{
		m_enemies[i] = new Enemy(float(rand() % 4) + 5.0f, 0.0f, float(rand() % -5) - 15.0f);
		m_enemies[i]->SetTag("Baddies_" + std::to_string(i));
	}


	// Setting up seeds for randomizing asteroid pos
	// based on current time as seed for the randomizer

	for (size_t i = 0; i < maxAsteroids; i++)
	{
		m_asteroids[i] = new Asteroid(float(rand() % -4) - 5.0f, 0.0f, float(rand() % -5) - 15.0f);
		m_asteroids[i]->SetTag("Asteroids_" + std::to_string(i));
	}


	// To-Do: Add more



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
		if (m_enemies[i] != nullptr)
		{
			m_enemies[i]->Update();

			// Testing Collisions
			if (m_enemies[i]->GetCollider().IsColliding
			(m_player->GetSphereCollider()))
			{
				m_player->OnCollision(m_enemies[i]);
				//m_player->HealthDown(10);
				//m_enemies[i]->IsAlive() = false;
				//delete m_enemies[i];
				//m_enemies[i] = nullptr;
			}
			else
			{
				Utility::Log("Not Colliding");
			}
		}
	}

	for (size_t i = 0; i < maxAsteroids; i++)
	{
		if (m_asteroids[i] != nullptr)
		{
			m_asteroids[i]->Update();

			if (m_asteroids[i]->GetSphereCollider().IsSphereColliding
			(m_player->GetSphereCollider()))
			{
				m_player->OnCollision(m_asteroids[i]);
				//m_asteroids[i]->IsAlive() = false;
				//delete m_asteroids[i];
				//m_asteroids[i] = nullptr;
			}
			else
			{
				Utility::Log("Not Colliding");
			}
		}
	}


	m_planet->Update();
	m_skyBox->Update();


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
		if (m_enemies[i] != nullptr)
		{
			m_enemies[i]->Draw();
		}
	}

	for (size_t i = 0; i < maxAsteroids; i++)
	{
		if (m_asteroids[i] != nullptr)
		{
			m_asteroids[i]->Draw();
		}
	}
	
	m_planet->Draw();
	m_skyBox->Draw();




#ifdef DEBUG

	//set the 2D camera and render the heads-up display last

	//m_HUD->Draw();

	// Setting up an Ortho projection
	// Move this out of Debug later
	TheScreen::Instance()->Set2DScreen(ScreenManager::BOTTOM_LEFT);
	m_HUDCamera->Draw();
	m_testText->Draw();

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
	delete m_testText;
	delete m_scoreText;
}