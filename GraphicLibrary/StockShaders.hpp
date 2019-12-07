#pragma once

#include "Shader.hpp"
#include "VertexLayoutDescription.hpp"


namespace SHADER
{
	Shader& solid_color() noexcept;
	const VertexLayoutDescription& solid_color_vertex_layout() noexcept;

	Shader& interpolated_colors() noexcept;
	const VertexLayoutDescription& interpolated_colors_vertex_layout() noexcept;

	Shader& textured() noexcept;
	const VertexLayoutDescription& textured_vertex_layout() noexcept;

	Shader& instancing() noexcept;
	const VertexLayoutDescription& instanced_vertex_layout() noexcept;

	constexpr const char* Uniform_ToNDC = "to_ndc";
	constexpr const char* Uniform_Depth = "depth";
	constexpr const char* Uniform_Color = "color";
	constexpr const char* Uniform_Texture = "texture_to_sample";
};

#include "StockShaders.inl"
