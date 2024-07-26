#include "SceneGame.h"
#include "SceneTitle.h"
#include "DxLib.h"
#include "Player.h"
#include "Camera.h"
#include "Stage.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "CollisionManager.h"
namespace
{

}
SceneGame::SceneGame(SceneManager& sceneManager) :
	SceneBase(sceneManager)
{
	m_pPlayer = std::make_shared<Player>();
	m_pCamera = std::make_shared<Camera>();
	m_pStage = std::make_shared<Stage>();
	m_pPointLight = std::make_shared<PointLight>();
	m_pSpotLight = std::make_shared<SpotLight>();
	m_pCollisionManager = std::make_shared<CollisionManager>(m_pPlayer,m_pStage);

	//オリジナルシェーダー使うと宣言
	MV1SetUseOrigShader(true);

	//シェーダーハンドル
	m_psHandle = LoadPixelShader("PixelShader.pso");
	m_vsHandle = LoadVertexShader("VertexShader.vso");

	m_cBuff = CreateShaderConstantBuffer(sizeof(LightData));

	m_lightData = static_cast<LightData*>(GetBufferShaderConstantBuffer(m_cBuff));

	//ポイントライトの情報を取得する
	{

		m_lightData->PLightPower = m_pPointLight->GetPower();

		m_lightData->PLightPos[0] = m_pPointLight->GetPos().x;
		m_lightData->PLightPos[1] = m_pPointLight->GetPos().y;
		m_lightData->PLightPos[2] = m_pPointLight->GetPos().z;

		m_lightData->PLightColor[0] = m_pPointLight->GetLightColor().x;
		m_lightData->PLightColor[1] = m_pPointLight->GetLightColor().y;
		m_lightData->PLightColor[2] = m_pPointLight->GetLightColor().z;

	}

	//ディレクションライトの情報を設定する
	{

		m_lightData->DLightColor[0] = 0.03f;
		m_lightData->DLightColor[1] = 0.03f;
		m_lightData->DLightColor[2] = 0.03f;

		//m_lightData->DLightColor[0] = 0.0f;
		//m_lightData->DLightColor[1] = 0.8f;
		//m_lightData->DLightColor[2] = 0.5f;

		m_lightData->DLightDir[0] = 0.0;
		m_lightData->DLightDir[1] = -1.0;
		m_lightData->DLightDir[2] = 0.0;

	}

	//スポットライトの情報を設定する
	{

		m_lightData->SpLightPos[0] = m_pSpotLight->GetPos().x;
		m_lightData->SpLightPos[1] = m_pSpotLight->GetPos().y + 100;
		m_lightData->SpLightPos[2] = m_pSpotLight->GetPos().z;

		m_lightData->SpLightColor[0] = m_pSpotLight->GetLightColor().x;
		m_lightData->SpLightColor[1] = m_pSpotLight->GetLightColor().y;
		m_lightData->SpLightColor[2] = m_pSpotLight->GetLightColor().z;

		m_lightData->SpLightDir[0] = m_pSpotLight->GetDir().x;
		m_lightData->SpLightDir[1] = m_pSpotLight->GetDir().y;
		m_lightData->SpLightDir[2] = m_pSpotLight->GetDir().z;

		m_lightData->SpLightAngle = m_pSpotLight->GetViewAngle();

		m_lightData->SpLightPower = m_pSpotLight->GetPower();

	}
	//カメラの座標を取得する
	{

		m_lightData->CameraPos[0] = m_pCamera->GetPos().x;
		m_lightData->CameraPos[1] = m_pCamera->GetPos().y;
		m_lightData->CameraPos[2] = m_pCamera->GetPos().z;

	}
	SetUseVertexShader(m_vsHandle);
	SetUsePixelShader(m_psHandle);
}

SceneGame::~SceneGame()
{

}

void SceneGame::Init()
{

	m_pPlayer->Init();

	m_pStage->Init();
	m_pCollisionManager->Init();

}

void SceneGame::Update(Input input)
{



	m_pPlayer->Update(input);

	m_pStage->Update();

	m_pPointLight->Update(input);
	m_pSpotLight->Update(input);

	//ポイントライトの情報更新
	m_lightData->PLightPos[0] = m_pPlayer->GetDrawPos().x;
	m_lightData->PLightPos[1] = m_pPlayer->GetDrawPos().y;
	m_lightData->PLightPos[2] = m_pPlayer->GetDrawPos().z;

	//スポットライトの情報更新
	m_lightData->SpLightPos[0] = m_pPlayer->GetDrawPos().x;
	m_lightData->SpLightPos[1] = m_pPlayer->GetDrawPos().y;
	m_lightData->SpLightPos[2] = m_pPlayer->GetDrawPos().z;

	m_lightData->SpLightDir[0] = m_pPlayer->GetDir().x;
	m_lightData->SpLightDir[1] = m_pPlayer->GetDir().y;
	m_lightData->SpLightDir[2] = m_pPlayer->GetDir().z;

	//カメラの座標更新
	m_lightData->CameraPos[0] = m_pCamera->GetPos().x;
	m_lightData->CameraPos[1] = m_pCamera->GetPos().y;
	m_lightData->CameraPos[2] = m_pCamera->GetPos().z;

	m_pCollisionManager->Update();

	//プレイヤーの座標をカメラに渡す	
	m_pCamera->SetTargetPos(m_pPlayer->GetDrawPos());

	m_pCamera->Update(input);

	//シェーダ関係
	UpdateShaderConstantBuffer(m_cBuff);
	SetShaderConstantBuffer(m_cBuff, DX_SHADERTYPE_PIXEL, 4);


	if (CheckHitKey(KEY_INPUT_T))
	{
		m_sceneManager.ChangeScene(std::make_shared<SceneTitle>(m_sceneManager));
	}
}

void SceneGame::Draw()
{
	m_pPlayer->Draw();
	m_pStage->Draw();

	DrawString(0, 0, "SceneGame", GetColor(255, 255, 255));
}

void SceneGame::End()
{
}
