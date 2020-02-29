#include "TestObject.h"
#include "DebugManager.h"


TestObject::TestObject()
{
	m_pos = Vec3<float>(0.0f, 0.0f, 0.0f);
}


TestObject::TestObject(float x, float y, float z)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.z = z;
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
	TheDebug::Instance()->DrawCube3D(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
}

void TestObject::Destroy()
{
}

void TestObject::OnCollision(GameObject* go)
{

}
