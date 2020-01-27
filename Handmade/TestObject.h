#pragma once

#include "Vec3.h"


class TestObject
{
public:
	TestObject();

	Vec3<float> GetVec();


private:
	Vec3<float> m_pos;
};

