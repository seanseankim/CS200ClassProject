#pragma once

#include "Component.hpp"
#include "Text.hpp"
#include "BitmapFont.hpp"
#include "Mesh.hpp"
#include "StockShaders.hpp"
#include "Graphic.hpp"
#include "Shader.hpp"
#include "Vertices.hpp"
#include "Material.hpp"
#include "Texture.hpp"
#include "Object.hpp"



class TextComp : public Component
{
public:
	TextComp();
	TextComp(Object* obj, std::wstring text_string, Color4f color, vector2<float> size, BitmapFont& font);
	void Init(Object* obj) override;
	void Update(float dt) override;
	Text& GetText();

private:
	BitmapFont      font{};
	Text text{};
	material textMaterial{};
	CameraView      view{};
	Vertices        lineVertices{};
	float seconds = 0;
	float width = 1280;
	float height = 720;
	vector2<float> text_position;
	vector2<float> text_size;
};