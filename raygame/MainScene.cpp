#include "MainScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Transform2D.h"

void MainScene::start()
{
	Player* player = new Player(400,400, "Player");
	player->getTransform()->setScale({50, 50});
	addItem(player);

	//for (int i = 0; i < 501; i++)
	{
		Enemy* enemy = new Enemy(560, 610, "Agent", 500, 500, player);
		enemy->getTransform()->setScale({ 50, 50 });
		addItem(enemy);
	}
	
}
