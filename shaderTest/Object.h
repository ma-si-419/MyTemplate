#pragma once
#include "DxLib.h"

class Object
{
public:
	Object();
	~Object();

	void Init();
	void Update();
	void Draw();

	int GetModel() { return m_handle; }
private:
	VECTOR m_pos;

	int m_handle;
};

