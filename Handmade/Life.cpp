#include "Life.h"
#include "ScreenManager.h"
#include "Utility.h"

Life::Life()
{
	m_healthVal = 0;
	glm::vec2 resolution = TheScreen::Instance()->GetScreenSize();

	m_transform.SetPosition(resolution.x - 110.0f, resolution.y - 100.0f, 0.0f);
	m_transform.SetScale(100.0f, 100.0f, 1.0f);

	m_sprite.Create("LIFE");
	m_sprite.LoadTexture("Assets/Sprites/Health_1_Light.png", "LIFE");
	m_sprite.SetSpriteType(Sprite::STATIC);
	m_sprite.SetTextureDimension(8, 1);
}

void Life::Update()
{
	//CheckLife();


	enum HEALTH {
		GREAT, GOOD, NOTGOOD, HALF,
		HALFBAD, BAD, REALBAD, DEAD
	};

	// Needs some further bug fixing
	switch (GREAT)
	{
	case GREAT:
		if (m_healthVal == 100)
		{
			m_sprite.SetTextureCell(0, 0);
		}
	case GOOD:
		if (m_healthVal > 75 && m_healthVal < 100)
		{
			m_sprite.SetTextureCell(1, 0);
		}
	case NOTGOOD:
		if (m_healthVal <= 75 && m_healthVal < 50)
		{
			m_sprite.SetTextureCell(2, 0);
		}
	case HALF:
		if (m_healthVal == 50)
		{
			m_sprite.SetTextureCell(3, 0);
		}
	case HALFBAD:
		if (m_healthVal < 50 && m_healthVal > 35)
		{
			m_sprite.SetTextureCell(4, 0);
			Utility::Log("Player at half life");
		}
	case BAD:
		if (m_healthVal < 35 && m_healthVal > 25)
		{
			m_sprite.SetTextureCell(5, 0);
		}
	case REALBAD:
		if (m_healthVal > 10 && m_healthVal < 25)
		{
			m_sprite.SetTextureCell(6, 0);
		}
	case DEAD:
		if (m_healthVal == 0)
		{
			m_sprite.SetTextureCell(7, 0);
		}
	}


	m_sprite.Update();
}

void Life::Draw()
{
	GameObject::SetMatrix(m_transform.GetMatrix());
	GameObject::SendToShader(false, true);

	m_sprite.Draw();
}

void Life::Destroy()
{

}

Life::~Life()
{
	m_sprite.Destroy("LIFE");
	m_sprite.UnloadTexture("LIFE");
}

void Life::SetHealthVal(const int val)
{
	m_healthVal = val;
}

const int Life::CheckLife()
{
	return m_healthVal;
}