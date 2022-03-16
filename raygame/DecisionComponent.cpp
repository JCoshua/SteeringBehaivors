#include "DecisionComponent.h"
#include "Decision.h"
#include "Agent.h"

void DecisionComponent::start()
{
	m_owner = dynamic_cast<Agent*>(getOwner());
}

void DecisionComponent::update(float deltaTime)
{
	if (m_owner)
		m_root->makeDecision(m_owner, deltaTime);
	else
		throw std::exception("Decision component was not attached to an Agent.");
}
