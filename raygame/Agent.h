#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include "SteeringComponent.h"
#include <Vector2.h>
#include "MovementComponent.h"
class SpriteComponent;

class Agent :
	public Actor
{
public:
	Agent(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target);
	Agent(float x, float y, const char* name, float maxForce, float maxSpeed);
	~Agent();

	void start() override;
	void update(float deltaTime) override;
	void onAddComponent(Component* component) override;
	float getMaxForce() { return m_maxForce; }
	void setMaxForce(float force) { m_maxForce = force; }

	MovementComponent* getMoveComponent() { return m_moveComponent; }

	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }

private:
	DynamicArray<SteeringComponent*> m_steeringComponents;
	MovementComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	MathLibrary::Vector2 m_force;
	Actor* m_target;
	float m_maxForce = 500;
};

