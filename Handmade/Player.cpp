#include "Player.h"
#include <iostream>


Player::Player()
{
	m_pos = glm::vec3(0.0f);

	m_xRot = 0.0f;
	m_yRot = 0.0f;
	m_zRot = 0.0f;

	m_XAngle = 0.0f;
	m_YAngle = 0.0f;
	m_ZAngle = 0.0f;
}

bool Player::Create()
{
	return false;
}

void Player::Update()
{
	KeyState keyState = TheInput::Instance()->GetKeyStates();

	if (keyState[SDL_SCANCODE_UP])
	{
		m_pos.z += 0.05f;
	}
	else if (keyState[SDL_SCANCODE_DOWN])
	{
		m_pos.z -= 0.05f;
	}
	else if (keyState[SDL_SCANCODE_LEFT])
	{
		m_pos.x += 0.05f;
	}
	else if (keyState[SDL_SCANCODE_RIGHT])
	{
		m_pos.x -= 0.05f;
	}

	if (keyState[SDL_SCANCODE_J])
	{
		m_XAngle -= 5.0f;
	}
	else if (keyState[SDL_SCANCODE_I])
	{
		m_YAngle += 5.0f;
	}
	else if (keyState[SDL_SCANCODE_K])
	{
		m_YAngle -= 5.0f;
	}
	else if (keyState[SDL_SCANCODE_L])
	{
		m_XAngle += 5.0f;
	}


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
	//GameObject::Translate(m_xPos, m_yPos, m_zPos);

	GameObject::SetIdentity();
	//GameObject::Rotate(m_angle, m_xRot, m_yRot, m_zRot);
	GameObject::Translate(0.5f + m_pos.x, 0.0f + m_pos.y, 0.0f + m_pos.z);
	TheDebug::Instance()->DrawSphere3D(0.3f, 100, 90, 100, 0.5f);

	GameObject::SetIdentity();
	GameObject::Translate(-0.5f + m_pos.x, 0.0f + m_pos.y, 0.0f + m_pos.z);
	//GameObject::Rotate(m_angle, m_xRot, m_yRot, m_zRot);
	TheDebug::Instance()->DrawSphere3D(0.3f, 100, 90, 100, 0.5f);

	GameObject::SetIdentity();
	GameObject::Translate(0.0f + m_pos.x, 0.5f + m_pos.y, 0.0f + m_pos.z);
	GameObject::Rotate(m_XAngle, 1, 0, 0);
	GameObject::Rotate(m_YAngle, 0, 1, 0);
	TheDebug::Instance()->DrawCube3D(0.5f, 1.0f, 0.5f, 100.0f, 100.0f, 100.0f, 0.5f);
}

void Player::Destroy()
{

}

