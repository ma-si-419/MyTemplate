#pragma once
#include<memory>
#include "Input.h"
class SceneBase;
class SceneManager
{
public:
	//�R���X�g���N�^
	SceneManager();
	//�f�X�g���N�^
	~SceneManager();

	//�X�V����
	void Update(Input input);
	//�`�揈��
	void Draw();
	//�ʂ̃V�[���Ɉړ�����ۂɎg�p����֐�
	void ChangeScene(std::shared_ptr<SceneBase> next);
	//�I���������ĂԂƂ��Ɏg��
	void GameEnd() { m_isEnd = true; }
	//�I���������Ă΂ꂽ���ǂ����擾����
	bool GetEnd() { return m_isEnd; }
private:
	std::shared_ptr<SceneBase> m_pScene;

	bool m_isEnd;//�I���������ĂԂƂ��Ɏg��
};

