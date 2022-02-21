#include "WanderComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include <stdlib.h>

void WanderComponent::changeVelocity(float deltaTime)
{
	MathLibrary::Vector2 target = getOwner()->getTransform()->getWorldPosition();
	target.x = target.x + (rand() - rand());
	target.y = target.y + (rand() - rand());
	target = getOwner()->getTransform()->getWorldPosition() + target.getNormalized() * m_radius;
	MathLibrary::Vector2 jitter = { (float)(rand() - rand()), (float)(rand() - rand()) };
	target = target + (jitter.getNormalized() * m_jitter);
	target = target.getNormalized() * m_radius;
	target = getOwner()->getTransform()->getWorldPosition() + (target * m_distance);

	m_previous = target;
	MathLibrary::Vector2 desiredVelocity = (target - getOwner()->getTransform()->getWorldPosition()).getNormalized() * 500;
	MathLibrary::Vector2 SteeringForce = desiredVelocity - m_velocity;
	m_velocity = m_velocity + SteeringForce * deltaTime;
}
