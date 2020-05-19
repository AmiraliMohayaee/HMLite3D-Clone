#include "Player.h"
#include <iostream>
#include <math.h>
#include "Utility.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Transform.h"


Player::Player()
{

}

Player::Player(float x, float y, float z)
{
	m_rb.SetPos(x, y, z);
	m_transform.SetPosition(m_rb.GetPos());

	m_vel = 0.01f;
	m_velCap = 0.0f;

	m_angle = 0.0f;

	// Direction Vectors
	m_dirGLM = glm::vec3(0.0f);

	m_upGLM = glm::vec3(0.0f, 1.0f, 0.0f);
	m_forwardGLM = glm::vec3(0.0f, 0.0f, -1.0f);
	m_rightGLM = glm::vec3(1.0f, 0.0f, 0.0f);
	m_rotVecGLM = glm::vec3(0.0f);

	m_rb.SetPos(m_transform.GetPos());
	m_rb.SetAcc(m_accGLM);
	m_rb.SetVel(m_velGLM);
	m_rb.SetMass(1.0f);
	m_rb.SetForce(m_forceGLM);

	//m_transform.SetIdentity();

 	m_model.LoadModel("Assets/Models/Spaceship.obj", "SPACESHIP");
	m_model.LoadTexture("Assets/Textures/Spaceship_Diffuse.png", "SPACESHIP");

	m_sphereCollider.SetRadius(0.5f);
	m_sphereCollider.SetScale(0.5f);
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


	// Set vel cap
	//if (m_rb.GetForce().x >= 1.0f || m_rb.GetForce().z >= 1.0f)
	//{
	//	m_rb.SetForce(0.0f, 0.0f, 0.0f);
	//}
	
	Utility::Log(m_rb.GetAcc().x, m_rb.GetAcc().y, 
		m_rb.GetAcc().z, "RigidBody Accelleration:");
	Utility::Log(m_rb.GetPos().x, m_rb.GetPos().y,
		m_rb.GetPos().z, "RigidBody Position:");
	Utility::Log(m_rb.GetVel().x, m_rb.GetVel().y,
		m_rb.GetVel().z, "RigidBody Velocity:");


	//if (TheInput::Instance()->GetLeftButtonState() == InputManager::DOWN)
	//{
	//	m_pos.y += 0.05f;
	//}
	//else if (TheInput::Instance()->GetRightButtonState() == InputManager::DOWN)
	//{
	//	m_pos.y -= 0.05f;
	//}

	// To do: Add mouse input 

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
}

void Player::OnCollision(GameObject* go)
{
	Utility::Log("Colliding with " + go->GetTag());
}

const SphereCollider& Player::GetSphereCollider() const
{
	return m_sphereCollider;
}