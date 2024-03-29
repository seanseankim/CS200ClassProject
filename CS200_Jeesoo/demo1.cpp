/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
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
	player->AddComponent(new Sprite(player, demo1_obj_manager,ObjectShape::SQUARE, true, "../sprite/mario.png", { -600,-150 }, { 130,100 }));
	player->AddComponent(new Movement);
	player->AddComponent(new Collision);
	player->Set_Tag("arena");
	demo1_obj_manager->AddObject(player);


	pipe = new Object();
	pipe->AddComponent(new Sprite(pipe, ObjectShape::RECT, "../sprite/pipe.png", { -350,-130 }, { 160,200 }));
	pipe->AddComponent(new Collision);
	pipe->Set_Tag("pipe2");
	demo1_obj_manager->AddObject(pipe);

	ground = new Object();
	ground->AddComponent(new Sprite(ground, ObjectShape::RECT, "../sprite/undergroundbrickpattern.png", { 0,-400 }, { 2000,350 }));
	ground->Set_Tag("arena");
	demo1_obj_manager->AddObject(ground);

	top_ground = new Object();
	top_ground->AddComponent(new Sprite(top_ground, ObjectShape::RECT, "../sprite/undergroundbrickpattern.png", { 0,500 }, { 2000,100 }));
	top_ground->Set_Tag("arena");
	demo1_obj_manager->AddObject(top_ground);

	ground_1 = new Object();
	ground_1->AddComponent(new Sprite(ground_1, ObjectShape::RECT, "../sprite/undergroundbrickpattern.png", { 200,150 }, { 400,100 }));
	ground_1->Set_Tag("arena");
	demo1_obj_manager->AddObject(ground_1);

	animatedObject = new Object();
	animatedObject->AddComponent(new Sprite(animatedObject,"../sprite/animatedBoo.png", true, 7, 1.0f,{ 400,200 }, { 100,100 }));
	animatedObject->AddComponent(new RandomMovement);
	animatedObject->Set_Tag("arena"); 
	demo1_obj_manager->AddObject(animatedObject);

	animatedObject_2 = new Object();
	animatedObject_2->AddComponent(new Sprite(animatedObject_2, "../sprite/animatedBoo.png", true, 7, 5.0f, { 200,200 }, { 100,100 }));
	animatedObject_2->AddComponent(new RandomMovement);
	animatedObject_2->Set_Tag("arena");
	demo1_obj_manager->AddObject(animatedObject_2);

	animatedObject_3 = new Object();
	animatedObject_3->AddComponent(new Sprite(animatedObject_3, "../sprite/animatedBoo.png", true, 7, 100.0f, { 0, 200 }, { 100,100 }));
	animatedObject_3->AddComponent(new RandomMovement);
	animatedObject_3->Set_Tag("arena");
	demo1_obj_manager->AddObject(animatedObject_3);

	turtle = new Object();
	turtle->AddComponent(new Sprite(turtle, "../sprite/animatedTurtle.png", true, 5, 25.0f, { 250,-190 }, { 100,100 }));
	turtle->AddComponent(new StraightMovement);
	turtle->Set_Tag("arena");
	demo1_obj_manager->AddObject(turtle);


	if (!font.LoadFromFile(L"../assets/malgungothic.fnt"))
	{
		std::cout << "Failed to Load Font!" << std::endl;
	}

	Object* text_1 = new Object();
	text_1->SetTranslation({ -800,400 });
	text_1->AddComponent(new TextComp(text_1, L"LEVEL : 2", {1,1,1,1}, { 100, 100 }, font));
	text_1->Set_Tag("text");
	demo1_obj_manager->AddObject(text_1);

}
void Demo1::Update(float dt)
{
	dt;
}

void Demo1::Clear()
{
	unsigned int number_of_objects = static_cast<unsigned int>(demo1_obj_manager->GetObjectManagerContainer().size());
	for (unsigned int i = 0; i < number_of_objects; ++i)
	{
		Object* to_be_deleted = demo1_obj_manager->GetObjectManagerContainer()[i].get();
		to_be_deleted->SetDeadCondition(true);
	}
}