#include "DxLib.h"
#include "Sphere.h"
#include "Triangle.h"
#include <cmath>
namespace
{
	constexpr int kCameraDist = 400;
	constexpr int kCameraHeight = 250;
	constexpr float kCameraSpeed = 3.0f;
}
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	ChangeLightTypeDir(VGet(0, -1, 0));

	//	SetLightDifColor(GetColorF(0.0f, 0.0f, 1.0f, 0.0f));


	SetCameraNearFar(0.1f, 1000.0f);

	VECTOR cameraPos = VGet(0, 300, -300);

	float cameraAngle = 0.0f;


	Sphere* sphere;
	sphere = new Sphere();

	Triangle* triangle;
	triangle = new Triangle();
	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		for (int i = 0; i < 50; i++)
		{
			DrawLine3D(VGet(-1000, 0, i * 50 - 1000), VGet(1000, 0, i * 50 - 1000), GetColor(0, 255, 255));
		}
		for (int j = 0; j < 50; j++)
		{
			DrawLine3D(VGet(j * 50 - 1000, 0, -2000), VGet(j * 50 - 1000, 0, 2000), GetColor(255, 255, 0));
		}

		if (CheckHitKey(KEY_INPUT_Q))
		{
			cameraAngle += 0.05f;
		}
		else if (CheckHitKey(KEY_INPUT_E))
		{
			cameraAngle -= 0.05f;
		}
		
		cameraPos.x = cosf(cameraAngle) * kCameraDist;
		cameraPos.y = kCameraHeight;
		cameraPos.z = sinf(cameraAngle) * kCameraDist;

		sphere->SetCameraAngle(cameraAngle);

		triangle->Update(sphere->GetPos());
		sphere->Update();

		VECTOR nextPos = triangle->SetTargetPos(sphere->GetPos());

		sphere->SetPos(nextPos);

		triangle->Draw();
		sphere->Draw();

		SetCameraPositionAndTarget_UpVecY(cameraPos, VGet(0, 0, 0));
		// 画面が切り替わるのを待つ
		ScreenFlip();

		// escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60に固定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}