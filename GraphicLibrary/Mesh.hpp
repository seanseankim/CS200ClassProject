/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#pragma once
#include "Color4ub.hpp"
#include "vector2.hpp"
#include <cstddef>
#include <vector>


enum class [[nodiscard]] PointListPattern
{
	Lines, LineStrip, LineLoop, Triangles, TriangleStrip, TriangleFan
};

class [[nodiscard]] Mesh
{
public:
	std::size_t GetPointCount() const noexcept;
	vector2<float> GetPoint(std::size_t index) const noexcept;
	Color4ub GetColor(std::size_t index = 0) const noexcept;
	vector2<float> GetTextureCoordinate(std::size_t index) const
	noexcept;
	vector2<int> GetCenterPoint() const noexcept;

	PointListPattern GetPointListPattern() const noexcept;
	void             SetPointListType(PointListPattern type) noexcept;

	void AddColor(Color4ub color) noexcept;
	void AddPoint(vector2<float> point) noexcept;
	void AddTextureCoordinate(vector2<float> texture_coordinate) noexcept;

	void ClearColors() noexcept;
	bool HasMoreThanOneColor() const noexcept;

	void ClearTextureCoordinates() noexcept;
	void ClearPoints() noexcept;
	void Clear() noexcept;
	std::vector<vector2<float>>& Get_Points();

	bool& Get_Is_Moved()
	{
		return is_moved;
	}

private:
	std::vector<vector2<float>>  points{};
	std::vector<Color4ub> colors{};
	std::vector<vector2<float>>  textureCoordinates{};
	PointListPattern      pointListType = PointListPattern::Lines;
	bool is_moved = false;
};

namespace MESH
{
	Mesh create_circle(float radius = 1, Color4ub color = Color4ub{ 255 }, std::size_t point_count = 30) noexcept;
	Mesh create_ellipse(float radius = 1, Color4ub color = Color4ub{ 255 }, std::size_t point_count = 30) noexcept;
	Mesh create_wire_circle(float radius = 1, Color4ub color = Color4ub{ 255 },
		std::size_t point_count = 30) noexcept;
	Mesh create_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_wire_rectangle(float width = 1, float height = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_wire_box(float dimension = 1, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_line(vector2<float> a = { 0, 0 }, vector2<float> b = { 1, 0 }, vector2<float> scale = { 1,1 }, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_triangle(vector2<float> scale = { 1,1 }, Color4ub color = Color4ub{ 255 }) noexcept;
	Mesh create_quad(vector2<float> point_1, vector2<float> point_2, vector2<float> point_3, vector2<float> point_4, Color4ub color = Color4ub{ 255 });
}