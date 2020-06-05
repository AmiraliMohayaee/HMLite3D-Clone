#include "WinState.h"
#include "PipelineManager.h"
#include "DebugManager.h"


WinState::WinState(GameState* state) : GameState(state)
{
	m_HUDCamera = nullptr;
	m_splashScreen_1 = nullptr;
	m_splashScreen_2 = nullptr;
}

bool WinState::OnEnter()
{
	m_HUDCamera = new HUDCamera();
	
	m_splashScreen_1 = new SplashScreen("Assets/Sprites/Games.png");
	m_splashScreen_2 = new SplashScreen("Assets/Sprites/SAE.png");
	
	m_splashScreen_1->Create();
	m_splashScreen_2->Create();

	m_splashScreen_2->IsActive() = false;

	return true;
}

bool WinState::Update()
{
	// Exiting the state if in Debug
#ifdef DEBUG

	m_isActive = m_isAlive = false;

#endif

#ifdef RELEASE


	if (m_splashScreen_1->IsActive())
	{
		m_splashScreen_1->Update();
	}
	else 
	{
		m_splashScreen_2->IsActive() = true;
	}


	if (m_splashScreen_2->IsActive())
	{
		m_splashScreen_2->Update();
		m_isActive = m_isAlive = m_splashScreen_2->IsActive();
	}



#endif

	return true;

}

bool WinState::Draw()
{
#ifdef RELEASE

	if (m_splashScreen_1->IsActive())
	{
		m_HUDCamera->Draw();
		m_splashScreen_1->Draw();
	}

	if (m_splashScreen_2->IsActive())
	{
		m_HUDCamera->Draw();
		m_splashScreen_2->Draw();
	}

#endif

	return true;
}

void WinState::OnExit()
{

#ifdef DEBUG

	TheDebug::Instance()->DestroyDebugObjects();

#endif


	ThePipeline::Instance()->DetachShaders();
	ThePipeline::Instance()->DestroyShaders();
	ThePipeline::Instance()->DestroyProgram();

	m_splashScreen_1->Destroy();
	m_splashScreen_2->Destroy();
	delete m_splashScreen_1;
	delete m_splashScreen_2;
	delete m_HUDCamera;
}
