#include "Component_Collision.hpp"
#include "ObjectManager.hpp"


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
	is_collided = false;

	objManager = ObjectManager::GetObjectManager();
	unsigned int number_of_objects = objManager->GetObjectManagerContainer().size();
	for (unsigned int i = 0; i < number_of_objects; ++i)
	{
		Object* obj_i = objManager->GetObjectManagerContainer()[i].get();
		if (obj_i->Get_Need_To_Update())
		{
			for (unsigned int j = 0; j < number_of_objects; ++j)
			{
				Object* obj_j = objManager->GetObjectManagerContainer()[j].get();
				if (obj_j->Get_Need_To_Update() && i != j)
				{
					//vector2<float> obj_i_min = { obj_i->GetTransform().GetTranslation().x - (obj_i->GetTransform().GetScale().x/2), 
					//	obj_i->GetTransform().GetTranslation().y - (obj_i->GetTransform().GetScale().y / 2) };
					//vector2<float> obj_i_max = { obj_i->GetTransform().GetTranslation().x + (obj_i->GetTransform().GetScale().x / 2),
					//	obj_i->GetTransform().GetTranslation().y + (obj_i->GetTransform().GetScale().y / 2) };
					//vector2<float> obj_j_min = { obj_j->GetTransform().GetTranslation().x - (obj_j->GetTransform().GetScale().x / 2),
					//	obj_i->GetTransform().GetTranslation().y - (obj_j->GetTransform().GetScale().y / 2) };
					//vector2<float> obj_j_max = { obj_j->GetTransform().GetTranslation().x + (obj_j->GetTransform().GetScale().x / 2),
					//	obj_i->GetTransform().GetTranslation().y + (obj_j->GetTransform().GetScale().y / 2) };
					//if (obj_i_max.x > obj_j_min.x && obj_i_min.x < obj_j_max.x && obj_i_min.y < obj_j_max.y && obj_j_max.y > obj_j_min.y)
					//{
					//	if (obj_i->GetComponentByTemplate<Collision>() != nullptr && obj_j->GetComponentByTemplate<Collision>() != nullptr)
					//	{
					//		is_collided = true;
					//		
					//	}
					//}
					if(obj_i->GetMesh().GetPoint(2).x < obj_j->GetMesh().GetPoint(2).x && obj_i->GetMesh().GetPoint(1).x > obj_j->GetMesh().GetPoint(1).x 
						&& obj_i->GetMesh().GetPoint(0).y < obj_j->GetMesh().GetPoint(1).y)
						if (obj_i->GetComponentByTemplate<Collision>() != nullptr && obj_j->GetComponentByTemplate<Collision>() != nullptr)
						{
							is_collided = true;

						}
				}
			}
		}
	}
}
