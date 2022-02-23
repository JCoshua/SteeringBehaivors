#include "Agent.h"
#include "Transform2D.h"
#include "MovementComponent.h"
#include "SpriteComponent.h"
#include "SeekComponent.h"
#include "FleeComponent.h"
#include "WanderComponent.h"

void Agent::start()
{
	Actor::start();

	m_moveComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	m_moveComponent->setSpeed(500);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));
	m_seekComponent = dynamic_cast<SeekComponent*>(addComponent(new SeekComponent()));
	m_fleeComponent = dynamic_cast<FleeComponent*>(addComponent(new FleeComponent()));
	m_wanderComponent = dynamic_cast<WanderComponent*>(addComponent(new WanderComponent(10,10)));
}

void Agent::update(float deltaTime)
{
	m_moveComponent->setVelocity({ 0,0 });
	if ((getTransform()->getWorldPosition() - m_target->getTransform()->getWorldPosition()).getMagnitude() > 200)
	{
		m_wanderComponent->changeVelocity(deltaTime);
		getTransform()->setForward(m_wanderComponent->getVelocity());
		m_moveComponent->setVelocity(m_wanderComponent->getVelocity());
	}


	//Moves the Agent to the other side of the screen if they hit an edge
	if (getTransform()->getWorldPosition().x < 0)
		getTransform()->setWorldPostion({ 700, getTransform()->getWorldPosition().y });
	if (getTransform()->getWorldPosition().y < 0)
		getTransform()->setWorldPostion({ getTransform()->getWorldPosition().x, 800 });
	if (getTransform()->getWorldPosition().x > 700)
		getTransform()->setWorldPostion({ 0, getTransform()->getWorldPosition().y });
	if (getTransform()->getWorldPosition().y > 800)
		getTransform()->setWorldPostion({ getTransform()->getWorldPosition().x, 0 });

	Actor::update(deltaTime);
}
