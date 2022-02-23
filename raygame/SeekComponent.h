#pragma once
#include "Component.h"
#include <Vector2.h>
class SeekComponent :
	public Component
{
public:
	SeekComponent() : Component::Component() {};
	~SeekComponent() {};

	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	void changeVelocity(Actor* target, float deltaTime);
private:
	MathLibrary::Vector2 m_velocity;
	float m_speed = 200;
};

