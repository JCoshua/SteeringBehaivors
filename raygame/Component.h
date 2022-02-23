#pragma once
class Actor;

class Component
{
public:
	Component();
	virtual ~Component();

	/// <summary>
	/// Gets the actor that this component is attached to
	/// </summary>
	Actor* getOwner() {return m_owner; }

	/// <summary>
	/// Assigns the owner of this component if it doesn't have one
	/// </summary>
	/// <param name="owner">The new owner of this component</param>
	void assignOwner(Actor* owner);

	/// <summary>
	/// Gets whether or not the start function has been called for this component instance
	/// </summary>
	bool getStarted() { return m_started; }

	//Functions called by actor class
	virtual void start() { m_started = true; }
	virtual void update(float deltaTime) {}
	virtual void draw() {}
	virtual void end() {}
	virtual void onCollision(Actor* other) {}
	virtual void onDestroy() {}
private:
	Actor* m_owner;
	bool m_started;
};

