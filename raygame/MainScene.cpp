#include "MainScene.h"
#include "Player.h"
#include "Agent.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"
#include "Transform2D.h"

void MainScene::start()
{
	Player* player = new Player(50,50, "Player");
	player->getTransform()->setScale({50, 50});

	Agent* agent = new Agent(300, 400, "Agent", player);
	agent->getTransform()->setScale({ 50, 50 });

	addActor(player);
	addActor(agent);
}
