#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"
#include <iostream>

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

void Actor::start()
{
    m_started = true;
}

void Actor::update(float deltaTime)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (!m_component[i]->getStarted())
            m_component[i]->start();

        m_component[i]->update(deltaTime);
    }
}

void Actor::draw()
{
    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->draw();
}

void Actor::end()
{
    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->end();
    m_started = false;
}

void Actor::onCollision(Actor* other)
{
    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->onCollision(other);
}

Component* Actor::addComponent(Component* component)
{
    //Return null if this component has an owner
    if (component->getOwner())
        return nullptr;

    //Create a new array with a size one greater than our old array
    Component** appendedArray = new Component * [m_componentCount + 1];
    //Copy the values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        appendedArray[i] = m_component[i];
    }

    //Set the last value in the new array to be the actor we want to add
    appendedArray[m_componentCount] = component;
    component->assignOwner(this);

    if (m_componentCount > 1)
        delete[] m_component;
    else if (m_componentCount == 1)
        delete m_component;

    //Set old array to hold the values of the new array
    m_component = appendedArray;
    m_componentCount++;
    onAddComponent(component);

    return component;
}

void Actor::onDestroy()
{
    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->onDestroy();

    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}