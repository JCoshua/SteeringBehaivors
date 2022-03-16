#include "SeekDecision.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "Agent.h"
#include "Enemy.h"

void SeekDecision::makeDecision(Agent* agent, float deltaTime)
{
	WanderComponent* wander = agent->getComponent<WanderComponent>();
	SeekComponent* seek = agent->getComponent<SeekComponent>();
	Enemy* enemy = dynamic_cast<Enemy*>(agent);

	if (enemy)
		enemy->setIsAggressive(true);
	if (seek)
		seek->setSteeringForce(200);
	if (wander)
		wander->setSteeringForce(0);
}

