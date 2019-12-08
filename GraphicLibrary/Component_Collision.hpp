/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#include "Component.hpp"

class Collision : public Component
{
public:
	void Init(Object* obj) override;
	void Update(float dt) override;
private:
	bool is_collided = false;
		
};