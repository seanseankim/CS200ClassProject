#pragma once
#include "State.hpp"
#include "Object.hpp"
#include "Component_Text.hpp"
#include <string>
#include <iostream>

class Start : public State
{
public:
	Start()
	{
		current_state = DemoState::menu;
	}

	virtual void Load();
	virtual void Update(float dt);
	virtual void UnLoad()
	{
		next_level = {};
		is_next = false;
	}
	void Clear();
	static Start* Get_Start()
	{
		return start;
	}

private:

	static Start* start;

	BitmapFont font{};

	Object* player{};
	Object* pipe{};
	Object* mountain{};
	Object* ground{};
	Object* sun{};

};
