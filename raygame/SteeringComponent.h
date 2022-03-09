#pragma once
#include "Component.h"
#include <Vector2.h>
class Actor;
class Agent; 

class SteeringComponent :
	public Component
{
public:
	SteeringComponent() : Component::Component() {};
	SteeringComponent(Actor* target, float steeringForce) : Component::Component() { m_target = target, m_steeringForce = steeringForce; }

	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }

	float getSteeringForce() { return m_steeringForce; }
	void setSteeringForce(float force) { m_steeringForce = force; }

	Agent* getAgent() { return (Agent*)getOwner(); }

	virtual MathLibrary::Vector2 calculateForce() = 0;
private:
	float m_steeringForce;
	Actor* m_target;
};

