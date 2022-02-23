#pragma once
#include "Component.h"
#include <Vector2.h>

class FleeComponent :
	public Component
{
public:
	FleeComponent() : Component::Component() {};
	~FleeComponent() {};

	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	void changeVelocity(Actor* target, float deltaTime);
private:
	MathLibrary::Vector2 m_velocity;
	float m_speed = 200;
};

