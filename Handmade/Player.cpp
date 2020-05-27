#include "Player.h"
#include <iostream>
#include <math.h>
#include "Utility.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Transform.h"
#include "DebugManager.h"
#include "InputManager.h"


Player::Player()
{

}

Player::Player(float x, float y, float z)
{
	m_health = 100;

	m_rb.SetPos(x, y, z);
	m_transform.SetPosition(m_rb.GetPos());


	// Direction Vectors
	m_upGLM = glm::vec3(0.0f, 1.0f, 0.0f);
	m_forwardGLM = glm::vec3(0.0f, 0.0f, -1.0f);
	m_rightGLM = glm::vec3(1.0f, 0.0f, 0.0f);


	m_rb.SetMass(0.1f);

	//m_transform.SetIdentity();

 	m_model.LoadModel("Assets/Models/Spaceship.obj", "SPACESHIP");
	m_model.LoadTexture("Assets/Textures/Spaceship_Diffuse.png", "SPACESHIP");

	m_sphereCollider.SetRadius(0.5f);
	m_sphereCollider.SetScale(0.5f);
}

void Player::SetLife(unsigned int life)
{
	life = m_health;
}

const int Player::GetLife()
{
	return m_health;
}

void Player::LifeLoss(int lifeLoss)
{
	lifeLoss -= m_health;
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
		m_rb.AddForce(0.0f, 0.0f, -2.0f);
	}
	else if (keyState[SDL_SCANCODE_DOWN])
	{
		m_rb.AddForce(0.0f, 0.0f, 2.0f);
	}
	else if (keyState[SDL_SCANCODE_LEFT])
	{
		m_rb.AddForce(-2.0f, 0.0f, 0.0f);
	}
	else if (keyState[SDL_SCANCODE_RIGHT])
	{
		m_rb.AddForce(2.0f, 0.0f, 0.0f);
	}
	else
	{
		// Resetting any matrix or rigidbody change
	}

	if (keyState[SDL_SCANCODE_SPACE])
	{
		// Shoot Projectile
 		if(m_bullet == nullptr)
		{
			m_bullet = new Laser(m_transform.GetPos(), m_forwardGLM);
		}
	}

	if (keyState[SDL_SCANCODE_LSHIFT])
	{
		m_rb.SetForce(0.0f, 0.0f, 0.0f);
		m_rb.SetVel(0.0f, 0.0f, 0.0f);
	}

	if (m_bullet != nullptr)
	{
		m_bullet->Update();
		
		if (m_bullet->IsAlive() != true)
		{
			delete m_bullet;
			m_bullet = nullptr;
		}
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

	
	Utility::Log(m_rb.GetAcc().x, m_rb.GetAcc().y, 
		m_rb.GetAcc().z, "RigidBody Accelleration:");
	Utility::Log(m_rb.GetPos().x, m_rb.GetPos().y,
		m_rb.GetPos().z, "RigidBody Position:");
	Utility::Log(m_rb.GetVel().x, m_rb.GetVel().y,
		m_rb.GetVel().z, "RigidBody Velocity:");


	// To do: Add mouse input for later
	//if (TheInput::Instance()->GetLeftButtonState() == InputManager::DOWN)
	//{
	//	m_pos.y += 0.05f;
	//}
	//else if (TheInput::Instance()->GetRightButtonState() == InputManager::DOWN)
	//{
	//	m_pos.y -= 0.05f;
	//}

	// Position Capping by preventing player from moving
	// passed a certain bounds, but still allowing for it
	// to retain force to move around. It's best to limit instead
	// of just grinding the spaceship to a halt
	if (m_rb.GetPos().x < -5.0f || m_rb.GetPos().x > 5.0f
		|| m_rb.GetPos().z < -5.0f || m_rb.GetPos().z > 0.5f)
	{
		m_rb.SetVel(0.0f, 0.0f, 0.0f);
	}


	Utility::Log(m_rb.GetPos().x, m_rb.GetPos().y, m_rb.GetPos().z,
		"Player's Pos");

	m_rb.Update();
	m_transform.SetPosition(m_rb.GetPos());

	m_sphereCollider.SetPos(m_rb.GetPos());
	m_sphereCollider.Update();

}


void Player::Draw()
{
	if (m_bullet != nullptr)
	{
		m_bullet->PlayerShotDraw();
	}

	if (m_explosion != nullptr)
	{
		m_explosion->Draw();
	}

	m_transform.SetRotation(0.0f, 180.0f, 0.0f);
	m_transform.SetScale(0.1f, 0.1f, 0.1f);
	GameObject::SetMatrix(m_transform.GetMatrix());

	// Required when loading costum objs
	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();

	GameObject::SetMatrix(m_transform.GetMatrix());

#ifdef DEBUG

	m_transform.SetScale(1, 1, 1);
	GameObject::SetMatrix(m_transform.GetMatrix());
	GameObject::SendToShader(false, true);
	m_sphereCollider.DebugDraw();

	// Drawing axis 
	GameObject::SetMatrix(m_transform.GetMatrix());
	TheDebug::Instance()->DrawVector3D(m_upGLM.x * 5, m_upGLM.y * 5, m_upGLM.z * 5, 
		2.0f, 1.0f, 0.0f, 0.0f);
	TheDebug::Instance()->DrawVector3D(m_rightGLM.x * 5, m_rightGLM.y * 5, m_rightGLM.z * 5,
		2.0f, 0.0f, 1.0f, 0.0f);
	TheDebug::Instance()->DrawVector3D(-m_forwardGLM.x * 5, -m_forwardGLM.y * 5, -m_forwardGLM.z * 5,
		2.0f, 0.0f, 0.0f, 1.0f);

#endif

}

void Player::Destroy()
{
	m_model.UnloadModel("PLAYER");
	m_model.UnloadTexture("PLAYER");
	delete m_bullet;
	delete m_explosion;
	delete m_life;
}

void Player::OnCollision(GameObject* go)
{
	Utility::Log("Colliding with " + go->GetTag());

	//if (m_explosion == nullptr)
	//{
	//	m_explosion = new Explosion(m_transform.GetPos().x, m_transform.GetPos().y,
	//		m_transform.GetPos().z, "EXPLOSION");
	//}
}

const SphereCollider& Player::GetSphereCollider() const
{
	return m_sphereCollider;
}