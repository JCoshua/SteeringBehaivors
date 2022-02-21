#pragma once
#include "Actor.h"
class InputComponent;
class MovementComponent;
class SpriteComponent;

class Player :
	public Actor
{
public:
	Player(float x, float y, char const* name = "Player") : Actor(x, y, name) {};
	~Player();
	void start() override;
	void update(float deltaTime) override;

private:
	InputComponent* m_inputComponent;
	MovementComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
};

