#include "WanderComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "raylib.h"
#include <stdlib.h>

void WanderComponent::changeVelocity(float deltaTime)
{
	MathLibrary::Vector2 target;
	target.x = rand() % (m_radius * 2 + 1) - m_radius;
	target.y = rand() % (m_radius * 2 + 1) - m_radius;
	target = target.getNormalized() * m_radius;
	target = m_previous + target;

	m_previous = target;
	MathLibrary::Vector2 desiredVelocity = (target - getOwner()->getTransform()->getWorldPosition()).getNormalized() * 100;
	MathLibrary::Vector2 SteeringForce = desiredVelocity - m_velocity;
	m_velocity = m_velocity + SteeringForce * deltaTime;
}

void WanderComponent::start()
{
	Component::start();
	m_previous = getOwner()->getTransform()->getWorldPosition() + (getOwner()->getTransform()->getForward() * m_distance);
}
