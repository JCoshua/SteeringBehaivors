#include "PursueComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MovementComponent.h"

MathLibrary::Vector2 PursueComponent::calculateForce()
{
	MathLibrary::Vector2 V = getTarget()->getTransform()->getWorldPosition() + getTarget()->getComponent<MovementComponent>()->getVelocity() - getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 SteeringForce = V.getNormalized() * m_speed - m_velocity;
	m_velocity = m_velocity + SteeringForce;
	return m_velocity;
}
