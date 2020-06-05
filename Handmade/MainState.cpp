#include "DebugManager.h"
#include "EndState.h"
#include "WinState.h"
#include "StartState.h"	
#include "InputManager.h"
#include "Game.h"
#include "MainState.h"
#include "PipelineManager.h"
#include "ScreenManager.h"
#include "Utility.h"
#include <stdlib.h>
#include <time.h>
#include <string>


//------------------------------------------------------------------------------------------------------
//constructor that assigns all default values
//------------------------------------------------------------------------------------------------------
MainState::MainState(GameState* state) : GameState(state)
{
	m_life = nullptr;
	m_laser = nullptr;
	m_scoreText = nullptr;
	m_testText = nullptr;
	m_lifeDisplay = nullptr;
	m_instructions1 = nullptr;
	m_instructions2 = nullptr;
	m_instructions3 = nullptr;

	m_explosion = nullptr;
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

	m_isExploCreated = false;
}

//------------------------------------------------------------------------------------------------------
//function that creates the cameras and HUD objects
//------------------------------------------------------------------------------------------------------
bool MainState::OnEnter()
{
	////////////////////////////
	// Setting up Text Boxes
	m_testText = new TextBox(10, 10, 0, 30, "TEXT_1");
	m_testText->SetText("Avoid obstacles and go as far as you can.");

	m_instructions1 = new TextBox(10, 30, 0, 30, "INSTRUC_1");
	m_instructions1->SetText("Use the arrow keys to move.");

	m_instructions2 = new TextBox(10, 60, 0, 30, "INSTRUC_2");
	m_instructions2->SetText("Press Left Shift to break");

	m_instructions3 = new TextBox(10, 120, 0, 30, "INSTRUCT_3");
	m_instructions3->SetText("Reach a score of 10K to pass the stage");

	m_scoreText = new TextBox(10, 700, 0, 30, "SCORETEXT");
	m_lifeDisplay = new TextBox(10, 650, 0, 30, "LIFETEXT");
	////////////////////////////

	m_player = new Player(0.0f, 0.0f, 0.0f);
	m_player->SetTag("Player");

	// Setting health values for on screen hud element
	m_player->SetLife(100);
	//m_laser = m_player->GetBullet();
	

	srand(time(0));

	for (size_t i = 0; i < maxEnemies; i++)
	{
		m_enemies[i] = new Enemy(float(rand() % 12) - 6.0f, 0.0f, float(rand() % -5) - 20.0f);
		m_enemies[i]->SetTag("Baddies_" + std::to_string(i));
	}


	// Setting up seeds for randomizing asteroid pos
	// based on current time as seed for the randomizer

	for (size_t i = 0; i < maxAsteroids; i++)
	{
		m_asteroids[i] = new Asteroid(float(rand() % 12) - 6.0f, 0.0f, float(rand() % -5) - 20.0f);
		m_asteroids[i]->SetTag("Asteroids_" + std::to_string(i));
	}


	m_life = new Life();
	m_life->SetHealthVal(m_player->GetLife());

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

	static int count = 0;

	//if ESCAPE key was pressed, return flag to end game 
	if (keyState[SDL_SCANCODE_ESCAPE])
	{
		m_isActive = m_isAlive = false;
		TheGame::Instance()->ChangeState(new EndState(this));
	}

	
	for (size_t i = 0; i < maxEnemies; i++)
	{
		if (m_enemies[i] != nullptr)
		{
			m_enemies[i]->Update();

			// Testing Collisions
			if (m_enemies[i]->GetSphereCollider().IsSphereColliding
			(m_player->GetSphereCollider()))
			{
				// When colliding with an enemy, lose
				// player life and destroy the enemy
				m_player->OnCollision(m_enemies[i]);
				m_player->LifeLoss(20);
				// Explosion
				if (!m_isExploCreated)
				{
					m_explosion = new Explosion(10.0f, 650.0f, 0.0f,
						"EXPLOSION" + std::to_string(count++));
					m_isExploCreated = true;
				}

				m_enemies[i]->IsAlive() = false;
				delete m_enemies[i];
				m_enemies[i] = nullptr;
	
			}
			else if (m_player->IsLaserCreated())
			{
				if (m_enemies[i]->GetSphereCollider().IsSphereColliding
				(m_player->GetLaserCollision()))
				{
					m_enemies[i]->IsAlive() = false;
					delete m_enemies[i];
					m_enemies[i] = nullptr;

					// Delete the bullet later

				}
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
				m_player->LifeLoss(20);

				if (!m_isExploCreated)
				{
					m_explosion = new Explosion(10.0f, 650.0f, 0.0f,
						"EXPLOSION" + std::to_string(count++));
					m_isExploCreated = true;
				}

				m_asteroids[i]->IsAlive() = false;
				delete m_asteroids[i];
				m_asteroids[i] = nullptr;
			}
			else
			{
				Utility::Log("Not Colliding");
			}
		}
	}

	// Constantly incrementing score 
	m_player->SetScore(10);
	m_player->Update();


	// Setting the win or loss states
	if (m_player->GetScore() > 10000)
	{
		m_isActive = m_isAlive = false;
		TheGame::Instance()->ChangeState(new WinState(this));
	}
	// If player dies or gets a high score 
	// go to the next state
	if (m_player->GetLife() == 0)
	{
		m_isActive = m_isAlive = false;
		TheGame::Instance()->ChangeState(new EndState(this));
	}


	m_planet->Update();
	m_skyBox->Update();

	if (m_isExploCreated)
	{
		m_explosion->Update();

		if (!m_explosion->IsAlive())
		{
			delete m_explosion;
			m_explosion = nullptr;
			m_isExploCreated = false;
		}
	}

	//=============================================
	// Adding score per frame

	m_lifeDisplay->SetText("Current Health is :" + std::to_string(m_player->GetLife()));
	m_lifeDisplay->Update();
	m_scoreText->SetText("Current Score is: " + std::to_string(m_player->GetScore()));
	m_scoreText->Update();
	m_life->SetHealthVal(m_player->GetLife());
	m_life->Update();
	m_instructions1->Update();
	m_instructions2->Update();
	m_instructions3->Update();
	//=============================================

	
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



	TheScreen::Instance()->Set2DScreen(ScreenManager::BOTTOM_LEFT);

#ifdef DEBUG

	//set the 2D camera and render the heads-up display last

	//m_HUD->Draw();

	// Setting up an Ortho projection
	// Move this out of Debug later

#endif
	m_HUDCamera->Draw();
	m_testText->Draw();
	m_lifeDisplay->Draw();
	m_scoreText->Draw();
	m_life->Draw();
	m_instructions1->Draw();
	m_instructions2->Draw();
	m_instructions3->Draw();

	if (m_isExploCreated == true)
	{
		m_explosion->Draw();
	}

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
	delete m_explosion;
	delete m_life;
	delete m_lifeDisplay;
	delete m_instructions1;
	delete m_instructions2;
	delete m_instructions3;
}