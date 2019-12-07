#include <iostream>
#include "Start.hpp"
#include "Graphic.hpp"
#include "Component_Collision.hpp"
#include "Component_Sprite.hpp"
#include "Component_Movement.hpp"
#include "GL.hpp"
#include "Color.cpp"
#include "ObjectShape.hpp"
#include "ObjectManager.hpp"

#define SKY {0.517647088f, 0.611764729f, 0.760784328f, 1}
#define BUTTON {224, 179, 110}
#define MOUNTAIN {20, 130, 36}


Start* Start::start = nullptr;

namespace
{
	ObjectManager* level1_obj_manager = nullptr;
}

void Start::Load()
{
	Graphic::GetGraphic()->GetView().GetCameraView().SetZoom(0.7f);

	level1_obj_manager = ObjectManager::GetObjectManager();

	GL::set_clear_color(SKY);

	mountain = new Object();
	mountain->AddComponent(new Sprite(mountain, ObjectShape::TRIANGLE, { -800, -130 }, { 600,400 }, MOUNTAIN));
	mountain->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(mountain);

	player = new Object();
	player->AddComponent(new Sprite(player, ObjectShape::SQUARE, "../sprite/mario.png", { -400,-150 }, { 130,100 }, BUTTON));
	player->AddComponent(new Movement);
	player->AddComponent(new Collision);
	player->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(player);

	pipe = new Object();
	pipe->AddComponent(new Sprite(pipe, ObjectShape::RECT, "../sprite/pipe.png", { 0,-130 }, { 160,200 }, BUTTON));
	pipe->AddComponent(new Collision);
	pipe->Set_Tag("pipe1");
	ObjectManager::GetObjectManager()->AddObject(pipe);
	
	ground = new Object();
	ground->AddComponent(new Sprite(ground, ObjectShape::RECT, "../sprite/brickpattern.png", { 0,-400 }, { 2000,350 }, BUTTON));
	ground->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(ground);

	sun = new Object();
	sun->AddComponent(new Sprite(sun, ObjectShape::ELLIPSE, { -500,400 }, { 100,300 }, BUTTON));
	sun->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(sun);

	if (!font.LoadFromFile(L"../assets/malgungothic.fnt"))
	{
		std::cout << "Failed to Load Font!" << std::endl;
	}

	
	Object* text = new Object();
	text->SetTranslation({ 0,300 });
	text->AddComponent(new TextComp(text, L"Welcome to my graphic project", { 1,0,0,1 }, {100, 100} , font));
	text->Set_Tag("text");
	ObjectManager::GetObjectManager()->AddObject(text);

	Object* text_2 = new Object();
	text_2->SetTranslation({ 30,50 });
	text_2->AddComponent(new TextComp(text_2, L" This way!", { 1,0,0,1 }, { 100, 100 }, font));
	text_2->Set_Tag("text");
	ObjectManager::GetObjectManager()->AddObject(text_2);

	Object* text_3 = new Object();
	text_3->SetTranslation({ -300,300 });
	text_3->AddComponent(new TextComp(text_3, L" 1", { 1,0,0,1 }, { 100, 100 }, font));
	text_3->Set_Tag("text");
	ObjectManager::GetObjectManager()->AddObject(text_3);
}

void Start::Update(float dt)
{
	dt;
}

void Start::Clear()
{
	unsigned int number_of_objects = static_cast<unsigned int>(level1_obj_manager->GetObjectManagerContainer().size());
	for (unsigned int i = 0; i < number_of_objects; ++i)
	{
		Object* to_be_deleted = level1_obj_manager->GetObjectManagerContainer()[i].get();
		to_be_deleted->SetDeadCondition(true);
	}
}