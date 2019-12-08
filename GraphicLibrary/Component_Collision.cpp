/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#include "Component_Collision.hpp"
#include "ObjectManager.hpp"
#include "StateManager.hpp"
#include "State.hpp"
#include "../CS200_Jeesoo/Start.hpp"
#include "../CS200_Jeesoo/Demo1.hpp"
#include "../CS200_Jeesoo/Demo2.hpp"


namespace
{
	ObjectManager* objManager = nullptr;
}

void Collision::Init(Object* obj)
{
	m_owner = obj;
}

void Collision::Update(float dt)
{
	dt;
	is_collided = false;

	objManager = ObjectManager::GetObjectManager();
	unsigned int number_of_objects = static_cast<unsigned int>(objManager->GetObjectManagerContainer().size());
	for (unsigned int i = 0; i < number_of_objects; ++i)
	{
		Object* obj_i = objManager->GetObjectManagerContainer()[i].get();
		if (obj_i->Get_Need_To_Update())
		{
			for (unsigned int j = 0; j < number_of_objects; ++j)
			{
				Object* obj_j = objManager->GetObjectManagerContainer()[j].get();
				if (obj_j->Get_Need_To_Update() && obj_i != obj_j)
				{
					if ((obj_j->GetTransform().GetTranslation().x - 20 <= obj_i->GetTransform().GetTranslation().x) && (obj_i->GetTransform().GetTranslation().x <= obj_j->GetTransform().GetTranslation().x + 20) /*&& (obj_i->GetTransform().GetTranslation().y <= obj_j->GetTransform().GetTranslation().y)*/)
					{
						if (obj_j->GetTransform().GetTranslation().y == obj_i->GetTransform().GetTranslation().y - 80)
						{
							if (obj_i->GetComponentByTemplate<Collision>() != nullptr && obj_j->GetComponentByTemplate<Collision>() != nullptr)
							{
								if (obj_i->Get_Tag() == "pipe1" || obj_j->Get_Tag() == "pipe1")
								{
									//load demo1
									is_collided = true;

									StateManager::GetStateManager()->Get_current_state().Get_is_next() = true;
									StateManager::GetStateManager()->Get_current_state().Get_next_level() = "Demo1";
									Start::Get_Start()->Clear();
									return;
										
								}
								if (obj_i->Get_Tag() == "pipe2" || obj_j->Get_Tag() == "pipe2")
								{
									//load demo2
									is_collided = true;

									StateManager::GetStateManager()->Get_current_state().Get_is_next() = true;
									StateManager::GetStateManager()->Get_current_state().Get_next_level() = "Demo2";
									Demo1::Get_Demo1()->Clear();
									return;
								}
								if (obj_i->Get_Tag() == "pipe3" || obj_j->Get_Tag() == "pipe3")
								{
									//load demo2
									is_collided = true;

									StateManager::GetStateManager()->Get_current_state().Get_is_next() = true;
									StateManager::GetStateManager()->Get_current_state().Get_next_level() = "Start";
									Demo2::Get_Demo2()->Clear();
									return;
								}
							}
						}
					}
				}
			}
		}
	}
}
