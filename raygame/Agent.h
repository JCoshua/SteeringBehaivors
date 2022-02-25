#pragma once
#include "Actor.h"
class MovementComponent;
class SpriteComponent;
class SeekComponent;
class FleeComponent;
class WanderComponent;
class PursueComponent;
class EvadeComponent;
class ArriveComponent;

class Agent :
	public Actor
{
public:
	Agent(float x, float y, const char* name, Actor* target) : Actor(x, y, name) { m_target = target; }
	~Agent();

	void start() override;
	void update(float deltaTime) override;

	void setTarget(Actor* target) { m_target = target; }
private:
	MovementComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	SeekComponent* m_seekComponent;
	FleeComponent* m_fleeComponent;
	WanderComponent* m_wanderComponent;
	PursueComponent* m_pursueComponent;
	EvadeComponent* m_evadeComponent;
	ArriveComponent* m_arriveComponent;
	Actor* m_target;
};

