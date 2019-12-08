/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#include "Graphic.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GL.hpp"

Graphic* Graphic::graphic = nullptr;

void Graphic::Init()
{
	glewInit();
	glEnable(GL_DEPTH | GL_BLEND);
	view.Init();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Graphic::Update(float dt)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	seconds += dt;
	view.Update(dt);
}

void Graphic::Draw(Vertices& shape, material material)
{
	GL::draw(shape, material);
	GL::end_drawing();
}


void Graphic::Delete()
{
	graphic = nullptr;
}


View& Graphic::GetView()
{
	return view;
}

Graphic* Graphic::GetGraphic()
{
	if (graphic == nullptr)
		graphic = new Graphic();

	return graphic;
}

bool& Graphic::get_need_update_sprite()
{
	return need_update_sprite;
}
