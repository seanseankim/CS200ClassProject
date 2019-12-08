/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#pragma once
#include "Vertices.hpp"
#include "Material.hpp"
#include "View.hpp"

class Graphic
{
public:
	static Graphic* GetGraphic();

	void Init();
	void Update(float dt);
	void Draw(Vertices& vertices, material material);

	void Delete();
	View& GetView();

	bool& get_need_update_sprite();

private :
	static Graphic* graphic;
	View view;
	int width = 1280;
	int height = 720;
	float seconds = 0;
	bool need_update_sprite = false;
};