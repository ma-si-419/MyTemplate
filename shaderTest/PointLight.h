#pragma once
#include "DxLib.h"

class Input;
class PointLight
{
public:
	PointLight();
	~PointLight();

	void Update(Input input);

	void Draw();

	VECTOR GetPos() { return m_pos; }

	VECTOR GetLightColor() { return m_color; }

	float GetPower() { return m_power; }
private:

	VECTOR m_pos;

	VECTOR m_color;

	float m_power;

};

