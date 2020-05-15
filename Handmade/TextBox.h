#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "GameObject.h"
#include "Transform.h"
#include "Text.h"
#include <string>


class TextBox : public GameObject
{
public:
	TextBox(float x, float y, float z, float size, const std::string& ID);
	virtual ~TextBox() {}

	virtual bool Create();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void SetText(const std::string& text);


private:
	Text m_text;


};

#endif