#include <iostream>
#include "demo2.hpp"
#include "Component_Sprite.hpp"
#include "Component_Collision.hpp"
#include "Component_Movement.hpp"
#include "Component_RandomMovement.hpp"
#include "Component_StraightMovement.hpp"
#include "Graphic.hpp"
#include "ObjectManager.hpp"
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
	player->AddComponent(new Sprite(player, ObjectShape::SQUARE, "../sprite/mario.png", { -600,-150 }, { 130,100 }));
	player->AddComponent(new Movement);
	player->AddComponent(new Collision);
	player->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(player);

	bowser = new Object();
	bowser->AddComponent(new Sprite(bowser, ObjectShape::SQUARE, "../sprite/animatedBowser.png", true, 6, 10.0f, { 800,-130 }, { 200,200 }));
	bowser->Set_Tag("arena");
	ObjectManager::GetObjectManager()->AddObject(bowser);

	pipe = new Object();
	pipe->AddComponent(new Sprite(pipe, ObjectShape::RECT, "../sprite/pipe.png", { -350,-130 }, { 160,200 }));
	pipe->AddComponent(new Collision);
	pipe->Set_Tag("pipe2");
	ObjectManager::GetObjectManager()->AddObject(pipe);

}
void Demo2::Update(float dt) 
{

}

void Demo2::Clear()
{

}