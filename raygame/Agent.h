#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include "SteeringComponent.h"
#include <Vector2.h>
class MovementComponent;
class SpriteComponent;

class Agent :
	public Actor
{
public:
	Agent(float x, float y, const char* name, Actor* target) : Actor(x, y, name) { m_target = target; }
	~Agent();

	void start() override;
	void update(float deltaTime) override;
	void onAddComponent(Component* component) override;
	float getMaxForce() { return m_maxForce; }
	void setMaxForce(float force) { m_maxForce = force; }

	MovementComponent* getMoveComponent() { return m_moveComponent; }

	void setTarget(Actor* target) { m_target = target; }
private:
	DynamicArray<SteeringComponent*> m_steeringComponents;
	MovementComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	MathLibrary::Vector2 m_force;
	Actor* m_target;
	float m_maxForce = 500;
};

