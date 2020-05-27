#include "Explosion.h"


Explosion::Explosion(float x, float y, float z, const std::string& ID)
{

	static bool isTextureLoaded = false;

	if (!isTextureLoaded)
	{
		m_animation.LoadTexture("Assets/Sprites/Explosion.png", "EXPLOSION");
		TheAudio::Instance()->LoadFromFile("Assets/Audio/Explosion.wav", 
			AudioManager::SFX_AUDIO, "EXPLOSION");
		m_sfx.SetAudioData("EXPLOSION", AudioManager::SFX_AUDIO);
		isTextureLoaded = true;
	}
	else
	{
		m_animation.SetTexture("EXPLOSION");
	}

	m_animation.Create(ID);
	m_animation.IsAnimationLooping() = false;
	m_animation.SetAnimationVelocity(50.0f);
	m_animation.SetTextureDimension(8, 6);

	m_sfx.SetAudioData("EXPLOSION", AudioManager::SFX_AUDIO);
	m_sfx.Volume() = 0.5f;
	m_sfx.Play();

	m_transform.SetPosition(x, y, z);
	m_transform.SetScale(100, 100, 0);
}

Explosion::~Explosion()
{
}

void Explosion::Update()
{
	m_animation.Update();
	m_isAlive = !(m_animation.IsAnimationDead());

}

void Explosion::Draw()
{
	GameObject::SetMatrix(m_transform.GetMatrix());
	GameObject::SendToShader(false, true);

	m_animation.Draw();
}
