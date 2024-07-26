#include "Player.h"
#include "Input.h"
namespace
{
	constexpr float kColScale = 10.0f;

	constexpr float kJumpPower = 30.0f;

	constexpr float kGravityPower = 1.5f;

	constexpr float kMaxFallSpeed = -10.0f;

	constexpr float kSpeed = 10.0f;

	const VECTOR kPlayerSize = VGet(0.1f, 0.1f, 0.1f);
	const VECTOR kPlayerInitAngle = VGet(0, 3.14f, 0);

}
Player::Player() :
	m_drawPos(VGet(0, 0, 10)),
	m_dirVec(VGet(0, 0, 0)),
	m_colPos(VAdd(m_drawPos, VGet(0, kColScale, 0))),
	m_handle(-1),
	m_jumpPower(0),
	m_isFall(false)
{
	m_handle = MV1LoadModel("data/model/Player.mv1");
	MV1SetRotationXYZ(m_handle, kPlayerInitAngle);
	MV1SetScale(m_handle, kPlayerSize);
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update(Input input)
{
	Input::StickInfo stickInfo;

	stickInfo = input.GetStickInfo();

	VECTOR dirVec = VGet(stickInfo.leftStickX, 0, stickInfo.leftStickY);

	if (VSize(dirVec) != 0)
	{
		dirVec.z *= -1;

		dirVec = VNorm(dirVec);

		DrawFormatString(100, 100, GetColor(255, 255, 255), "%d,%d", stickInfo.leftStickX, stickInfo.leftStickY);
		m_dirVec = dirVec;

		VECTOR moveVec = VScale(dirVec, kSpeed);

		m_drawPos = VAdd(m_drawPos, moveVec);
	}

	if (m_isFall)
	{
		m_jumpPower -= kGravityPower;
	}
	else
	{
		m_jumpPower = 0;
	}

	if (input.IsTrigger("jump"))
	{
		m_jumpPower = kJumpPower;
		m_isFall = true;
	}
	if (m_jumpPower < kMaxFallSpeed)
	{
		m_jumpPower = kMaxFallSpeed;
	}

	m_drawPos.y += m_jumpPower;



	m_colPos = VAdd(m_drawPos, VGet(0, kColScale, 0));

	//	m_drawPos.y += 30;

	MV1SetPosition(m_handle, m_drawPos);
}

void Player::Draw()
{
	MV1DrawModel(m_handle);
	DrawSphere3D(m_colPos, kColScale, 10, GetColor(255, 255, 255), GetColor(255, 0, 0), false);
}
