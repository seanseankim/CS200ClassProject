#pragma once
#include "State.hpp"
#include "Object.hpp"
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

private:
	Object* demo1Button;
	Object* demo2Button;
	Object* demo3Button; 
	Object* demo4Button;
	Object* demo5Button;
	Object* demo6Button;
	Object* player;
};
