#pragma once
#include "Component.h"
#include <Vector2.h>
class WanderComponent :
	public Component
{
public:
	WanderComponent(float distance, float radius, float jitter, const char* name = "SeekComponent") : 
		Component::Component(name) { m_distance = distance, m_radius = radius, m_jitter = jitter; };
	~WanderComponent() {};

	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	void changeVelocity(float deltaTime);
private:
	MathLibrary::Vector2 m_velocity;
	MathLibrary::Vector2 m_previous;
	float m_speed = 200;
	int m_radius;
	float m_distance;
	float m_jitter = 10;
};

