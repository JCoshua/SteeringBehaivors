#pragma once
#include "Agent.h"
class Enemy :
	public Agent
{
public:
	Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target) : Agent(x, y, name, maxForce, maxSpeed, target) {};
	void start() override;

	bool getIsAggressive() { return m_isAggressive; }
	void setIsAggressive(bool value) { m_isAggressive = value; }

	bool getTargetInSight();
private:
	bool m_isAggressive;
};

