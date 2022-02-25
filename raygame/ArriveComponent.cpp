#include "ArriveComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MovementComponent.h"

void ArriveComponent::changeVelocity(Actor* target, float deltaTime)
{
	MathLibrary::Vector2 V = target->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 SteeringForce = V.getNormalized() + (V/m_speed * m_speed) - m_velocity;
	m_velocity = m_velocity + SteeringForce * deltaTime;
}
