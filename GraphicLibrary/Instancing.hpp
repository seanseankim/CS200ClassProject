//#pragma once
//#include "Component.hpp"
//#include "Shader.hpp"
//#include "Vertices.hpp"
//#include "Material.hpp"
//#include "Image.hpp"
//#include "Texture.hpp"
//#include "ObjectShape.hpp"
//#include "vector2.hpp"
//#include "matrix3.hpp"
//
//class Instancing : public Component
//{
//public:
//	Instancing(Object* obj, bool is_optimized,int amount, ObjectShape objShape, const char* path, vector2<float> position, vector2<float> scale, Color4ub color = { 255,255,255,255 });
//	void Init(Object* obj) override;
//	void Update(float dt) override;
//	bool Can_Load_To_Texture(Texture& texture, const char* file_path);
//	Mesh Helper_make_mesh(ObjectShape objShape, vector2<float> scale, Color4ub color);
//private:
//
//	Shader shader;
//	Vertices shape;
//	material material;
//	Texture texture;
//	Image image;
//
//	float seconds = 1000;
//	float width = 1280, height = 720;
//
//	bool id_optimized = false;
//}