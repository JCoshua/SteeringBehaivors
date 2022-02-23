#include "MainScene.h"
#include "Player.h"
#include "Agent.h"
#include "Transform2D.h"

void MainScene::start()
{
	Player* player = new Player(960,510, "Player");
	player->getTransform()->setScale({50, 50});
	addItem(player);

	Agent* agent = new Agent(1060, 610, "Agent", player);
	agent->getTransform()->setScale({ 50, 50 });
	addItem(agent);
	
}
