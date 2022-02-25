#pragma once
#include "Component.h"
#include <Vector2.h>

class ArriveComponent :
	public Component
{
public:
	ArriveComponent(float radius) : Component::Component() { m_radius = radius; };
	~ArriveComponent() {};

	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	void changeVelocity(Actor* target, float deltaTime);
private:
	MathLibrary::Vector2 m_velocity;
	float m_speed = 200;
	float m_radius = 5;
};

