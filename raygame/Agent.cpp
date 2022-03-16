#include "Agent.h"
#include "Transform2D.h"
#include "MovementComponent.h"
#include "SpriteComponent.h"
#include "SeekComponent.h"
#include "FleeComponent.h"
#include "WanderComponent.h"
#include "PursueComponent.h"
#include "EvadeComponent.h"
#include "ArriveComponent.h"
#include "StateMachineComponent.h"

Agent::Agent(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target) : Actor(x, y, name)
{
	m_maxForce = maxForce;
	m_moveComponent = addComponent<MovementComponent>();
	m_moveComponent->setSpeed(maxSpeed);
	m_target = target;
}

Agent::Agent(float x, float y, const char* name, float maxForce, float maxSpeed) : Actor(x, y, name)
{
	m_maxForce = maxForce;
	m_moveComponent = addComponent<MovementComponent>();
	m_moveComponent->setSpeed(maxSpeed);
}

void Agent::start()
{
	Actor::start();

	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));
	addComponent(new WanderComponent(10000,5,200));
	addComponent(new SeekComponent(m_target, 150));
	addComponent(new StateMachineComponent());
}

void Agent::update(float deltaTime)
{ 
	Actor::update(deltaTime);

	//Get all forces being applied ftom sttering behaviours
	for (int i = 0; i < m_steeringComponents.getLength(); i++)
		m_force = m_force + m_steeringComponents.getItem(i)->calculateForce();

	//Clamp force if it exceeds the maximum scale
	if (m_force.getMagnitude() > getMaxForce())
		m_force = m_force.getNormalized() * getMaxForce();

	//Apply force to velocity
	getMoveComponent()->setVelocity(getMoveComponent()->getVelocity() + m_force * deltaTime);
}

void Agent::onAddComponent(Component* component)
{
	if (dynamic_cast<SteeringComponent*>(component))
		m_steeringComponents.addItem((SteeringComponent*)component);
}