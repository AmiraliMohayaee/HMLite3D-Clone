#include "TestObject.h"
#include "DebugManager.h"


TestObject::TestObject()
{
	
}


TestObject::TestObject(float x, float y, float z)
{
	m_rb.SetAcc(0.0f, 0.0f, 0.0f);
	m_rb.SetPos(x, y, z);
	m_rb.SetForce(0.0f, 0.0f, 0.0f);
	m_rb.SetMass(0.0f);
	m_rb.SetVel(0.0f, 0.0f, 0.0f);
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
