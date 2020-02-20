#include "Player.h"
#include <iostream>
#include <math.h>
#include "Utility.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Transformation.h"
//#include "Matrix4x4.h"


Player::Player()
{
	m_pos = Vec3<float>(0.0f, 0.0f, 0.0f);
	m_vel = 0.1f;

	m_direction = Vec3<float>(0.0f, 0.0f, 0.0f);

	m_forward = Vec3<float>(0.0f, 0.0f, -1.0f);
	m_up = Vec3<float>(0.0f, 1.0f, 0.0f);
	m_right = Vec3<float>(1.0f, 0.0f, 0.0f);


	m_rotationVec = Vec3<float>(0.0f, 0.0f, 0.0f);
	m_angle = 0.0f;

	
	m_transform.SetIdentity();

	// Initialize?
	m_translateMat.SetIdentity();
	m_rotateMat.SetIdentity();
	m_scaleMat.SetIdentity();

	m_model.LoadModel("Assets/Models/Spaceship.obj", "SPACESHIP");
	m_model.LoadTexture("Assets/Textures/Spaceship_Diffuse.png", "SPACESHIP");
}

Player::Player(float x, float y, float z)
{
	m_pos = Vec3<float>(x, y, z);

	m_vel = 0.1f;

	m_direction = Vec3<float>(0.0f, 0.0f, 0.0f);

	m_forward = Vec3<float>(0.0f, 0.0f, -1.0f);
	m_up = Vec3<float>(0.0f, 1.0f, 0.0f);
	m_right = Vec3<float>(1.0f, 0.0f, 0.0f);


	m_rotationVec = Vec3<float>(0.0f, 0.0f, 0.0f);
	m_angle = 0.0f;


	m_transform.SetIdentity();

	// Initialize?
	m_translateMat.SetIdentity();
	m_rotateMat.SetIdentity();
	m_scaleMat.SetIdentity();

	m_model.LoadModel("Assets/Models/Spaceship.obj", "SPACESHIP");
	m_model.LoadTexture("Assets/Textures/Spaceship_Diffuse.png", "SPACESHIP");
}

bool Player::Create()
{
	return false;
}

void Player::Update()
{
	KeyState keyState = TheInput::Instance()->GetKeyStates();

	//m_right.x = cos(Utility::DegToRad(m_angle));
	//m_right.y = 0.0f;
	//m_right.z = sin(Utility::DegToRad(m_angle));

	//m_forward = Utility::CrossProduct(m_right, m_up);


	if (keyState[SDL_SCANCODE_UP])
	{
		//m_direction = m_forward;
		m_pos.z += 0.05f;
	}
	else if (keyState[SDL_SCANCODE_DOWN])
	{
		//m_direction = -m_forward;
		m_pos.z -= 0.05f;
	}
	else if (keyState[SDL_SCANCODE_LEFT])
	{
		//m_direction = -m_right;
		m_pos.x += 0.05f;
	}
	else if (keyState[SDL_SCANCODE_RIGHT])
	{
		//m_direction = m_right;
		m_pos.x -= 0.05f;
	}

	if (keyState[SDL_SCANCODE_J])
	{
		m_angle -= 5.0f;
	}
	else if (keyState[SDL_SCANCODE_I])
	{
		m_angle += 5.0f;
	}
	else if (keyState[SDL_SCANCODE_K])
	{
		m_angle -= 5.0f;
	}
	else if (keyState[SDL_SCANCODE_L])
	{
		m_angle += 5.0f;
	}

	m_pos += m_direction * m_vel;


	if (TheInput::Instance()->GetLeftButtonState() == InputManager::DOWN)
	{
		m_pos.y += 0.05f;
	}
	else if (TheInput::Instance()->GetRightButtonState() == InputManager::DOWN)
	{
		m_pos.y -= 0.05f;
	}

	glm::vec2 motion = TheInput::Instance()->GetMouseMotion();

	std::cout << "X motion is " << motion.x << std::endl;
	std::cout << "Y motion is " << motion.y << std::endl;

	//m_angle += 0.5f;
	//m_xRot = motion.x;
	//m_yRot = motion.y;
}


void Player::Draw()
{
	//GameObject::Translate();

	
	m_transform = Transformation::Translation(m_transform, m_pos);
	//GameObject::Rotate(m_angle, m_xRot, m_yRot, m_zRot);
	GameObject::SetMatrix(m_transform);
	m_transform.PrintMatrix();	// Testing transform


	glm::mat4 result;
	glm::mat4 trans = glm::translate(glm::mat4(), glm::vec3(0.5f + m_pos.x, 0.0f + m_pos.y, 0.0f + m_pos.z));
	glm::mat4 rot = glm::rotate(glm::mat4(), Utility::DegToRad(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(0.1, 0.1, 0.1));
	result = trans * rot * scale;
	GameObject::SetMatrix(result);
	// Required when loading costum objs
	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();


	//vTheDebug::Instance()->DrawSphere3D(0.3f, 100, 90, 100, 0.5f);

	//GameObject::SetIdentity();
	//GameObject::Translate(-0.5f + m_pos.x, 0.0f + m_pos.y, 0.0f + m_pos.z);
	////GameObject::Rotate(m_angle, m_xRot, m_yRot, m_zRot);
	//TheDebug::Instance()->DrawSphere3D(0.3f, 100, 90, 100, 0.5f);

	//GameObject::SetIdentity();
	//GameObject::Translate(0.0f + m_pos.x, 0.5f + m_pos.y, 0.0f + m_pos.z);
	//GameObject::Rotate(m_angle, 1, 0, 0);
	//GameObject::Rotate(m_angle, 0, 1, 0);
	//TheDebug::Instance()->DrawCube3D(0.5f, 1.0f, 0.5f, 100.0f, 100.0f, 100.0f, 0.5f);

	//GameObject::SetIdentity();
	//GameObject::Translate(m_pos.x, m_pos.y, m_pos.z);
	//TheDebug::Instance()->DrawVector3D(m_up.x * 4, m_up.y * 4, m_up.z * 4, 
	//	2.0f, 1.0f, 0.0f, 0.0f);
	//TheDebug::Instance()->DrawVector3D(m_right.x * 4, m_right.y * 4, m_right.z * 4,
	//	2.0f, 0.0f, 1.0f, 0.0f);
	//TheDebug::Instance()->DrawVector3D(m_forward.x * 4, m_forward.y * 4, m_forward.z * 4,
	//	2.0f, 0.0f, 0.0f, 1.0f);
}


void Player::Destroy()
{

}

