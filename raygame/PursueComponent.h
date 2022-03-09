#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>

class PursueComponent :
	public SteeringComponent
{
public:
	PursueComponent(Actor* target, float steeringForce) : SteeringComponent::SteeringComponent(target, steeringForce) {};
	~PursueComponent() {};

	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	MathLibrary::Vector2 calculateForce() override;
private:
	MathLibrary::Vector2 m_velocity;
	float m_speed = 200;
};

