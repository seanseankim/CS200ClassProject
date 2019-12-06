#pragma once
#include "State.hpp"
#include "Object.hpp"
#include <string>
#include <iostream>

class Demo1 : public State
{
public:
	Demo1()
	{
		current_state = DemoState::Demo1;
	}

	virtual void Load();
	virtual void Update(float dt);
	virtual void UnLoad()
	{
		next_level = {};
		is_next = false;
	}
	void Clear();
	static Demo1* Get_Demo1()
	{
		return demo1;
	}
private:
	static Demo1* demo1;
	Object* player;
	Object* animatedObject;
	Object* animatedObject_2;	
	Object* animatedObject_3; 
	Object* ground;
	Object* top_ground;
	Object* turtle;
	Object* pipe;
};