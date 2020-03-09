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
	m_pos = Vec3<float>(x, y, z);
	m_posGLM = glm::vec3(x, y, z);

	m_vel = 0.01f;
	m_velCap = 0.0f;

	// These vectors are currently disabled until 
	// the vector classes are reworked
	m_direction = Vec3<float>(0.0f, 0.0f, 0.0f);
	m_forward = Vec3<float>(0.0f, 0.0f, -1.0f);
	m_up = Vec3<float>(0.0f, 1.0f, 0.0f);
	m_right = Vec3<float>(1.0f, 0.0f, 0.0f);

	// Disabled until rework
	m_rotationVec = Vec3<float>(0.0f, 0.0f, 0.0f);
	m_angle = 0.0f;


	m_dirGLM = glm::vec3(0.0f);

	m_upGLM = glm::vec3(0.0f, 1.0f, 0.0f);
	m_forwardGLM = glm::vec3(0.0f, 0.0f, -1.0f);
	m_rightGLM = glm::vec3(1.0f, 0.0f, 0.0f);
	m_rotVecGLM = glm::vec3(0.0f);


	m_transform.SetIdentity();

	// Initialize?
	m_translateMat.SetIdentity();
	m_rotateMat.SetIdentity();
	m_scaleMat.SetIdentity();

	m_model.LoadModel("Assets/Models/Spaceship.obj", "SPACESHIP");
	m_model.LoadTexture("Assets/Textures/Spaceship_Diffuse.png", "SPACESHIP");

	m_collider.SetPos(m_posGLM);
	m_collider.SetDimension(2.0f, 2.0f, 2.0f);

	m_sphereCollider.SetRadius(1.0f);
	m_sphereCollider.SetScale(0.5f);

	//m_playerShot->
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
		m_dirGLM = m_forwardGLM;
		//m_pos.z -= 0.05f;
		//m_posGLM.z -= 0.05f;
	}
	else if (keyState[SDL_SCANCODE_DOWN])
	{
		m_dirGLM = -m_forwardGLM;
		//m_pos.z += 0.05f;
		//m_posGLM.z += 0.05f;
	}
	else if (keyState[SDL_SCANCODE_LEFT])
	{
		//m_direction = -m_right;
		m_pos.x -= 0.05f;
		m_posGLM.x -= 0.05f;
	}
	else if (keyState[SDL_SCANCODE_RIGHT])
	{
		//m_direction = m_right;
		m_pos.x += 0.05f;
		m_posGLM.x += 0.05f;
	}

	if (keyState[SDL_SCANCODE_SPACE])
	{
		// Shoot Projectile
		m_playerShot->IsActive() = true;
		m_playerShot->Create();
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

	m_posGLM += m_dirGLM * m_vel;

	// Set vel cap



	if (TheInput::Instance()->GetLeftButtonState() == InputManager::DOWN)
	{
		m_pos.y += 0.05f;
	}
	else if (TheInput::Instance()->GetRightButtonState() == InputManager::DOWN)
	{
		m_pos.y -= 0.05f;
	}

	// For debug use to get mouse motion parameters
	//glm::vec2 motion = TheInput::Instance()->GetMouseMotion();

	//std::cout << "X motion is " << motion.x << std::endl;
	//std::cout << "Y motion is " << motion.y << std::endl;


	Utility::Log(m_posGLM.x, m_posGLM.y, m_posGLM.z, "Player's Pos");

	//m_collider.SetPos(m_posGLM);
	m_collider.Update();
	Utility::Log(m_posGLM.x, m_posGLM.y, m_posGLM.z, "Player Collider Pos");

	m_sphereCollider.SetPos(m_posGLM);
	m_sphereCollider.Update();

	m_playerShot->Update();
}


void Player::Draw()
{
	m_playerShot->Draw();

	m_transform = Transformation::Translation(m_transform, m_pos);
	//GameObject::Rotate(m_angle, m_xRot, m_yRot, m_zRot);
	GameObject::SetMatrix(m_transform);
	//m_transform.PrintMatrix();	// Testing transform


	glm::mat4 result;
	glm::mat4 trans = glm::translate(glm::mat4(), glm::vec3(0.5f + m_posGLM.x, 0.0f + m_posGLM.y, 0.0f + m_posGLM.z));
	glm::mat4 rot = glm::rotate(glm::mat4(), Utility::DegToRad(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(0.1, 0.1, 0.1));
	result = trans * rot * scale;
	GameObject::SetMatrix(result);
	// Required when loading costum objs
	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();

	result = trans * rot;
	GameObject::SetMatrix(result);

#ifdef DEBUG

	m_collider.DebugDraw();
	//m_sphereCollider.DebugDraw();

#endif

	// Drawing axis 
	GameObject::Translate(m_posGLM.x, m_posGLM.y, m_posGLM.z);
	TheDebug::Instance()->DrawVector3D(m_up.x * 4, m_up.y * 4, m_up.z * 4, 
		2.0f, 1.0f, 0.0f, 0.0f);
	TheDebug::Instance()->DrawVector3D(m_right.x * 4, m_right.y * 4, m_right.z * 4,
		2.0f, 0.0f, 1.0f, 0.0f);
	TheDebug::Instance()->DrawVector3D(-m_forward.x * 4, -m_forward.y * 4, -m_forward.z * 4,
		2.0f, 0.0f, 0.0f, 1.0f);
}


void Player::Destroy()
{
	delete m_playerShot;
}

void Player::OnCollision(GameObject* go)
{
	Utility::Log("Colliding with " + go->GetTag());
}

const AABB& Player::GetCollider() const
{
	return m_collider;
}

const SphereCollider& Player::GetSphereCollider() const
{
	return m_sphereCollider;
}