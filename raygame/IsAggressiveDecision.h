#pragma once
#include "BooleanDecision.h"
#include "Enemy.h"
class IsAggressiveDecision :
	public BooleanDecision
{
public:
	IsAggressiveDecision(Decision* leftChild = nullptr, Decision* rightChild = nullptr) : BooleanDecision(leftChild, rightChild) {};
	bool checkCondition(Agent* agent, float deltaTime) override;
};

