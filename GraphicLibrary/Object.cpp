#include <algorithm>
#include "Object.hpp"

void Object::AddComponent(Component* comp)
{
	comp->Init(this);
	components_.push_back(comp);
}


void Object::DeleteComponent(Component* comp)
{
	components_.erase(std::find(components_.begin(), components_.end(), comp));
}

void Object::SetTranslation(vector2<float> pos)
{
	m_transform.SetTranslation(pos);
}

void Object::SetRotation(float angle)
{
	m_transform.SetRotation(angle);
}

void Object::SetScale(vector2<float> scale)
{
	m_transform.SetScale(scale);
}

void Object::SetScale(float scale)
{
	m_transform.SetScale(scale);
}

void Object::SetDepth(float depth)
{
	m_transform.SetDepth(depth);
}

void Object::SetMesh(Mesh mesh)
{
	m_mesh = mesh;
}

std::string Object::GetName()
{
	return m_name;
}

bool Object::Get_Need_To_Update()
{
	return need_to_update;
}

Object* Object::Get_Belong_Object_By_Name(std::string name)
{
	if (!belongs_object.empty())
	{
		for (Object* obj : belongs_object)
		{
			if (obj->GetName() == name)
			{
				return obj;
			}
		}
	}
	return nullptr;
}

Object* Object::Get_Belong_Object_By_Tag(std::string n_tag)
{
	if (!belongs_object.empty())
	{
		for (Object* obj : belongs_object)
		{
			if (obj->Get_Tag() == n_tag)
			{
				return obj;
			}
		}
	}
	return nullptr;
}
