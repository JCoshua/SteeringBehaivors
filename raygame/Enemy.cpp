#include "Enemy.h"
#include "Transform2D.h"
#include "SeekDecision.h"
#include "IdleDecision.h"
#include "WanderDecision.h"
#include "IsAggressiveDecision.h"
#include "InRangeDecision.h"
#include "DecisionComponent.h"
#include <Vector2.h>

void Enemy::start()
{
	Agent::start();

	IdleDecision* idle = new IdleDecision();
	WanderDecision* wander = new WanderDecision();
	SeekDecision* seek = new SeekDecision();

	IsAggressiveDecision* aggression = new IsAggressiveDecision(idle, wander);
	InRangeDecision* inRange = new InRangeDecision(aggression, seek);

	addComponent(new DecisionComponent(inRange));
}

bool Enemy::getTargetInSight()
{
	MathLibrary::Vector2 direction = getTarget()->getTransform()->getWorldPosition() - getTransform()->getWorldPosition();
	float distance = direction.getMagnitude();
	float fov = MathLibrary::Vector2::dotProduct(direction.getNormalized(), getTransform()->getForward());
	return distance <= 300 && acos(fov) < 1;
}
