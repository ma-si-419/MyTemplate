#include "Stage.h"
namespace
{
	constexpr float kStageSize = 0.1f;
}
Stage::Stage():
	m_pos(VGet(0,0,0)),
	m_handle(-1)
{
	m_handle = MV1LoadModel("data/model/_Stage.mv1");
	MV1SetScale(m_handle, VGet(kStageSize, kStageSize, kStageSize));
}

Stage::~Stage()
{
}

void Stage::Init()
{
	// モデル全体のコリジョン情報のセットアップ
	MV1SetupCollInfo(m_handle, -1);
}

void Stage::Update()
{
	MV1SetPosition(m_handle, m_pos);
}

void Stage::Draw()
{
	MV1DrawModel(m_handle);
}
