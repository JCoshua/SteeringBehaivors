#pragma once
#include "Component.h"
#include <Vector2.h>

class MovementComponent :
	public Component
{
public:
	MovementComponent(const char* name = "MoveComponent") : Component::Component(name) {};
	~MovementComponent() {}

	/// <summary>
	/// Gets the maximum magnitude fo this actors velocity vector
	/// </summary>
	float getSpeed() { return m_maxSpeed; }

	/// <summary>
	/// Gets the maximum magnitude fo this actors velocity vector
	/// </summary>
	void setSpeed(float value) { m_maxSpeed = value; }

	/// <summary>
	/// Gets the current speed and direction of this actor
	/// </summary>
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	/// <summary>
	/// Sets the current speed and direction of this actor
	/// </summary>
	void setVelocity(MathLibrary::Vector2 value) { m_velocity = value; }

	//inherited from component class
	void update(float deltaTime) override;
private:
	float m_maxSpeed;
	MathLibrary::Vector2 m_velocity;
};

