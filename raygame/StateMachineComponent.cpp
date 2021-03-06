#include "StateMachineComponent.h"
#include "WanderComponent.h"
#include "SeekComponent.h"
#include "Transform2D.h"
#include "Actor.h"

void StateMachineComponent::start()
{
	Component::start();

	m_seekComponent = getOwner()->getComponent<SeekComponent>();
	m_seekForce = m_seekComponent->getSteeringForce();

	m_wanderComponent = getOwner()->getComponent<WanderComponent>();
	m_wanderForce = m_wanderComponent->getSteeringForce();

	m_currentState = IDLE;
}

void StateMachineComponent::update(float deltaTime)
{
	MathLibrary::Vector2 targetPos = m_seekComponent->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();

	bool playerInRange = (targetPos - ownerPos).getMagnitude() <= m_seekRange;

	switch (m_currentState)
	{
	case IDLE:
		m_seekComponent->setSteeringForce(0);
		m_wanderComponent->setSteeringForce(0);

		if (playerInRange)
			setCurrentState(SEEK);
		else
			setCurrentState(WANDER);
		break;
	case WANDER:
		m_seekComponent->setSteeringForce(0);
		m_wanderComponent->setSteeringForce(m_wanderForce);

		if (playerInRange)
			setCurrentState(SEEK);
		break;
	case SEEK:
		m_seekComponent->setSteeringForce(m_seekForce);
		m_wanderComponent->setSteeringForce(0);

		if (!playerInRange)
			setCurrentState(WANDER);
		break;
	}
}
