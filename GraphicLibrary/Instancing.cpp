/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
//#include "Instancing.hpp"
//#include "Mesh.hpp"
//#include <GL/glew.h>
//#include "StockShaders.hpp"
//#include "Graphic.hpp"
//#include "Object.hpp"
//#include <string>
//
//bool Instancing::Can_Load_To_Texture(Texture& texture, const char* file_path)
//{
//	const bool is_okay = texture.LoadFromPNG(file_path);
//	if (!is_okay)
//	{
//		//std::cerr << "Failed to load \"" << file_path << "\"\n";
//	}
//	return is_okay;
//}
//
//void Instancing::Init(Object* obj)
//{
//	m_owner = obj;
//}
//
//Mesh Instancing::Helper_make_mesh(ObjectShape objShape, vector2<float> scale, Color4ub color)
//{
//	Mesh newMesh;
//	if (objShape == ObjectShape::SQUARE)
//	{
//		newMesh = MESH::create_box(scale.x, color);
//	}
//	else if (objShape == ObjectShape::RECT)
//	{
//		newMesh = MESH::create_rectangle(scale.x, scale.y, color);
//	}
//	else if (objShape == ObjectShape::CIRCLE)
//	{
//		newMesh = MESH::create_circle(scale.x, color);
//	}
//	else if (objShape == ObjectShape::ELLIPSE)
//	{
//		newMesh = MESH::create_ellipse(scale.x, color);
//	}
//	else if (objShape == ObjectShape::TRIANGLE)
//	{
//		newMesh = MESH::create_triangle({ 0,0 }, { 1,0 }, scale, color);
//	}
//	else
//	{
//		newMesh = MESH::create_line({ 0,0 }, { 1,0 }, scale, color);
//	}
//	return newMesh;
//}
//
//Instancing::Instancing(Object* obj, bool optimize_flag, int amount, ObjectShape objShape, const char* path,  vector2<float> position, vector2<float> scale, Color4ub color)
//{
//	m_owner = obj;
//
//	if (!optimize_flag)
//		amount = 10000;
//
//	matrix3<float>* mat_ndc = new matrix3<float>[amount];
//	int index = 0;
//
//	matrix3<float> transform = Graphic::GetGraphic()->GetView().GetCameraView().GetCameraToNDCTransform();
//	transform *= Graphic::GetGraphic()->GetView().GetCamera().WorldToCamera();
//	transform *= m_owner->GetTransform().GetModelToWorld();
//
//	material.shader = &(SHADER::textured());	
//	if (!Can_Load_To_Texture(texture, path))
//	{
//
//	}
//	texture.SelectTextureForSlot(texture);
//	material.textureUniforms["texture_to_sample"] = { &(texture) };
//	material.color4fUniforms["color"] = { 1.0f };
//
//	for (int j = -(amount / 10); j < (amount / 10); j++)
//	{
//		for (int i = -(amount / 10); i < (amount / 10); i++)
//		{
//			Mesh square;
//			Mesh newMesh = Helper_make_mesh(objShape, scale, color);
//			shape.InitializeWithMeshAndLayout(square, SHADER::textured_vertex_layout());
//			mat_ndc[index] = transform * MATRIX3::build_translation(static_cast<float>(i), static_cast<float>(j));
//			material.matrix3Uniforms["to_ndc"] = mat_ndc[index];
//			m_owner->SetMesh(square);
//			Graphic::GetGraphic()->Draw(shape, material);
//			index++;
//		}
//	}
//}
//
//
//
//
//void Instancing::Update(float dt)
//{
//
//}
