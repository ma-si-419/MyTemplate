#pragma once
#include "DxLib.h"

class Input;
class SpotLight
{
public:
	SpotLight();
	~SpotLight();

	void Update(Input input);

	void Draw();

	VECTOR GetPos() { return m_pos; }

	VECTOR GetLightColor() { return m_color; }

	VECTOR GetDir() { return m_dir; }

	float GetPower() { return m_power; }

	float GetViewAngle() { return m_viewAngle; }

private:

	VECTOR m_pos;

	VECTOR m_dir;

	VECTOR m_color;

	float m_power;

	float m_viewAngle;

	float dirX;
	float dirY;
	float dirZ;

	VECTOR m_targetPos;



};