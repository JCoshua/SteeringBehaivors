#include "SeekComponent.h"
#include "Transform2D.h"
#include "MovementComponent.h"
#include "Actor.h"
#include "Agent.h"

MathLibrary::Vector2 SeekComponent::calculateForce()
{
	if (!getTarget())
		return { 0,0 };

	MathLibrary::Vector2 directionToTarget = getTarget()->getTransform()->getWorldPosition()
		- getOwner()->getTransform()->getWorldPosition();

	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 steeringForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return steeringForce;
}
