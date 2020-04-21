#include "Player.h"
#include <iostream>
#include <math.h>
#include "Utility.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Transformation.h"


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
	
	// These matrices (mine), are not being fully used
	// alternatively using the glm matrix
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
	m_pos = Vec3f(x, y, z);
	m_posGLM = glm::vec3(x, y, z);

	m_vel = 0.01f;
	m_velCap = 0.0f;

	// These vectors are currently disabled until 
	// the vector classes are reworked
	m_direction = Vec3f(0.0f, 0.0f, 0.0f);
	m_forward = Vec3f(0.0f, 0.0f, -1.0f);
	m_up = Vec3f(0.0f, 1.0f, 0.0f);
	m_right = Vec3f(1.0f, 0.0f, 0.0f);

	// Disabled until rework
	m_rotationVec = Vec3f(0.0f, 0.0f, 0.0f);
	m_angle = 0.0f;

	// Direction Vectors
	m_dirGLM = glm::vec3(0.0f);

	m_upGLM = glm::vec3(0.0f, 1.0f, 0.0f);
	m_forwardGLM = glm::vec3(0.0f, 0.0f, -1.0f);
	m_rightGLM = glm::vec3(1.0f, 0.0f, 0.0f);
	m_rotVecGLM = glm::vec3(0.0f);

	m_rb.SetPos(m_posGLM);
	m_rb.SetAcc(m_accGLM);
	m_rb.SetVel(m_velGLM);
	m_rb.SetForce(m_forceGLM);

	m_transform.SetIdentity();

	// Initialize?
	m_translateMat.SetIdentity();
	m_rotateMat.SetIdentity();
	m_scaleMat.SetIdentity();

	m_model.LoadModel("Assets/Models/Spaceship.obj", "SPACESHIP");
	m_model.LoadTexture("Assets/Textures/Spaceship_Diffuse.png", "SPACESHIP");

	m_collider.SetPos(m_posGLM);
	m_collider.SetDimension(1.0f, 1.0f, 1.0f);


	m_sphereCollider.SetRadius(1.0f);
	m_sphereCollider.SetScale(0.5f);

	for (size_t i = 0; i < 10; i++)
	{
		m_bullet[i] = new Laser();
	}
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
		m_rb.SetPos(0.0f, 0.0f, -0.05f);
		m_posGLM.z -= 0.05f;
		m_rb.AddForce(0.0f, 0.0f, -1.0f);
	}
	else if (keyState[SDL_SCANCODE_DOWN])
	{
		m_posGLM.z += 0.05f;
		m_rb.SetPos(0.0f, 0.0f, +0.05f);
		m_rb.AddForce(0.0f, 0.0f, 1.0f);
	}
	else if (keyState[SDL_SCANCODE_LEFT])
	{
		m_posGLM.x -= 0.05f;
		m_rb.SetPos(-0.05f, 0.0f, 0.0f);
	}
	else if (keyState[SDL_SCANCODE_RIGHT])
	{
		m_posGLM.x += 0.05f;
		m_rb.SetPos(+0.05f, 0.0f, 0.0f);
	}

	if (keyState[SDL_SCANCODE_SPACE])
	{
		// Shoot Projectile
		m_bullet[0]->IsActive() = true;
	}

	for (size_t i = 0; i < 10; i++)
	{
		m_bullet[i]->Update();
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

	//m_posGLM += m_dirGLM * m_vel;

	// Set vel cap
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

	Utility::Log(m_posGLM.x, m_posGLM.y, m_posGLM.z, "Player's Pos");

	//m_collider.GetPos(m_posGLM);
	//m_collider.Update();
	//Utility::Log(m_collider., "Player Collider Pos");

	m_sphereCollider.SetPos(m_posGLM);
	m_sphereCollider.Update();

	m_rb.Update();
}


void Player::Draw()
{
	//m_playerShot->Draw();

	m_transform = Transformation::Translation(m_transform, m_pos);
	//GameObject::Rotate(m_angle, m_xRot, m_yRot, m_zRot);
	GameObject::SetMatrix(m_transform);
	//m_transform.PrintMatrix();	// Testing transform


	glm::mat4 result;

	m_transform.ZeroTranslate(x, y, z);

	result = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f + m_posGLM.x, 0.0f + m_posGLM.y, 0.0f + m_posGLM.z));
	result = glm::rotate(result, Utility::DegToRad(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	result = glm::scale(result, glm::vec3(0.1, 0.1, 0.1));
	//result = trans * rot * scale;
	GameObject::SetMatrix(result);
	// Required when loading costum objs
	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();

	//result = trans * rot;
	GameObject::SetMatrix(result);

#ifdef DEBUG

	//m_collider.DebugDraw();
	m_sphereCollider.DebugDraw();

#endif

	// Drawing axis 
	GameObject::SetMatrix(result);
	TheDebug::Instance()->DrawVector3D(m_up.x * 4, m_up.y * 4, m_up.z * 4, 
		2.0f, 1.0f, 0.0f, 0.0f);
	TheDebug::Instance()->DrawVector3D(m_right.x * 4, m_right.y * 4, m_right.z * 4,
		2.0f, 0.0f, 1.0f, 0.0f);
	TheDebug::Instance()->DrawVector3D(-m_forward.x * 4, -m_forward.y * 4, -m_forward.z * 4,
		2.0f, 0.0f, 0.0f, 1.0f);
}


void Player::Destroy()
{
	for (size_t i = 0; i < 10; i++)
	{
		delete m_bullet[i];
	}
}

void Player::OnCollision(GameObject* go)
{
	Utility::Log("Colliding with " + go->GetTag());
}

//void Player::CheckCollision(const Enemy& enemy)
//{
//
//}

const AABB& Player::GetCollider() const
{
	return m_collider;
}

const SphereCollider& Player::GetSphereCollider() const
{
	return m_sphereCollider;
}