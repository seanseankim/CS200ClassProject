/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#include <iostream>
#include "Mesh.hpp"
#include "StockShaders.hpp"
#include "Text.hpp"

Text::Text(std::wstring text_string, const BitmapFont& text_font) noexcept
{
	string = text_string;
	font = &text_font;
	InitializeWithEmptyVertices();
}

std::vector<std::pair<Vertices*, const Texture*>> Text::GetVerticesWithMatchingTextures() const noexcept
{
	std::vector<std::pair<Vertices*, const Texture*>> newMesh;

	for (int i = 0; i < font->GetInformation().pagesCount; i++)
	{
		std::pair pairVerticesTexture(&vertices.at(i), &font->GetTexture(i));
		newMesh.push_back(pairVerticesTexture);
	}
	return newMesh;
}

std::wstring Text::GetString() const noexcept
{
	return string;
}

void Text::SetString(const std::wstring& text_string) noexcept
{
	if (text_string.compare(string))
	{
		string = text_string;
		needNewMeshes = true;
		BuildNewMeshesIfNeeded();
	}
}

const BitmapFont* Text::GetFont() const noexcept
{
	return font;
}

void Text::SetFont(const BitmapFont& text_font) noexcept
{
	vertices.clear();
	font = &text_font;
	needNewMeshes = true;
}

void Text::InitializeWithEmptyVertices() const noexcept
{
	Mesh mesh;
	for (int i = 0; i < font->GetInformation().pagesCount; i++)
	{
		vertices.insert_or_assign(font->GetInformation().pagesCount,
			Vertices(mesh, SHADER::textured_vertex_layout()));
	}
}

void Text::BuildNewMeshesIfNeeded() const noexcept
{
	if (!needNewMeshes)
		return;

	const BitmapFont::information& information = font->GetInformation();

	for (int i = 0; i < information.pagesCount; ++i)
	{
		Mesh     new_mesh;
		Vertices vertice;
		std::pair<int, int>  cursor{ 0 , 0};
		for (const auto& content : string)
		{
			const BitmapFont::character& character = font->GetCharacter(content);
			new_mesh.SetPointListType(PointListPattern::Triangles);
			if (character.page == i)
			{
				float left = static_cast<float>(character.xOffset) + static_cast<float>(cursor.first);
				float bottom = static_cast<float>((character.yOffset + character.height) * -1 + font->GetLineHeight()) + static_cast<float>(cursor.second);
				float right = static_cast<float>(left) + static_cast<float>(character.width);
				float top = static_cast<float>(bottom) + static_cast<float>(character.height);

				float left_u_vec = static_cast<float>(character.x) / static_cast<float>(information.imageWidth);
				float right_u_vec = static_cast<float>(character.x + character.width) / static_cast<float>(information.imageWidth);
				float top_v_vec = static_cast<float>(character.y) / static_cast<float>(information.imageHeight);
				float bottom_v_vec = static_cast<float>(character.y + character.height) / static_cast<float>(information.imageHeight);

				new_mesh.AddPoint(vector2{ left, top });
				new_mesh.AddPoint(vector2{ right, top });
				new_mesh.AddPoint(vector2{ left, bottom });
				new_mesh.AddPoint(vector2{ right, top });
				new_mesh.AddPoint(vector2{ left, bottom });
				new_mesh.AddPoint(vector2{ right, bottom });

				new_mesh.AddTextureCoordinate(vector2{ left_u_vec, top_v_vec });
				new_mesh.AddTextureCoordinate(vector2{ right_u_vec, top_v_vec });
				new_mesh.AddTextureCoordinate(vector2{ left_u_vec, bottom_v_vec });
				new_mesh.AddTextureCoordinate(vector2{ right_u_vec, top_v_vec });
				new_mesh.AddTextureCoordinate(vector2{ left_u_vec, bottom_v_vec });
				new_mesh.AddTextureCoordinate(vector2{ right_u_vec, bottom_v_vec });

				cursor.first += character.xAdvance;
			}

			else if (content == L' ')
			{
				if (font->HasCharacter(wchar_t(' ')))
				{
					cursor.first += character.xAdvance;
				}
				else
				{
					cursor.first += information.fontSize;
				}
			}

			else if (content == L'\n')
			{
				cursor.first = 0;
				cursor.second -= information.lineHeight;
			}
			
			else
			{
				cursor.first += character.xAdvance;
			}
		}
		vertice.InitializeWithMeshAndLayout(new_mesh, SHADER::textured_vertex_layout());
		vertices.insert_or_assign(i, std::move(vertice));
	}
	needNewMeshes = false;
}





