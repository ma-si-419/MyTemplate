#include "Object.h"

Object::Object() :
	m_pos(VGet(0,0,10)),
	m_handle(-1)
{
	m_handle = MV1LoadModel("data/model/Stage.mv1");

	MV1SetPosition(m_handle,m_pos);

	MV1SetScale(m_handle, VGet(0.1, 0.1, 0.1));
}

Object::~Object()
{
}

void Object::Init()
{
}

void Object::Update()
{
}

void Object::Draw()
{
	MV1DrawModel(m_handle);
}
