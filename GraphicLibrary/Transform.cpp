#include "Transform.hpp"
#include "angles.hpp"

matrix3<float> Transform::GetModelToWorld() const noexcept
{
		matrix3<float> model_to_world = MATRIX3::build_identity(1.0f);
		matrix3<float> scale_matrix = MATRIX3::build_scale(GetScale());
		matrix3<float> translation_matrix = MATRIX3::build_translation(GetTranslation());
		matrix3<float> rotation_matrix = MATRIX3::build_rotation(to_radians(GetRotation()));
		model_to_world = translation_matrix * rotation_matrix * scale_matrix;
		if (parent == nullptr)
		{
			return model_to_world;
		}
		else
		{
			return parent->GetModelToWorld() * model_to_world;
		}

}

matrix3<float> Transform::GetWorldToModel() const noexcept
{
	matrix3<float> world_to_model = MATRIX3::build_identity(1.0f);
	matrix3<float> scale_matrix = MATRIX3::build_scale(1 / GetScale().x, 1 / GetScale().y);
	matrix3<float> translation_matrix = MATRIX3::build_translation(-GetTranslation());
	matrix3<float> rotation_matrix = MATRIX3::build_rotation(to_radians(-GetRotation()));
	world_to_model = scale_matrix * rotation_matrix * translation_matrix;

	if (parent == nullptr)
	{
		return world_to_model;
	}
	else
	{
		return world_to_model * parent->GetModelToWorld();
	}
}

float Transform::CalculateWorldDepth() const noexcept
{
	float worldDepth = GetDepth();

	if (parent != nullptr)
	{
		worldDepth += parent->CalculateWorldDepth();
	}

	return worldDepth;
}

float Transform::GetDepth() const noexcept
{
	return depth;
}

void Transform::SetDepth(float new_depth) noexcept
{

	depth = new_depth;
}

vector2<float> Transform::GetTranslation() const noexcept
{
	return translation;
}

void Transform::SetTranslation(const vector2<float>& new_translation) noexcept
{
	translation.x = new_translation.x;
	translation.y = new_translation.y;
}

void Transform::AddTranslation(const vector2<float>& translation)
{
	this->translation.x += translation.x;
	this->translation.y += translation.y;
}

vector2<float> Transform::Get_Save_Translation()const noexcept
{
	return save_translation;
}
vector2<float> Transform::GetScale() const noexcept
{
	return scale;
}

void Transform::SetScale(const float& new_scale) noexcept
{
	scale.x = new_scale;
	scale.y = new_scale;
}

void Transform::SetScale(const vector2<float>& new_scale) noexcept
{
	scale.x = new_scale.x;
	scale.y = new_scale.y;
}

float Transform::GetRotation() const noexcept
{
	return rotation;
}

void Transform::SetRotation(float new_rotation) noexcept
{
	rotation = new_rotation;
}

const Transform* Transform::GetParent() const noexcept
{
	return parent;
}

void Transform::SetParent(const Transform* transform_parent) noexcept
{
	parent = transform_parent;
}