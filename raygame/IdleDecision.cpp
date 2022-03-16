#include "IdleDecision.h"
#include "WanderComponent.h"
#include "SeekComponent.h"
#include "Agent.h"

void IdleDecision::makeDecision(Agent* agent, float deltaTime)
{
	WanderComponent* wander = agent->getComponent<WanderComponent>();
	SeekComponent* seek = agent->getComponent<SeekComponent>();

	if (wander)
		wander->setSteeringForce(0);
	if (seek)
		seek->setSteeringForce(0);
}
