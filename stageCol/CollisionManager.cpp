#include "CollisionManager.h"
#include "Player.h"
#include "Stage.h"
namespace
{
	constexpr float kPlayerColScale = 20.0f;
}
CollisionManager::CollisionManager(std::shared_ptr<Player> player, std::shared_ptr<Stage> stage)
{
	count = 0;
	m_pPlayer = player;
	m_pStage = stage;
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::Init()
{
}

void CollisionManager::Update()
{
	MV1_COLL_RESULT_POLY_DIM checkCol;

	checkCol =  MV1CollCheck_Sphere(m_pStage->GetHandle(),-1, m_pPlayer->GetColPos(), kPlayerColScale);

	bool fallFlag = true;

	for (int i = 0; i < checkCol.HitNum; i++)
	{
		if (checkCol.Dim[i].HitFlag && checkCol.Dim[i].Normal.y == 1)
		{
			fallFlag = false;
			count++;
			VECTOR nextPos = m_pPlayer->GetColPos();
			nextPos.y = checkCol.Dim[i].HitPosition.y;
			m_pPlayer->SetPos(nextPos);
			printfDx("‚ ‚½‚Á‚½‚Å‚¢%d\n",count);
		}
	}
	m_pPlayer->SetFall(fallFlag);
}
