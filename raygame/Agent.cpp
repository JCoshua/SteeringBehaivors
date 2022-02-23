#include "Agent.h"
#include "Transform2D.h"
#include "MovementComponent.h"
#include "SpriteComponent.h"
#include "SeekComponent.h"
#include "FleeComponent.h"
#include "WanderComponent.h"
#include "PursueComponent.h"
#include "EvadeComponent.h"

void Agent::start()
{
	Actor::start();

	m_moveComponent = addComponent<MovementComponent>();
	m_moveComponent->setSpeed(500);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));
	m_seekComponent = addComponent<SeekComponent>();
	m_fleeComponent = addComponent<FleeComponent>();
	m_pursueComponent = addComponent<PursueComponent>();
	m_evadeComponent = dynamic_cast<EvadeComponent*>(addComponent(new EvadeComponent(m_target)));
	m_wanderComponent = dynamic_cast<WanderComponent*>(addComponent(new WanderComponent(10,10)));
}

void Agent::update(float deltaTime)
{
	m_evadeComponent->changeVelocity(deltaTime);
	getTransform()->setForward(m_evadeComponent->getVelocity());
	m_moveComponent->setVelocity(m_evadeComponent->getVelocity());
	
	//Moves the Agent to the other side of the screen if they hit an edge
	if (getTransform()->getWorldPosition().x < 0)
		getTransform()->setWorldPostion({ 1920, getTransform()->getWorldPosition().y });
	if (getTransform()->getWorldPosition().y < 0)
		getTransform()->setWorldPostion({ getTransform()->getWorldPosition().x, 1020 });
	if (getTransform()->getWorldPosition().x > 1920)
		getTransform()->setWorldPostion({ 0, getTransform()->getWorldPosition().y });
	if (getTransform()->getWorldPosition().y > 1020)
		getTransform()->setWorldPostion({ getTransform()->getWorldPosition().x, 0 });

	Actor::update(deltaTime);
}
