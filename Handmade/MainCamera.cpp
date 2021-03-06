#include "InputManager.h"
#include "MainCamera.h"
#include "ScreenManager.h"

//------------------------------------------------------------------------------------------------------
//constructor that assigns all camera default properties based on game setting 
//------------------------------------------------------------------------------------------------------
MainCamera::MainCamera()
{

#ifdef GAME_3D

		m_camera.Position().x = 0;
		m_camera.Position().y = 5;
		m_camera.Position().z = 4;
		//m_camera.RotateY(-45);
		m_camera.RotateX(30);
		m_camera.SetSensitivity(0.4f);
		m_camera.IsFreeFlow() = false;

#ifdef DEBUG
		m_camera.SetVelocity(5.0f);	// Turn off when creating full game
#endif

#endif

#ifdef GAME_2D

		m_camera.Position().z = 0;
		m_camera.Position().x = (float)(-5 * TheScreen::Instance()->GetPixelsPerUnit());
		m_camera.Position().y = (float)(-5 * TheScreen::Instance()->GetPixelsPerUnit());
		m_camera.SetVelocity(10.0f * TheScreen::Instance()->GetPixelsPerUnit());
		m_camera.SetSensitivity(0.0f);
		m_camera.IsFreeFlow() = false;

#endif

#ifdef DEBUG
	//disable mouse cursor so that it does not interfere when rotating the camera
	TheInput::Instance()->SetMouseCursorState(InputManager::OFF);
#endif
}
//------------------------------------------------------------------------------------------------------
//function that updates the camera and reads key and mouse input  
//------------------------------------------------------------------------------------------------------
void MainCamera::Update()
{

	//store keyboard key states in a temp variable for processing below
	const Uint8* keyState = TheInput::Instance()->GetKeyStates();

#ifdef DEBUG
	//if a key has been released, stop the camera from moving
	if (!(TheInput::Instance()->IsKeyPressed()))
	{
		m_camera.Stop();
	}

	//if Q is pressed move camera up
	if (keyState[SDL_SCANCODE_Q])
	{
		m_camera.MoveUp();
	}

	//if E is pressed move camera down
	else if (keyState[SDL_SCANCODE_E])
	{
		m_camera.MoveDown();
	}
#endif



#ifdef DEBUG
	//if game is in 3D mode check for forward and backward movement
	//in 2D mode this is not necessary as there is no depth!
#ifdef GAME_3D

	//if W is pressed move camera forwards
	if (keyState[SDL_SCANCODE_W])
	{
		m_camera.MoveForward();
	}

	//if S is pressed move camera backwards
	else if (keyState[SDL_SCANCODE_S])
	{
		m_camera.MoveBackward();
	}

	//if A is pressed move camera left
	if (keyState[SDL_SCANCODE_A])
	{
		m_camera.MoveLeft();
	}

	//if D is pressed move camera right
	else if (keyState[SDL_SCANCODE_D])
	{
		m_camera.MoveRight();
	}

	if (keyState[SDL_SCANCODE_R])
	{
		m_camera.MoveUp();
	}
	else if (keyState[SDL_SCANCODE_F])
	{
		m_camera.MoveDown();
	}

#endif

	//set camera rotation values based on mouse motion values
	m_camera.RotateX((short)(TheInput::Instance()->GetMouseMotion().y));
	m_camera.RotateY((short)(TheInput::Instance()->GetMouseMotion().x));

#endif
	//set camera's position and orientation
	m_camera.Update();


}
//------------------------------------------------------------------------------------------------------
//function that sets view matrix accordingly
//------------------------------------------------------------------------------------------------------
void MainCamera::Draw()
{

	Camera::SendToShader();
	
}