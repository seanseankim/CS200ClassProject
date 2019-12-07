#pragma once
#include "Component.hpp"
#include "Shader.hpp"
#include "Vertices.hpp"
#include "Material.hpp"
#include "Image.hpp"
#include "Texture.hpp"
#include "ObjectShape.hpp"
#include "vector2.hpp"
#include "matrix3.hpp"

class Sprite : public Component
{
public:
	Sprite(Object* obj, ObjectShape objShape, vector2<float> position, vector2<float> scale, Color4ub color = {255,255,255,255});
	Sprite(Object* obj, ObjectShape objShape, const char* staticSpritePath, vector2<float> position, vector2<float> scale, Color4ub color = { 255,255,255,255 });
	Sprite(Object* obj, const char* aniamtedSpritePath, bool animated, int frames, float m_speed, vector2<float> position, vector2<float> scale, Color4ub color = { 255,255,255,255 });
	void Init(Object* obj) override;
	void Update(float dt) override;
	bool Can_Load_To_Texture(Texture& texture, const char* file_path);
	Mesh Helper_make_mesh(ObjectShape objShape, vector2<float> scale, Color4ub color);
	material& Get_Material()
	{
		return material;
	}
	Vertices& Get_Shape()
	{
		return shape;
	}
	float Get_Width() 
	{
		return width;
	}
	float Get_Height()
	{
		return height;
	}
private:
	Shader shader;
	Vertices shape;
	material material;
	Texture texture;
	Image image;

	float seconds = 1000;
	float width = 1280, height = 720;

	bool is_animated = false;
	int frame = 0;
	float spriteWidth = 0;
	float speed = 1;
};
