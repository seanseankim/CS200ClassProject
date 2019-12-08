/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#include <iostream>
#include "demo2.hpp"
#include "Component_Sprite.hpp"
#include "Component_Collision.hpp"
#include "Component_Movement.hpp"
#include "Component_RandomMovement.hpp"
#include "Component_StraightMovement.hpp"
#include "Graphic.hpp"
#include "ObjectManager.hpp"
#include "Instancing.hpp"
#include "GL.hpp"

#define BACKGROUND {0,0,0,1}

Demo2* Demo2::demo2 = nullptr;

namespace
{
	ObjectManager* demo2_obj_manager = nullptr;
}

void Demo2::Load()
{
	GL::set_clear_color(BACKGROUND);
	Graphic::GetGraphic()->GetView().GetCameraView().SetZoom(0.7f);

	demo2_obj_manager = ObjectManager::GetObjectManager();

	player = new Object();
	player->AddComponent(new Sprite(player, demo2_obj_manager, ObjectShape::SQUARE, true, "../sprite/mario.png", { -600,-150 }, { 130,100 }));
	player->AddComponent(new Movement);
	player->AddComponent(new Collision);
	player->Set_Tag("arena");
	demo2_obj_manager->AddObject(player);

	ground = new Object();
	ground->AddComponent(new Sprite(ground, ObjectShape::RECT, "../sprite/bossbrickpattern.png", { 0,-400 }, { 2000,350 }));
	ground->Set_Tag("arena");
	demo2_obj_manager->AddObject(ground);

	ground_1 = new Object();
	ground_1->AddComponent(new Sprite(ground_1, ObjectShape::RECT, "../sprite/bossbrickpattern.png", { -900,400 }, { 100,200 }));
	ground_1->Set_Tag("arena");
	demo2_obj_manager->AddObject(ground_1);

	ground_2 = new Object();
	ground_2->AddComponent(new Sprite(ground_2, ObjectShape::RECT, "../sprite/bossbrickpattern.png", { 900,400 }, { 100,200 }));
	ground_2->Set_Tag("arena");
	demo2_obj_manager->AddObject(ground_2);

	top_ground = new Object();
	top_ground->AddComponent(new Sprite(top_ground, ObjectShape::RECT, "../sprite/bossbrickpattern.png", { 0,500 }, { 2000,100 }));
	top_ground->Set_Tag("arena");
	demo2_obj_manager->AddObject(top_ground);


	bowser = new Object();
	bowser->AddComponent(new Sprite(bowser,"../sprite/animatedBowser.png", true, 6, 10.0f, { 800,-130 }, { 200,200 }));
	bowser->Set_Tag("arena");
	demo2_obj_manager->AddObject(bowser);

	pipe = new Object();
	pipe->AddComponent(new Sprite(pipe, ObjectShape::RECT, "../sprite/pipe.png", { -350,-130 }, { 160,200 }));
	pipe->AddComponent(new Collision);
	pipe->Set_Tag("pipe3");
	demo2_obj_manager->AddObject(pipe);


	if (!font.LoadFromFile(L"../assets/malgungothic.fnt"))
	{
		std::cout << "Failed to Load Font!" << std::endl;
	}

	Object* text_1 = new Object();
	text_1->SetTranslation({ -800,400 });
	text_1->AddComponent(new TextComp(text_1, L"LEVEL : 3", { 1,1,1,1 }, { 100, 100 }, font));
	text_1->Set_Tag("text");
	demo2_obj_manager->AddObject(text_1);

}
void Demo2::Update(float dt) 
{
	dt;
}

void Demo2::Clear()
{
	unsigned int number_of_objects = static_cast<unsigned int>(demo2_obj_manager->GetObjectManagerContainer().size());
	for (unsigned int i = 0; i < number_of_objects; ++i)
	{
		Object* to_be_deleted = demo2_obj_manager->GetObjectManagerContainer()[i].get();
		to_be_deleted->SetDeadCondition(true);
	}

}