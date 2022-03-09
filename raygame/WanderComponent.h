#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>
#include "Actor.h"
#include "Transform2D.h"
#include <stdlib.h>
#include <time.h>

class WanderComponent :
	public SteeringComponent
{
public:
	WanderComponent(float distance, float radius, float wanderForce) : SteeringComponent::SteeringComponent() 
	{
		m_distance = distance;
		m_radius = radius;
		setSteeringForce(wanderForce);
		srand((unsigned int)time(0));
	};
	~WanderComponent() {};

	MathLibrary::Vector2 calculateForce() override;
private:
	float m_distance = 0;
	float m_radius = 0;

	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_circlePos;
};

