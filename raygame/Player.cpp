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

	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	m_moveComponent->setSpeed(500);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));
	//Set spawn point
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();
	m_moveComponent->setVelocity(moveDirection * 200);

	Actor::update(deltaTime);

	if (getTransform()->getWorldPosition().x < 0)
		getTransform()->setWorldPostion({ 700, getTransform()->getWorldPosition().y });
	if (getTransform()->getWorldPosition().y < 0)
		getTransform()->setWorldPostion({ getTransform()->getWorldPosition().x, 800 });

	if (getTransform()->getWorldPosition().x > 700)
		getTransform()->setWorldPostion({ 0, getTransform()->getWorldPosition().y });
	if (getTransform()->getWorldPosition().y > 800)
		getTransform()->setWorldPostion({ getTransform()->getWorldPosition().x, 0 });
}

