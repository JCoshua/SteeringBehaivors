#include "PursueComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MovementComponent.h"

void PursueComponent::changeVelocity(Actor* target, float deltaTime)
{
	MathLibrary::Vector2 V = target->getTransform()->getWorldPosition() + target->getComponent<MovementComponent>()->getVelocity() - getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 SteeringForce = V.getNormalized() * m_speed - m_velocity;
	m_velocity = m_velocity + SteeringForce * deltaTime;
}
