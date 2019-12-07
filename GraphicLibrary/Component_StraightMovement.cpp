#include "Component_StraightMovement.hpp"

void StraightMovement::Init(Object* obj)
{
	m_owner = obj;
}

void StraightMovement::Update(float dt)
{
	dt;
	if (m_owner->GetTransform().GetTranslation().x == 0)
	{
		translate = 5.0f;
	}
	if (m_owner->GetTransform().GetTranslation().x == 500)
	{
		translate = -5.0f;
	}

	m_owner->GetTransform().AddTranslation({ translate , 0.0f });
	m_owner->GetMesh().Get_Is_Moved() = true;
	m_owner->Set_Need_Update_Points(true);

}