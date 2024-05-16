#pragma once
#include "DxLib.h"
class Sphere
{
public:
	Sphere();

	void Update();
	void Draw();

	void SetPos(VECTOR pos) { m_pos = pos; }
	
	void SetCameraAngle(float angle) { m_cameraAngle = angle; }

	VECTOR GetPos() { return m_pos; }
private:
	VECTOR m_pos;

	float m_cameraAngle;
};

