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
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
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
	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
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
		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		// esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}