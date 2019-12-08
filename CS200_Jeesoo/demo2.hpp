/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#pragma once
#include "State.hpp"
#include "Object.hpp"
#include "Component_Text.hpp"
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
	Object* ground{};
	Object* ground_1{};
	Object* ground_2{};
	Object* top_ground{};
	Object* bowser{};
	Object* pipe{};

	BitmapFont font{};
};