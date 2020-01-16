#include "Player.h"
#include <iostream>


Player::Player()
{
	m_xPos = 0.0f;
	m_yPos = 0.0f;
	m_zPos = 0.0f;

	m_xRot = 0.0f;
	m_yRot = 0.0f;
	m_zRot = 0.0f;

	m_angle = 0.0f;
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
		m_zPos += 0.05f;
	}
	else if (keyState[SDL_SCANCODE_DOWN])
	{
		m_zPos -= 0.05f;
	}
	else if (keyState[SDL_SCANCODE_LEFT])
	{
		m_xPos += 0.05f;
	}
	else if (keyState[SDL_SCANCODE_RIGHT])
	{
		m_xPos -= 0.05f;
	}

	if (TheInput::Instance()->GetLeftButtonState() == InputManager::DOWN)
	{
		m_yPos += 0.05f;
	}
	else if (TheInput::Instance()->GetRightButtonState() == InputManager::DOWN)
	{
		m_yPos -= 0.05f;
	}

	glm::vec2 motion = TheInput::Instance()->GetMouseMotion();

	std::cout << "X motion is " << motion.x << std::endl;
	std::cout << "Y motion is " << motion.y << std::endl;

	m_angle += 0.5f;
	m_xRot = motion.x;
	m_yRot = motion.y;
}

void Player::Draw()
{
	//GameObject::Translate(m_xPos, m_yPos, m_zPos);

	GameObject::SetIdentity();
	//GameObject::Rotate(m_angle, m_xRot, m_yRot, m_zRot);
	GameObject::Translate(0.5f + m_xPos, 0.0f + m_yPos, 0.0f + m_zPos);
	TheDebug::Instance()->DrawSphere3D(0.3f, 100, 90, 100, 0.5f);

	GameObject::SetIdentity();
	GameObject::Translate(-0.5f + m_xPos, 0.0f + m_yPos, 0.0f + m_zPos);
	//GameObject::Rotate(m_angle, m_xRot, m_yRot, m_zRot);
	TheDebug::Instance()->DrawSphere3D(0.3f, 100, 90, 100, 0.5f);

	GameObject::SetIdentity();
	GameObject::Translate(0.0f + m_xPos, 0.5f + m_yPos, 0.0f + m_zPos);
	//GameObject::Rotate(m_angle, m_xRot, m_yRot, m_zRot);
	TheDebug::Instance()->DrawCube3D(0.5f, 1.0f, 0.5f, 100.0f, 100.0f, 100.0f, 0.5f);

	
}

void Player::Destroy()
{

}
