#include "SpotLight.h"
#include "Input.h"

namespace
{
	//ライトの色
	const VECTOR kColor = VGet(1.0, 1.0, 1.0);
	//ライトの射出角度
	constexpr float kInitAngle = 3.14f / 180 * 25;
	//ライトの影響範囲
	constexpr float kInitPower = 1000.0f;
}


SpotLight::SpotLight() :
	m_pos(VGet(0, 50, 0)),
	m_dir(VNorm(VGet(-1, -1, 0))),
	m_color(kColor),
	m_power(kInitPower),
	m_viewAngle(kInitAngle),
	dirX(0),
	dirY(0),
	dirZ(-1)
{
	m_targetPos = VGet(10, 0, 10);
}

SpotLight::~SpotLight()
{
}

void SpotLight::Update(Input input)
{
	Input::StickInfo stickInfo;

	stickInfo = input.GetStickInfo();

	VECTOR moveDirVec = VGet(stickInfo.leftStickX, 0, stickInfo.leftStickY);
	//Bボタンを押しているときだけ動く
	if (input.IsPress("cancel"))
	{
		if (VSize(moveDirVec) != 0)
		{
			moveDirVec.z *= -1;

			moveDirVec = VNorm(moveDirVec);

			if (input.IsPress("OK"))
			{
				moveDirVec.y = moveDirVec.z;
				moveDirVec.z = 0;
			}

			VECTOR moveVec = VScale(moveDirVec, 1);

			m_pos = VAdd(m_pos, moveVec);
		}

		VECTOR angleDirVec = VGet(stickInfo.rightStickX, 0,-stickInfo.rightStickY);

		if (VSize(angleDirVec) != 0)
		{
			angleDirVec = VNorm(angleDirVec);

			VECTOR dirMoveVec = VScale(angleDirVec, 0.01);

			m_dir = VAdd(m_dir, dirMoveVec);
		}
	}

	dirX += 0.01f;
	dirZ += 0.01f;

	m_targetPos.x = sinf(dirX) * 100;
	m_targetPos.z = sinf(dirZ) * 100;
	

	m_dir = VNorm(VSub(m_targetPos,m_pos));
}

void SpotLight::Draw()
{
	DrawSphere3D(m_pos, 5, 30, GetColor(255, 0, 255), GetColor(255, 255, 255), true);
	DrawSphere3D(m_targetPos, 3, 30, GetColor(255, 255, 255), GetColor(255, 255, 255), true);

}
