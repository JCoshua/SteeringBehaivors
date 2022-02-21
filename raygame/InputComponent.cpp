#include "InputComponent.h"

InputComponent::~InputComponent()
{
}

void InputComponent::start()
{
}

void InputComponent::update(float deltaTime)
{
	
}

void InputComponent::draw()
{
}

void InputComponent::end()
{
}

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	//Gets the direction for the indiviual axis
	int xDirection = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_A) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_D);
	int yDirection = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_W) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_S);

	//Returns a new vector represneting the move direction
	return MathLibrary::Vector2(xDirection, yDirection);
}
