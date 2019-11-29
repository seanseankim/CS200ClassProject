#pragma once

#include <string>
#include <unordered_map>
#include "Vertices.hpp"
#include "Texture.hpp"
#include "Component_Sprite.hpp"
#include "CameraView.hpp"
#include "BitmapFont.hpp"

class CameraView;
class Transform;
class BitmapFont;
class Color4f;

class [[nodiscard]] Text
{
public:
	Text() noexcept = default;
	Text(std::wstring text_string, const BitmapFont & text_font) noexcept;

	std::vector<std::pair<Vertices*, const Texture*>> GetVerticesWithMatchingTextures() const noexcept;
	std::wstring                                            GetString() const noexcept;
	void                                                    SetString(const std::wstring & text_string) noexcept;
	const BitmapFont* GetFont() const noexcept;
	void                                                    SetFont(const BitmapFont & text_font) noexcept;

private:
	void InitializeWithEmptyVertices() const noexcept;
	void BuildNewMeshesIfNeeded() const noexcept;

private:
	std::wstring                              string{};
	const BitmapFont* font = nullptr;
	mutable std::unordered_map<int, Vertices> vertices{};
	mutable bool                              needNewMeshes = true;
	material textMaterial{};
	vector2<float> position;
	CameraView view{};
	float width = 1280, height = 720;
};

