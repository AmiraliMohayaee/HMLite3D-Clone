#include "WinState.h"
#include "PipelineManager.h"


WinState::WinState(GameState* state) : GameState(state)
{
	m_HUDCamera = nullptr;
	m_splashScreen_1 = nullptr;
	m_splashScreen_2 = nullptr;
}

bool WinState::OnEnter()
{
	m_HUDCamera = new HUDCamera();
	m_splashScreen_1 = new SplashScreen("Assets\\Sprites\\Win.png");
	m_splashScreen_1->Create();

	m_splashScreen_2 = new SplashScreen("Assets\\Sprites\\Games.png");
	m_splashScreen_2->Create();

	return true;
}

bool WinState::Update()
{
#ifdef DEBUG

	m_isActive = m_isAlive = false;

#endif

#ifdef RELEASE


	if (m_splashScreen_1->IsActive())
	{
		m_splashScreen_1->Update();
	}
	else if (m_splashScreen_2->IsActive())
	{
		m_splashScreen_2->Update();
	}
	else
	{

	}


#endif

	return true;

}

bool WinState::Draw()
{
#ifdef RELEASE

	m_HUDCamera->Draw();
	m_splashScreen_1->Draw();
	m_splashScreen_1->Draw();

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
