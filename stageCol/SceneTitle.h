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
	//初期化処理
	void Init();
	//更新処理
	void Update(Input input);
	//描画処理
	void Draw();
	//終了処理
	void End();
};