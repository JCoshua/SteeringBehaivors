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

    return component;
}

bool Actor::remomveComponent(Component* component)
{
    //Check to see if the index is outside the bounds of our array
    if (!component)
        return false;

    bool componentRemoved = false;

    //Create a new array with a size one less than our old array 
    Component** newArray = new Component * [m_componentCount - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        //If the current index is not the index that needs to be removed,
        //add the value into the old array and increment j
        if (m_component[i] == component)
        {
            newArray[j] = m_component[i];
            j++;
        }
        else
            componentRemoved = true;
    }

    //Set the old array to be the tempArray
    if (componentRemoved)
    {
        delete[] m_component;
        m_component = newArray;
        m_componentCount--;
        delete component;
    }
    else
        delete[] newArray;

    //Returns whether or not the removal occured
    return componentRemoved;
}

bool Actor::remomveComponent(const char* name)
{
    //Check to see if the index is outside the bounds of our array
    if (name)
    {
        return false;
    }

    bool componentRemoved = false;
    Component* componentToDelete = nullptr;

    //Create a new array with a size one less than our old array 
    Component** newArray = new Component * [m_componentCount - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        //If the current index is not the index that needs to be removed,
        //add the value into the old array and increment j
        if (strcmp(m_component[i]->getName(), name) == 0)
        {
            newArray[j] = m_component[i];
            j++;
        }
        else
        {
            componentToDelete = m_component[i];
            componentRemoved = true;
        }
    }

    if (componentRemoved)
    {
        delete[] m_component;
        m_component = newArray;
        m_componentCount--;
        delete componentToDelete;
    }
    else
        delete[] newArray;
    
    return componentRemoved;
}

Component* Actor::getComponent(const char* name)
{
    //Iterate through the component array
    for (int i = 0; i < m_componentCount; i++)
        //Return the component if the name is the same as the current component
        if (strcmp(m_component[i]->getName(), name) == 0)
            return m_component[i];

    return nullptr;
}

Component* Actor::getComponent(int value)
{
    if(value < 0 || value > m_componentCount)
	return nullptr;

    return m_component[value];
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