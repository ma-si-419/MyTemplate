#pragma once
#include "DxLib.h"
class Input;
class Camera
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Camera();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Camera();
	/// <summary>
	/// �X�V����
	/// </summary>
	void Update(Input input,VECTOR target);
	
	VECTOR GetPos() { return m_pos; }

private:
	//�\�����W
	VECTOR m_pos;
};

