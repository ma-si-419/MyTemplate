#include "Sphere.h"

namespace
{
	constexpr float kSpeed = 4.0f;
}
Sphere::Sphere()
{
	m_pos = VGet(200, 0, 0);
}

void Sphere::Update()
{
	VECTOR move = VGet(0,0,0);

	if(CheckHitKey(KEY_INPUT_LEFT))
	{
		move.x -= kSpeed;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		move.x += kSpeed;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		move.z += kSpeed;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		move.z -= kSpeed;
	}

	MATRIX mat = MGetRotY(-m_cameraAngle - DX_PI_F / 2);

	move = VTransform(move, mat);

	m_pos = VAdd(m_pos, move);

}

void Sphere::Draw()
{
	DrawSphere3D(m_pos,10,100,GetColor(255, 255, 0), GetColor(255, 255, 255), true);
}
