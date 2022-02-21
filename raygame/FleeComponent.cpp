#include "FleeComponent.h"
#include "Actor.h"
#include "Transform2D.h"

void FleeComponent::changeVelocity(Actor* target, float deltaTime)
{
	MathLibrary::Vector2 desiredVelocity = (getOwner()->getTransform()->getWorldPosition() - target->getTransform()->getWorldPosition()).getNormalized() * 100;
	MathLibrary::Vector2 SteeringForce = desiredVelocity - m_velocity;
	m_velocity = m_velocity + SteeringForce * deltaTime;
}
