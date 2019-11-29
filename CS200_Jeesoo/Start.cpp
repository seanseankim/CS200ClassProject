#include <iostream>
#include "Start.hpp"
#include "Graphic.hpp"
#include "Component_Collision.hpp"
#include "Component_Sprite.hpp"
#include "Component_Movement.hpp"
#include "Component_Text.hpp"
#include "GL.hpp"
#include "Color.cpp"
#include "ObjectShape.hpp"
#include "ObjectManager.hpp"

#define SKY {0.517647088, 0.611764729, 0.760784328, 1}
#define BUTTON {224, 179, 110}
#define MOUNTAIN {20, 130, 36}

namespace
{
	ObjectManager* level1_obj_manager = nullptr;
}

void Start::Load()
{
	Graphic::GetGraphic()->GetView().GetCameraView().SetZoom(0.7f);

	level1_obj_manager = ObjectManager::GetObjectManager();

	GL::set_clear_color(SKY);

	demo2Button = new Object();
	demo2Button->AddComponent(new Sprite(demo2Button, ObjectShape::TRIANGLE, { -800, -130 }, { 600,400 }, MOUNTAIN));
	demo2Button->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(demo2Button);

	player = new Object();
	player->AddComponent(new Sprite(player, ObjectShape::SQUARE, "../sprite/mario.png", { -500,-150 }, { 130,100 }, BUTTON));
	player->AddComponent(new Movement);
	player->AddComponent(new Collision);
	player->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(player);


	demo1Button = new Object();
	demo1Button->AddComponent(new Sprite(demo1Button, ObjectShape::RECT, "../sprite/pipe.png", { 0,-130 }, { 160,200 }, BUTTON));
	demo1Button->AddComponent(new Collision);
	demo1Button->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(demo1Button);
	

	demo3Button = new Object();
	demo3Button->AddComponent(new Sprite(demo3Button, ObjectShape::RECT, "../sprite/brickpattern.png", { 0,-400 }, { 2000,350 }, BUTTON));
	demo3Button->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(demo3Button);

	demo4Button = new Object();
	demo4Button->AddComponent(new Sprite(demo4Button, ObjectShape::RECT, "../sprite/pipe.png", { 800,-130 }, { 160,200 }, BUTTON));
	demo4Button->AddComponent(new Collision);
	demo4Button->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(demo4Button);

	demo5Button = new Object();
	demo5Button->AddComponent(new Sprite(demo5Button, ObjectShape::RECT, "../sprite/pipe.png", { 400,-130 }, { 160,200 }, BUTTON));
	demo5Button->AddComponent(new Collision);
	demo5Button->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(demo5Button);

	demo6Button = new Object();
	demo6Button->AddComponent(new Sprite(demo6Button, ObjectShape::ELLIPSE, { -500,400 }, { 100,300 }, BUTTON));
	demo6Button->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(demo6Button);

	/*Object* text1 = new Object();
	text1->AddComponent(new Sprite(text1, ObjectShape::RECT, { 0,130 }, { 130,50 }, { 255,0,0,255 }));
	text1->AddComponent(new TextComp(text1, L"Demo 1", { 0,0,0,1 }, { 30,30 }));
	text1->Set_Tag("text");
	ObjectManager::GetObjectManager()->AddObject(text1);*/
}

void Start::Update(float dt)
{
	//cout << "At the menu!\n";
}