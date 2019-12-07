#pragma once
#include "State.hpp"
#include "Object.hpp"
#include <string>
#include <iostream>

class Demo2 : public State
{
public:
	Demo2()
	{
		current_state = DemoState::Demo2;
	}

	virtual void Load();
	virtual void Update(float dt);
	virtual void UnLoad()
	{
		next_level = {};
		is_next = false;
	}
	void Clear();
	static Demo2* Get_Demo2()
	{
		return demo2;
	}
private:
	static Demo2* demo2;

	Object* player{};
	Object* bowser{};
	Object* pipe{};
};