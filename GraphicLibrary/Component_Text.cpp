#include <GL/glew.h>
#include <iostream>
#include "Component_Text.hpp"

TextComp::TextComp(Object* obj, std::wstring text_string, Color4f color, vector2<float> size) {


	view.SetViewSize(width, height);
	textMaterial.shader = &SHADER::textured();
	textMaterial.color4fUniforms[SHADER::Uniform_Color] = color;
	textMaterial.floatUniforms[SHADER::Uniform_Depth] = 0.0f;
	if (!font.LoadFromFile(L"../assets/malgungothic.fnt"))
	{
		std::cout << "Failed to Load Font!" << std::endl;
	}
	Mesh square;
	square = MESH::create_box(size.x, { 100,100,100,255 });
	lineVertices.InitializeWithMeshAndLayout(square, SHADER::textured_vertex_layout());
	m_owner = obj;
	m_owner->SetMesh(square);
	m_owner->Get_Object_Points() = m_owner->GetMesh().Get_Points();

	int size_for_normal = m_owner->GetMesh().Get_Points().size();

	m_owner->Set_Center({ 0.0f , 0.0f });
	text_size = size;
	text.SetFont(font);
	text.SetString(text_string);
	text_position = m_owner->GetTransform().GetTranslation();
}

void TextComp::Init(Object* obj)
{
	m_owner = obj;
}

void TextComp::Update(float dt)
{
	const float left = -width * 0.5f + m_owner->GetTransform().GetTranslation().x;
	const float top = height * 0.5f - m_owner->GetTransform().GetTranslation().y;


	textMaterial.matrix3Uniforms[SHADER::Uniform_ToNDC] =
		view.GetCameraToNDCTransform() * MATRIX3::build_translation(left, top);
	for (auto& vertices_texture_pair : text.GetVerticesWithMatchingTextures())
	{
		Vertices& text_vertices = *vertices_texture_pair.first;
		const Texture* text_texture = vertices_texture_pair.second;
		textMaterial.textureUniforms.insert_or_assign(SHADER::Uniform_Texture, texture_uniform{ text_texture });
		Graphic::GetGraphic()->Draw(text_vertices, textMaterial);
	}
	textMaterial.floatUniforms["time"] = seconds;
}
