#include "EvadeComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MovementComponent.h"

void EvadeComponent::changeVelocity(Actor* target, float deltaTime)
{
	MathLibrary::Vector2 V = getOwner()->getTransform()->getWorldPosition() - (target->getTransform()->getWorldPosition() + target->getComponent<MovementComponent>()->getVelocity());
	MathLibrary::Vector2 SteeringForce = V.getNormalized() * m_speed - m_velocity;
	m_velocity = m_velocity + SteeringForce * deltaTime;
}
