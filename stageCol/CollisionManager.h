#pragma once
#include<memory>

class Player;
class Stage;
class CollisionManager
{
public:
	CollisionManager(std::shared_ptr<Player> player, std::shared_ptr<Stage> stage);
	~CollisionManager();

	void Init();
	void Update();
private:
	std::shared_ptr<Player> m_pPlayer;
	std::shared_ptr<Stage> m_pStage;

	int count;
};

