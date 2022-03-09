#include "WanderComponent.h"
#include "Transform2D.h"
#include "MovementComponent.h"
#include "Actor.h"
#include "Agent.h"

MathLibrary::Vector2 WanderComponent::calculateForce()
{
	if (getSteeringForce() == 0)
		return MathLibrary::Vector2(0,0);

	//Find the agents Position and Direction
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerDirection = getAgent()->getMoveComponent()->getVelocity().getNormalized();
	m_circlePos = ownerPos + (ownerDirection * m_distance);

	//Find a random point on the unit circle and scale it by the radius
	float randNum = rand() % 201;
	MathLibrary::Vector2 randDirection = MathLibrary::Vector2(sin(randNum), cos(randNum)).getNormalized() * m_radius;
	m_target = m_circlePos + randDirection;

	MathLibrary::Vector2 desiredVelocity = (m_target - ownerPos).getNormalized() * getSteeringForce();
	MathLibrary::Vector2 force = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();
	return force;
}
