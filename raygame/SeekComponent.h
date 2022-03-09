#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>

class SeekComponent :
	public SteeringComponent
{
public:
	SeekComponent(Actor* target, float steeringForce) : SteeringComponent::SteeringComponent(target, steeringForce) {};
	~SeekComponent() {};

	MathLibrary::Vector2 calculateForce() override;
private:
	float m_speed = 200;
};

