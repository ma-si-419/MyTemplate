#pragma once
#include "DxLib.h"
class Input;
class Player
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Player();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Player();
	/// <summary>
	/// ����������
	/// </summary>
	void Init();
	/// <summary>
	/// �X�V����
	/// </summary>
	void Update(Input input);
	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �v���C���[�̓����蔻��̍��W��Ԃ�
	/// </summary>
	/// <returns>�v���C���[�̌��݂̓����蔻��̍��W</returns>
	VECTOR GetColPos(){ return m_colPos; }

	/// <summary>
	/// �v���C���[�`��ʒu��Ԃ�
	/// </summary>
	/// <returns>�v���C���[�̕`����W</returns>
	VECTOR GetDrawPos() { return m_drawPos; }

	/// <summary>
	/// �v���C���[�̌����Ă���������擾����
	/// </summary>
	/// <returns></returns>
	VECTOR GetDir() { return m_dirVec; }

	/// <summary>
	/// ���ݗ������Ă��邩�ǂ����ݒ肷��
	/// </summary>
	/// <param name="fall">�������Ă��邩�ǂ���</param>
	void SetFall(bool fall) { m_isFall = fall; }
	
	void SetPos(VECTOR pos) { m_colPos = pos; }
private:
	//�\�����W
	VECTOR m_drawPos;

	//�������Ă������
	VECTOR m_dirVec;

	//�����蔻��̍��W
	VECTOR m_colPos;

	//�v���C���[�n���h��
	int m_handle;

	//��Ɍ�������
	float m_jumpPower;

	//�������Ă��邩�ǂ���
	bool m_isFall;
};

