#include "Player.h"
#include "InputComponent.h"
#include "MovementComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"

Player::~Player()
{
}

void Player::start()
{
	Actor::start();

	m_inputComponent = addComponent<InputComponent>();
	m_moveComponent = addComponent<MovementComponent>();
	m_moveComponent->setSpeed(500);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));

	//Set spawn point
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();
	m_moveComponent->setVelocity(moveDirection.getNormalized() * 100);
	

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

