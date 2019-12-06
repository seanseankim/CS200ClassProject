#include <iostream>
#include "demo1.hpp"
#include "Component_Sprite.hpp"
#include "Component_Collision.hpp"
#include "Component_Movement.hpp"
#include "Component_RandomMovement.hpp"
#include "Component_StraightMovement.hpp"
#include "Graphic.hpp"
#include "ObjectManager.hpp"
#include "GL.hpp"

#define BackGround {0,0,0,1}

Demo1* Demo1::demo1 = nullptr;

namespace
{
	ObjectManager* demo1_obj_manager = nullptr;
}

void Demo1::Load()
{
	GL::set_clear_color(BackGround);
	Graphic::GetGraphic()->GetView().GetCameraView().SetZoom(0.7f);

	demo1_obj_manager = ObjectManager::GetObjectManager();
	player = new Object();
	player->AddComponent(new Sprite(player, ObjectShape::SQUARE, "../sprite/mario.png", { -600,-150 }, { 130,100 }));
	player->AddComponent(new Movement);
	player->AddComponent(new Collision);
	player->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(player);


	pipe = new Object();
	pipe->AddComponent(new Sprite(pipe, ObjectShape::RECT, "../sprite/pipe.png", { -350,-130 }, { 160,200 }));
	pipe->AddComponent(new Collision);
	pipe->Set_Tag("pipe2");
	ObjectManager::GetObjectManager()->AddObject(pipe);

	ground = new Object();
	ground->AddComponent(new Sprite(ground, ObjectShape::RECT, "../sprite/undergroundbrickpattern.png", { 0,-400 }, { 2000,350 }));
	ground->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(ground);

	top_ground = new Object();
	top_ground->AddComponent(new Sprite(top_ground, ObjectShape::RECT, "../sprite/undergroundbrickpattern.png", { 0,500 }, { 2000,100 }));
	top_ground->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(top_ground);

	animatedObject = new Object();
	animatedObject->AddComponent(new Sprite(animatedObject, ObjectShape::SQUARE, "../sprite/animatedBoo.png", true, 7, 1.0f,{ 400,200 }, { 100,100 }));
	animatedObject->AddComponent(new RandomMovement);
	animatedObject->Set_Tag("arena"); 
	ObjectManager::GetObjectManager()->AddObject(animatedObject);

	animatedObject_2 = new Object();
	animatedObject_2->AddComponent(new Sprite(animatedObject_2, ObjectShape::SQUARE, "../sprite/animatedBoo.png", true, 7, 5.0f, { 200,200 }, { 100,100 }));
	animatedObject_2->AddComponent(new RandomMovement);
	animatedObject_2->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(animatedObject_2);

	animatedObject_3 = new Object();
	animatedObject_3->AddComponent(new Sprite(animatedObject_3, ObjectShape::SQUARE, "../sprite/animatedBoo.png", true, 7, 50.0f, { 0, 200 }, { 100,100 }));
	animatedObject_3->AddComponent(new RandomMovement);
	animatedObject_3->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(animatedObject_3);

	Object* turtle = new Object();
	turtle->AddComponent(new Sprite(turtle, ObjectShape::SQUARE, "../sprite/animatedTurtle.png", true, 5, 25.0f, { 250,-190 }, { 100,100 }));
	turtle->AddComponent(new StraightMovement);
	turtle->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(turtle);
}
void Demo1::Update(float dt)
{

}

void Demo1::Clear()
{
	unsigned int number_of_objects = demo1_obj_manager->GetObjectManagerContainer().size();
	for (unsigned int i = 0; i < number_of_objects; ++i)
	{
		Object* to_be_deleted = demo1_obj_manager->GetObjectManagerContainer()[i].get();
		to_be_deleted->SetDeadCondition(true);
	}
}