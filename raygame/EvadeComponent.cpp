#include "EvadeComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MovementComponent.h"

MathLibrary::Vector2 EvadeComponent::calculateForce()
{
	MathLibrary::Vector2 V = getOwner()->getTransform()->getWorldPosition() - (getTarget()->getTransform()->getWorldPosition() + getTarget()->getComponent<MovementComponent>()->getVelocity());
	MathLibrary::Vector2 SteeringForce = V.getNormalized() * m_speed - m_velocity;
	m_velocity = m_velocity + SteeringForce;
	return m_velocity;
}
