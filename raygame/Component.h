#pragma once
class Actor;

class Component
{
public:
	Component();
	Component(const char* name);
	virtual ~Component();

	/// <summary>
	/// Gets the name of this component
	/// </summary>
	const char* getName() { return m_name; }

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
	const char* m_name;
	bool m_started;
};

