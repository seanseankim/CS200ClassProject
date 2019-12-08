/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#pragma once
#include "Component.hpp"
#include "Transform.hpp"
#include "Object.hpp"
#include "Input.hpp"

class RandomMovement : public Component
{
public:
	void Init(Object* obj) override;
	void Update(float dt) override;
private:
};