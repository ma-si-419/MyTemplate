#include "Sphere.h"

Sphere::Sphere()
{
	m_pos = VGet(0, 0, 0);
}

void Sphere::Update()
{
}

void Sphere::Draw()
{
	DrawSphere3D(m_pos,10,100,GetColor(255,0,255),GetColor(255,255,0),true);
}
