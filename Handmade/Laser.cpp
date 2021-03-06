#include "Laser.h"
#include "Utility.h"
#include "AudioManager.h"


Laser::Laser()
{

}

Laser::~Laser()
{

}

Laser::Laser(const glm::vec3& pos, const glm::vec3& dir)
{
	m_rb.SetPos(pos);
	m_transform.SetPosition(m_rb.GetPos());
	m_rb.SetMass(1.0f);

	m_followPos = 0;

	m_rb.SetVel(dir * 3.4f);

	static bool isLaserLoaded = false;

	if (!isLaserLoaded)
	{
		m_playerLaser.LoadModel("Assets/Models/Laser_Player.obj", "PLAYERMODEL");
		m_playerLaser.LoadTexture("Assets/Textures/Laser_Player_Diffuse.png", "PLAYERLASER");

		TheAudio::Instance()->LoadFromFile("Assets/Audio/Player_Laser.wav", AudioManager::SFX_AUDIO, "LASER");
		m_sfx.SetAudioData("LASER", AudioManager::SFX_AUDIO);
		isLaserLoaded = true;
	}
	else
	{
		m_playerLaser.SetBuffer("PLAYERMODEL");
		m_playerLaser.SetTexture("PLAYERLASER");
		m_sfx.SetAudioData("LASER", AudioManager::SFX_AUDIO);
	}

	m_sphereCollider.SetPos(m_rb.GetPos());
	m_sphereCollider.SetRadius(1.0f);
	m_sphereCollider.SetScale(1.0f);

	m_sfx.Volume() = 0.5f;

}


bool Laser::Create()
{
	return false;
}

void Laser::Update()
{
	m_rb.AddForce(0.0f, 0.0f, -8.0f);
	
	// If the projectile goes further than 100 units, it is killed off
	if (m_rb.GetPos().z <= -15.0f)
	{
		m_isAlive = false;
	}

	m_rb.Update();
	m_transform.SetPosition(m_rb.GetPos());

	// Move forward in z-axis with the addition of the vel
	//PlayerUpdate();

	m_sfx.Play();

	m_sphereCollider.SetPos(m_rb.GetPos());
	m_sphereCollider.Update();
}

void Laser::Draw()
{
	PlayerShotDraw();
}

void Laser::Destroy()
{
	m_playerLaser.UnloadModel("PLAYERMODEL");
	m_playerLaser.UnloadTexture("PLAYERLASER");
	TheAudio::Instance()->UnloadFromMemory(AudioManager::SFX_AUDIO,
		AudioManager::CUSTOM_AUDIO, "LASER");
}

void Laser::OnCollision(GameObject* go)
{
	Utility::Log("Colliding with " + go->GetTag());
}

void Laser::PlayerShotDraw()
{
	m_transform.SetRotation(0.0f, 90.0f, 0.0f);
	m_transform.SetScale(0.1f, 0.1f, 0.1f);

	GameObject::SetMatrix(m_transform.GetMatrix());
	// Required when loading costum objs
	GameObject::SendToShader(false, true);
	m_playerLaser.SetColor(1, 1, 1, 1);
	m_playerLaser.Draw();

#ifdef DEBUG
	m_sphereCollider.DebugDraw();
#endif
}

void Laser::EnemyShotDraw()
{
	GameObject::SetMatrix(m_transform.GetMatrix());
	// Required when loading costum objs
	GameObject::SendToShader(false, true);
	m_enemyLaser.SetColor(1, 1, 1, 1);
	m_enemyLaser.Draw();

	GameObject::SetMatrix(m_transform.GetMatrix());

	m_sphereCollider.DebugDraw();
}

void Laser::PlayerUpdate()
{
	m_followPos--;

	m_rb.AddForce(0.0f, 0.0f, m_followPos);
}

void Laser::EnemyUpdate()
{

}

const SphereCollider& Laser::GetSphereCollider() const
{
	return m_sphereCollider;
}