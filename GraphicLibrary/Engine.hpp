/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#pragma once
#include "TimeClock.hpp"

class Engine 
{
public:
	Engine() = default;

	void Init();
	void Update();
	void Delete();
	void Reset();
	void Clear();
	bool IsDone();

private :
	bool Is_Done = false;
	float m_dt;
	TimeClock timer;

};