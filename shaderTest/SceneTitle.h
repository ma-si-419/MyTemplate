#pragma once
#include "SceneBase.h"
#include "DxLib.h"
#include <memory>
class Camera;
class SceneTitle : public SceneBase
{
public:
	SceneTitle(SceneManager& sceneManager);
	~SceneTitle();
	//����������
	void Init();
	//�X�V����
	void Update(Input input);
	//�`�揈��
	void Draw();
	//�I������
	void End();
};