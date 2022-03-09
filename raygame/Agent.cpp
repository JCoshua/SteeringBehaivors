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

void Agent::start()
{
	Actor::start();

	m_moveComponent = addComponent<MovementComponent>();
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));
	addComponent(new WanderComponent(200, 10, 100));
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