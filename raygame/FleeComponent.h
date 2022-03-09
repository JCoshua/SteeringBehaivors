#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>

class FleeComponent :
	public SteeringComponent
{
public:
	FleeComponent(Actor* target, float steeringForce) : SteeringComponent::SteeringComponent(target, steeringForce) {};
	~FleeComponent() {};

	MathLibrary::Vector2 calculateForce() override;
private:
	float m_speed = 200;
};

