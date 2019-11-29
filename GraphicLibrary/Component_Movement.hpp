#pragma once
#include "Component.hpp"
#include "Transform.hpp"
#include "Object.hpp"
#include "Input.hpp"

class Movement : public Component
{
public:
	void Init(Object* obj) override;
	void Update(float dt) override;
private:
};