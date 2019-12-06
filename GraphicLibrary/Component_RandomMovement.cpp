#include "Component_RandomMovement.hpp"
#include <time.h>
void RandomMovement::Init(Object* obj)
{
	m_owner = obj;
}

void RandomMovement::Update(float dt)
{
	bool is_move_random = false;
	time_t t;
	srand(time(&t));
	m_owner->GetTransform().AddTranslation({ static_cast<float>(rand() % 5 - 2.5), static_cast<float>(rand() % 5 - 2) });

	m_owner->GetMesh().Get_Is_Moved() = true;
	m_owner->Set_Need_Update_Points(true);
	if (m_owner->GetTransform().GetTranslation().x < -500 || m_owner->GetTransform().GetTranslation().x > 500 || m_owner->GetTransform().GetTranslation().y < -150 || m_owner->GetTransform().GetTranslation().y > 550)
	{
		m_owner->GetTransform().SetTranslation({200, 200}); 
		m_owner->GetMesh().Get_Is_Moved() = true;
		m_owner->Set_Need_Update_Points(true);
	}
}