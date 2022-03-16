#pragma once
#include "BooleanDecision.h"

class InRangeDecision :
	public BooleanDecision
{
public:
	InRangeDecision(Decision* leftChild = nullptr, Decision* rightChild = nullptr) : BooleanDecision(leftChild, rightChild) {};
	bool checkCondition(Agent* agent, float deltaTime) override;
};

