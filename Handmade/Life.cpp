#include "Life.h"
#include "ScreenManager.h"

Life::Life()
{
	glm::vec2 resolution = TheScreen::Instance()->GetScreenSize();

	m_transform.SetPosition(resolution.x - 100.0f, resolution.y - 20.0f, 0.0f);
	m_transform.SetScale(100.0f, 100.0f, 1.0f);

	m_sprite.Create("LIFE");
	m_sprite.LoadTexture("Assets/Sprite/Health_1_Light.png", "LIFE");
	m_sprite.SetSpriteType(Sprite::STATIC);
	m_sprite.SetTextureDimension(8, 1);
}

void Life::Update()
{
	m_sprite.SetTextureCell(0, 0);
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

void Life::OnCollision(GameObject* go)
{

}

Life::~Life()
{
	m_sprite.Destroy("LIFE");
	m_sprite.UnloadTexture("LIFE");
}