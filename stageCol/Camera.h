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
	void Update(Input input);
	/// <summary>
	/// �J�����̃^�[�Q�b�g���W��ݒ肷��
	/// </summary>
	/// <param name="pos">�^�[�Q�b�g���W</param>
	void SetTargetPos(VECTOR pos) { m_targetPos = pos; m_targetPos.y += 300; }

	/// <summary>
	/// �J�����̍��W���擾����
	/// </summary>
	/// <returns>�J�����̍��W</returns>
	VECTOR GetPos() { return m_pos; }

private:
	//�\�����W
	VECTOR m_pos;

	//�^�[�Q�b�g���W
	VECTOR m_targetPos;
};

