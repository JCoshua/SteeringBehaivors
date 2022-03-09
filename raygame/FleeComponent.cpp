#include "FleeComponent.h"
#include "Agent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MovementComponent.h"

MathLibrary::Vector2 FleeComponent::calculateForce()
{
	if (!getTarget())
		return { 0,0 };

	MathLibrary::Vector2 directionToTarget = getOwner()->getTransform()->getWorldPosition() 
		- getTarget()->getTransform()->getWorldPosition();

	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 steeringForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return steeringForce;
}
