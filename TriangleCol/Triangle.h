#pragma once
#include "DxLib.h"
class Triangle
{
public:
	Triangle();
	void Update(VECTOR targetPos);
	void Draw();

	VECTOR SetTargetPos(VECTOR pos);

private:
	VECTOR m_pos1;
	VECTOR m_pos2;
	VECTOR m_pos3;

	VECTOR m_targetPos;
};

