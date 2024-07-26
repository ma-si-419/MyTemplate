#pragma once
#include "DxLib.h"
class Stage
{
public:
	Stage();
	~Stage();

	void Init();
	void Update();
	void Draw();

	int GetHandle() { return m_handle; }

private:
	int m_handle;
	VECTOR m_pos;
};

