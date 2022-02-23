#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"

void SeekComponent::changeVelocity(Actor* target, float deltaTime)
{
	MathLibrary::Vector2 desiredVelocity = (target->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()).getNormalized() * 150;
	MathLibrary::Vector2 SteeringForce = desiredVelocity - m_velocity;
	m_velocity = m_velocity + SteeringForce * deltaTime;
}
