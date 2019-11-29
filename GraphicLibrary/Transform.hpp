#pragma once
#include "matrix3.hpp"
#include "vector2.hpp"


class [[nodiscard]] Transform
{
public:
	Transform() noexcept = default;
	matrix3<float> GetModelToWorld() const noexcept;
	matrix3<float> GetWorldToModel() const noexcept;

	float CalculateWorldDepth() const noexcept;
	float GetDepth() const noexcept;
	void  SetDepth(float new_depth) noexcept;

	vector2<float> GetTranslation() const noexcept;
	vector2<float>& GetTranslation_Reference()
	{
		return translation;
	}
	void SetTranslation(const vector2<float> & new_translation) noexcept;
	void AddTranslation(const vector2<float> & translation);
	vector2<float> Get_Save_Translation()const noexcept;
	//void Set_Save_Translation(const vector2& new_translation)noexcept;

	vector2<float> GetScale() const noexcept;
	vector2<float>& GetScale_Reference()
	{
		return scale;
	}
	/*vector2 GetAcceleration()const noexcept;
	vector2& GetAcceleration_Reference()
	{
		return acceleration;
	}*/
	vector2<float>& GetCenter()
	{
		return center;
	}
	void    SetScale(const float& new_scale) noexcept;
	void    SetScale(const vector2<float>& new_scale) noexcept;

	void SetAcceleration(const vector2<float>& new_acceleration) noexcept;

	float GetRotation() const noexcept;
	void  SetRotation(float new_rotation) noexcept;

	const Transform* GetParent() const noexcept;
	void             SetParent(const Transform * transform_parent) noexcept;

private:
	vector2<float>			 acceleration = { 0, 0 };
	vector2<float>          translation{};
	vector2<float>          scale{1.0f, 1.0f};
	vector2<float>			 save_translation{0, 0};
	vector2<float>          center{ 0.0f, 0.0f };

	float            rotation = 0.0f;
	float            depth = 0.0f;
	const Transform* parent = nullptr;

};

