#pragma once
#include "SceneBase.h"
#include <memory>

class Player;
class Camera;
class Stage;
class PointLight;
class SpotLight;
class CollisionManager;
class SceneGame : public SceneBase
{
private:
	//�V�F�[�_�ɓn���f�[�^�\����
	struct LightData
	{
		float PLightPos[3];

		float pad1;

		float PLightColor[3];

		float PLightPower;

		float DLightDir[3];

		float pad2;

		float DLightColor[3];

		float pad3;

		float SpLightPos[3];

		float pad4;

		float SpLightColor[3];

		float SpLightPower;

		float SpLightDir[3];

		float SpLightAngle;

		float CameraPos[3];

		float pad5;
	};
public:
	SceneGame(SceneManager& sceneManager);
	~SceneGame();
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
	/// �I������
	/// </summary>
	void End();
private:
	std::shared_ptr<Player> m_pPlayer;
	std::shared_ptr<Camera> m_pCamera;
	std::shared_ptr<Stage> m_pStage;
	std::shared_ptr<PointLight> m_pPointLight;
	std::shared_ptr<SpotLight> m_pSpotLight;
	std::shared_ptr<CollisionManager> m_pCollisionManager;

	//�V�F�[�_�[�n���h��
	int m_psHandle;
	int m_vsHandle;

	//C�o�b�t�@
	int m_cBuff;
	//�V�F�[�_�ɑ��郉�C�g�̃f�[�^
	LightData* m_lightData;

};
