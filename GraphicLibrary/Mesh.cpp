/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#include "Mesh.hpp"
#include "angles.hpp"
#include <cmath>

namespace MESH
{
	Mesh create_circle(float radius, Color4ub color, std::size_t point_count) noexcept
	{
		Mesh circle;
		int angle = static_cast<int>(360 / point_count);

		circle.AddPoint({});
		for (int i = 0; i <= 360; i += angle)
		{
			circle.AddPoint({ static_cast<float>(radius * sin(i * PI / 180.0f)),
							 static_cast<float>(-radius * cos(i * PI / 180.0f)) });
		}
		circle.AddColor(color);
		circle.SetPointListType(PointListPattern::TriangleFan);
		return circle;
	}
	Mesh create_ellipse(float radius, Color4ub color, std::size_t point_count) noexcept
	{
		Mesh ellipse;
		int angle = static_cast<int>(360 / point_count);

		ellipse.AddPoint({});
		for (int i = 0; i <= 360; i += angle)
		{
			ellipse.AddPoint({ static_cast<float>(radius * sin(i * PI / 180.0f)),
							 static_cast<float>(-radius * cos(i * PI / 180.0f) / 2) });
		}
		ellipse.AddColor(color);
		ellipse.SetPointListType(PointListPattern::TriangleFan);
		return ellipse;
	}
	Mesh create_wire_circle(float radius, Color4ub color, std::size_t point_count) noexcept
	{
		Mesh circle;
		int  angle = static_cast<int> (360 / point_count);

		for (int i = 0; i <= 360.0; i += angle)
		{
			circle.AddPoint({ static_cast<float>(radius * sin(i * PI / 180.0f)),
							 static_cast<float>(-radius * cos(i * PI / 180.0f)) });
		}
		circle.AddColor(color);
		circle.SetPointListType(PointListPattern::LineLoop);
		return circle;

	}
	Mesh create_box(float dimension, Color4ub color) noexcept
	{
		Mesh box;

		vector2<float> pos(dimension / 2);

		box.AddPoint({ -pos.x, -pos.y });
		box.AddPoint({ -pos.x, pos.y });
		box.AddPoint({ pos.x, pos.y });
		box.AddPoint({ pos.x, -pos.y });

		box.AddColor(color);

		box.AddTextureCoordinate({ 0, 1 });
		box.AddTextureCoordinate({ 0, 0 });
		box.AddTextureCoordinate({ 1, 0 });
		box.AddTextureCoordinate({ 1, 1 });


		box.SetPointListType(PointListPattern::TriangleFan);

		return box;
	}
	Mesh create_rectangle(float width, float height, Color4ub color) noexcept
	{
		Mesh rectangle;

		vector2<float> pos(width / 2, height / 2);

		rectangle.AddPoint({ -pos.x, -pos.y });
		rectangle.AddPoint({ -pos.x, pos.y });
		rectangle.AddPoint({ pos.x, pos.y });
		rectangle.AddPoint({ pos.x, -pos.y });

		rectangle.AddColor(color);

		rectangle.AddTextureCoordinate({ 0, 1 });
		rectangle.AddTextureCoordinate({ 0, 0 });
		rectangle.AddTextureCoordinate({ 1, 0 });
		rectangle.AddTextureCoordinate({ 1, 1 });


		rectangle.SetPointListType(PointListPattern::TriangleFan);

		return rectangle;
	}
	Mesh create_wire_rectangle(float width, float height, Color4ub color) noexcept
	{
		Mesh rectangle;

		vector2<float> pos(width / 2, height / 2);

		rectangle.AddPoint({ -pos.x, -pos.y });
		rectangle.AddPoint({ -pos.x, pos.y });
		rectangle.AddPoint({ pos.x, pos.y });
		rectangle.AddPoint({ pos.x, -pos.y });

		rectangle.AddColor(color);

		rectangle.SetPointListType(PointListPattern::LineLoop);

		return rectangle;
	}
	Mesh create_wire_box(float dimension, Color4ub color) noexcept
	{
		Mesh box;

		vector2<float> pos(dimension / 2);

		box.AddPoint({ -pos.x, -pos.y });
		box.AddPoint({ -pos.x, pos.y });
		box.AddPoint({ pos.x, pos.y });
		box.AddPoint({ pos.x, -pos.y });

		box.AddColor(color);

		box.SetPointListType(PointListPattern::LineLoop);

		return box;
	}
	Mesh create_line(vector2<float> a, vector2<float> b, vector2<float> scale, Color4ub color) noexcept
	{
		Mesh line;

		line.AddPoint({ a.x * scale.x, a.y * scale.y });
		line.AddPoint({ b.x * scale.x, b.y * scale.y });

		line.AddColor(color);

		line.SetPointListType(PointListPattern::Lines);

		return line;
	}
	Mesh create_triangle(vector2<float> scale, Color4ub color) noexcept
	{
		Mesh traingle;

		traingle.AddPoint({ 0, scale.y / 2 });
		traingle.AddPoint({ scale.x / 2, -scale.y / 2 });
		traingle.AddPoint({ -scale.x / 2, -scale.y / 2 });

		traingle.AddColor(color);

		traingle.SetPointListType(PointListPattern::Triangles);

		return traingle;
	}
	Mesh create_quad(vector2<float> point_1, vector2<float> point_2, vector2<float> point_3, vector2<float> point_4, Color4ub color)
	{
		Mesh quad;

		quad.AddPoint({ point_1.x, point_1.y });
		quad.AddPoint({ point_2.x, point_2.y });
		quad.AddPoint({ point_3.x, point_3.y });
		quad.AddPoint({ point_4.x, point_4.y });

		quad.AddColor(color);

		quad.SetPointListType(PointListPattern::TriangleFan);

		return quad;
	}
}

std::size_t Mesh::GetPointCount() const noexcept
{
	return points.size();
}

vector2<float>     Mesh::GetPoint(std::size_t index) const noexcept
{
	return points[index];
}

std::vector<vector2<float>>& Mesh::Get_Points()
{
	return points;
}

Color4ub Mesh::GetColor(std::size_t index) const noexcept
{
	if (colors.empty())
	{
		return { 0, 0, 0 };
	}
	if (index >= colors.size())
	{
		return colors.back();
	}
	if (index >= 0 && GetPointCount())
	{
		return colors.at(index);
	}
	return { 0, 0, 0 };
}
vector2<float> Mesh::GetTextureCoordinate(std::size_t index) const noexcept
{
	if (index >= 0 && index < GetPointCount())
	{
		if (textureCoordinates.empty())
		{
			return { 0, 0 };
		}
		return textureCoordinates[index];
	}
	else
	{
		return textureCoordinates[GetPointCount() - 1];
	}
}

PointListPattern Mesh::GetPointListPattern() const noexcept { return pointListType; }
void             Mesh::SetPointListType(PointListPattern type) noexcept { pointListType = type; }

void Mesh::AddColor(Color4ub color) noexcept { colors.push_back(color); }
void Mesh::AddPoint(vector2<float> point) noexcept { points.push_back(point); }
void Mesh::AddTextureCoordinate(vector2<float> texture_coordinate) noexcept
{
	textureCoordinates.push_back(texture_coordinate);
}

void Mesh::ClearColors() noexcept { colors.clear(); }
bool Mesh::HasMoreThanOneColor() const noexcept
{
	if (colors.size() > 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Mesh::ClearTextureCoordinates() noexcept { textureCoordinates.clear(); }
void Mesh::ClearPoints() noexcept { points.clear(); }
void Mesh::Clear() noexcept
{
	colors.clear();
	textureCoordinates.clear();
	points.clear();
}

