#include "BooleanDecision.h"

BooleanDecision::BooleanDecision(Decision* leftChild, Decision* rightChild)
{
	m_yes = leftChild;
	m_no = rightChild;
}

void BooleanDecision::makeDecision(Agent* agent, float deltaTime)
{
	if (checkCondition(agent, deltaTime))
	{
		if (m_no)
			m_no->makeDecision(agent, deltaTime);
	}
	else
	{
		if (m_yes)
			m_yes->makeDecision(agent, deltaTime);
	}
}
