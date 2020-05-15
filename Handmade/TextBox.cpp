#include "TextBox.h"


TextBox::TextBox(float x, float y, float z, float size, const std::string& ID)
{
	static bool isTextLoaded = false;

	if (!isTextLoaded)
	{
		m_text.LoadTexture("Assets/Font/Space Age.png", "FONT");
		isTextLoaded = true;
	}
	else
	{
		m_text.SetTexture("FONT");
	}

	m_text.Create(ID);

	m_transform.SetPosition(x, y, z);
	m_transform.SetScale(size, size, size);
}

bool TextBox::Create()
{
	return false;
}

void TextBox::Update()
{
	
}

void TextBox::Draw()
{
	GameObject::SetMatrix(m_transform.GetMatrix());
	GameObject::SendToShader(false, true);

	m_text.Draw();
}

void TextBox::Destroy()
{
}

void TextBox::SetText(const std::string& text)
{
	m_text.SetText(text);
}
