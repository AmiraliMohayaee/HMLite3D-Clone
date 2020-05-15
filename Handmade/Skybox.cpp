#include "Skybox.h"
#include <gtc/matrix_transform.hpp>
#include "Utility.h"
#include "AudioManager.h"
#include "Game.h"


Skybox::Skybox()
{
}

Skybox::Skybox(float x, float y, float z)
{
	m_rb.SetPos(x, y, z);
	m_transform.SetPosition(m_rb.GetPos());

	m_model.LoadModel("Assets/Models/Skybox.obj", "SKYBOX");
	m_model.LoadTexture("Assets/Textures/Skybox_Color.png", "SKYBOX");

	// Setting up the level music
	TheAudio::Instance()->LoadFromFile("Assets/Audio/DualPlanetaryReverse.ogg", AudioManager::MUSIC_AUDIO, "SKYBOXAUD");
	m_music.SetAudioData("SKYBOXAUD", AudioManager::MUSIC_AUDIO);
	m_music.Volume() = 0.4f;

	//m_music.Play();
	//m_music.SetLoopCount(Audio::ENDLESS_LOOP);
}

bool Skybox::Create()
{
	return false;
}

void Skybox::Update()
{
	m_rotAngle += TheGame::Instance()->GetElapsedTime() / 1000.0f;
}

void Skybox::Draw()
{
	GameObject::SetMatrix(m_transform.GetMatrix());

	// Required when loading costum objs
	GameObject::SendToShader(false, true);
	m_model.SetColor(1, 1, 1, 1);
	m_model.Draw();

	GameObject::SetMatrix(m_transform.GetMatrix());
}

void Skybox::Destroy()
{
	m_model.UnloadModel("SKYBOX");
	m_model.UnloadTexture("SKYBOX");
	TheAudio::Instance()->UnloadFromMemory(AudioManager::MUSIC_AUDIO,
		AudioManager::CUSTOM_AUDIO, "SKYBOXAUD");
	m_music.Stop();
}

void Skybox::OnCollision(GameObject* go)
{

}
