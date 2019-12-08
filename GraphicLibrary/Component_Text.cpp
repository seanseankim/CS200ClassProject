/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#include <GL/glew.h>
#include <iostream>
#include "Component_Text.hpp"
#include "GL.hpp"

TextComp::TextComp(Object* obj, std::wstring text_string, Color4f color, vector2<float> size, BitmapFont& font)
{

	m_owner = obj;


	textMaterial.shader = &SHADER::textured();
	textMaterial.color4fUniforms[SHADER::Uniform_Color] = color;

	text_size = size;
	text.SetFont(font);
	text.SetString(text_string);
	const float left = -width * 0.5f + m_owner->GetTransform().GetTranslation().x;
	const float top = height * 0.5f - m_owner->GetTransform().GetTranslation().y;

	matrix3<float> mat_ndc = Graphic::GetGraphic()->GetView().GetCameraView().GetCameraToNDCTransform();
	mat_ndc *= Graphic::GetGraphic()->GetView().GetCamera().WorldToCamera();
	mat_ndc *= m_owner->GetTransform().GetModelToWorld();
	textMaterial.matrix3Uniforms["to_ndc"] =
		mat_ndc * MATRIX3::build_scale(size.x / 100.0f, size.y / 100.0f);

	for (auto& vertices_texture_pair : text.GetVerticesWithMatchingTextures())
	{
		Vertices& text_vertices = *vertices_texture_pair.first;
		const Texture* text_texture = vertices_texture_pair.second;
		textMaterial.textureUniforms.insert_or_assign(SHADER::Uniform_Texture, texture_uniform{ text_texture });
		Graphic::GetGraphic()->Draw(text_vertices, textMaterial);
	}
}

void TextComp::Init(Object* obj)
{
	m_owner = obj;
}

void TextComp::Update(float dt)
{
	dt;
	const float left = -width * 0.5f + m_owner->GetTransform().GetTranslation().x;
	const float top = height * 0.5f - m_owner->GetTransform().GetTranslation().y;

	matrix3<float> mat_ndc = Graphic::GetGraphic()->GetView().GetCameraView().GetCameraToNDCTransform();
	mat_ndc *= Graphic::GetGraphic()->GetView().GetCamera().WorldToCamera();
	mat_ndc *= m_owner->GetTransform().GetModelToWorld();
	textMaterial.matrix3Uniforms["to_ndc"] =
		mat_ndc * MATRIX3::build_scale(text_size.x / 100.0f, text_size.y / 100.0f);

	for (auto& vertices_texture_pair : text.GetVerticesWithMatchingTextures())
	{
		Vertices& text_vertices = *vertices_texture_pair.first;
		const Texture* text_texture = vertices_texture_pair.second;
		textMaterial.textureUniforms.insert_or_assign(SHADER::Uniform_Texture, texture_uniform{ text_texture });
		Graphic::GetGraphic()->Draw(text_vertices, textMaterial);
	}
}

Text& TextComp::GetText()
{
	return text;
}