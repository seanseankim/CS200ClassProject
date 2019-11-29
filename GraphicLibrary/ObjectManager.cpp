#include <functional>
#include "StateManager.hpp"
#include "ObjectManager.hpp"
#include <iostream>

ObjectManager* ObjectManager::object_manager = nullptr;

ObjectManager* ObjectManager::GetObjectManager()
{
	if (object_manager == nullptr)
		object_manager = new ObjectManager();

	return object_manager;
}

void ObjectManager::Init()
{
	objects.clear();
	delete_obj.clear();
}

void ObjectManager::Update(float dt)
{
	if (StateManager::GetStateManager()->is_pause)//
	{
		delete_obj.clear();

		for (auto& obj : objects)
		{
			if (obj->Get_Need_To_Update())
			{
				for (auto component : obj->GetComponentContainer())
				{
					component->Update(dt);
				}
			}
			if (obj->IsDead())
				delete_obj.push_back(obj);
		}
		for (auto& remove_obj : delete_obj)
		{
			DeleteObject(remove_obj);
		}
	}
	else
	{

	}
}

void ObjectManager::Delete()
{
	objects.clear();
	delete_obj.clear();

	delete object_manager;
	object_manager = nullptr;
}

void ObjectManager::Clear()
{
	objects.clear();
	delete_obj.clear();
}

void ObjectManager::AddObject(Object* obj)
{
	objects.push_back(std::shared_ptr<Object>(obj));
}

void ObjectManager::DeleteObject(std::shared_ptr<Object> obj)
{
	objects.erase(std::find(objects.begin(), objects.end(), obj));
}

std::vector<Object*> ObjectManager::Find_Objects_By_Tag(std::string tag)
{
	std::vector<Object*> objects_have_tag;

	for (auto object : objects)
	{
		if (object.get()->Get_Tag() == tag)
		{
			objects_have_tag.push_back(object.get());
		}
	}

	return objects_have_tag;
}

Object* ObjectManager::Find_Object_By_Name(std::string name)
{
	for (auto object : objects)
	{
		if (object.get()->GetName() == name)
		{
			return object.get();
		}
	}
	return nullptr;
}

