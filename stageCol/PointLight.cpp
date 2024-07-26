#include "PointLight.h"
#include "Input.h"
namespace
{
	//ライトの色
	const VECTOR kColor = VGet(1.0, 0.0, 0.0);
	//ライトの影響範囲
	constexpr float kInitPower = 300.0f;
}

PointLight::PointLight() :
	m_pos(VGet(0, 20, 0)),
	m_color(kColor),
	m_power(kInitPower)
{
}

PointLight::~PointLight()
{
}

void PointLight::Update(Input input)
{
	Input::StickInfo stickInfo;

	stickInfo = input.GetStickInfo();

	VECTOR dirVec = VGet(stickInfo.leftStickX, 0, stickInfo.leftStickY);

	if (!input.IsPress("cancel"))
	{
		if (VSize(dirVec) != 0)
		{
			dirVec.z *= -1;

			dirVec = VNorm(dirVec);

			if (input.IsPress("OK"))
			{
				dirVec.y = dirVec.z;
				dirVec.z = 0;
			}

			VECTOR moveVec = VScale(dirVec, 1);

			m_pos = VAdd(m_pos, moveVec);
		}
	}

}

void PointLight::Draw()
{
	DrawSphere3D(m_pos, 3, 20, GetColor(0, 255, 0), GetColor(255, 255, 255), true);
}
