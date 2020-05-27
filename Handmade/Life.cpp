#include "Life.h"
#include "ScreenManager.h"

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
	CheckLife();

	enum HEALTH { GREAT, GOOD, NOTGOOD, HALF, 
		HALFBAD, BAD, REALBAD, DEAD };

	switch (GREAT)
	{
	case GREAT:
		if (CheckLife() == 100)
		{
			m_sprite.SetTextureCell(0, 0);
		}
	case GOOD:
		if (CheckLife() > 75 && CheckLife() < 100)
		{
			m_sprite.SetTextureCell(1, 0);
		}
	case NOTGOOD:
		if (CheckLife() <= 75 && CheckLife() < 50)
		{
			m_sprite.SetTextureCell(2, 0);
		}
	case HALF:
		if (CheckLife() == 50)
		{
			m_sprite.SetTextureCell(3, 0);
		}
	case HALFBAD:
		if (CheckLife() < 50 && CheckLife() > 35)
		{
			m_sprite.SetTextureCell(4, 0);
		}
	case BAD:
		if (CheckLife() < 35 && CheckLife() > 25)
		{
			m_sprite.SetTextureCell(5, 0);
		}
	case REALBAD:
		if (CheckLife() > 10 && CheckLife() < 25)
		{
			m_sprite.SetTextureCell(6, 0);
		}
	case DEAD:
		if (CheckLife() == 0)
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