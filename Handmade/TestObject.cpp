#include "TestObject.h"

TestObject::TestObject()
{
	m_pos = Vec3<float>(0.0f, 0.0f, 0.0f);
}


TestObject::TestObject(float x, float y, float z)
{

}

bool TestObject::Create()
{
	return false;
}

void TestObject::Update()
{
}

void TestObject::Draw()
{
}

void TestObject::Destroy()
{
}

void TestObject::OnCollision(GameObject* go)
{

}
