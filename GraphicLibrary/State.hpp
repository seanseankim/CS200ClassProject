#pragma once
#include <string>

enum class DemoState
{
	menu, Demo1, Demo2, NA
};

class State
{
public:
	virtual void Load() = 0;
	virtual void Update(float dt) = 0;
	virtual void UnLoad() = 0;
	bool IsNextLevel()
	{
		return is_next;
	}
	void MoveLevel(std::string name)
	{
		next_level = name;
	}
	std::string GetNextLevelName()
	{
		return next_level;
	}
	DemoState GetStateInfo()
	{
		return current_state;
	}
	bool& Get_is_next()
	{
		return is_next;
	}
	std::string& Get_next_level()
	{
		return next_level;
	}
protected:
	std::string next_level;
	bool is_next = false;
	DemoState current_state = DemoState::NA;
};
