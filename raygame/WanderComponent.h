#pragma once
#include "Component.h"
#include <Vector2.h>
#include "Actor.h"
#include "Transform2D.h"
#include <stdlib.h>
class WanderComponent :
	public Component
{
public:
	WanderComponent(float distance, float radius) : 
		Component::Component() { m_distance = distance, m_radius = radius; };
	~WanderComponent() {};

	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	void changeVelocity(float deltaTime);
	void start() override;
private:
	MathLibrary::Vector2 m_velocity;
	MathLibrary::Vector2 m_previous;
	float m_speed = 200;
	int m_radius;
	float m_distance;
};

