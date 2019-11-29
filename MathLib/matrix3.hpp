#pragma once
#include "vector2.hpp"
#include "vector3.hpp"
#pragma warning(push)
#pragma warning(disable : 4201) // warning C4201 : nonstandard extension used : nameless struct / union

/**
 * \brief Column first 3x3 matrix class
 */
template <typename T>
struct [[nodiscard]] matrix3
{
public:
	union {
		float elements[3][3];
		struct
		{
			vector3<T> column0;
			vector3<T> column1;
			vector3<T> column2;
		};
	};
	constexpr matrix3() noexcept;
	constexpr matrix3(vector3<T> first_column, vector3<T> second_column, vector3<T> third_column) noexcept;

	constexpr matrix3(T column0_row0, T column0_row1, T column0_row2, T column1_row0, T column1_row1,
		T column1_row2, T column2_row0, T column2_row1, T column2_row2) noexcept;
	constexpr T  operator()(T column, T row) const noexcept;
	constexpr T& operator()(int column, int row) noexcept;
};

template <typename T>
constexpr matrix3<T> operator*(const matrix3<T>& m1, const matrix3<T>& m2) noexcept;

template <typename T>
constexpr void    operator*=(matrix3<T>& m1, const matrix3<T>& m2) noexcept;

template <typename T>
constexpr vector3<T> operator*(const matrix3<T>& m, vector3<T> v) noexcept;

template <typename T>
struct vector2;
namespace MATRIX3
{
	template <typename T>
	constexpr matrix3<T> transpose(const matrix3<T>& m) noexcept;

	template <typename T>
	constexpr matrix3<T> build_rotation(T angle_in_radians) noexcept;

	template <typename T>
	constexpr matrix3<T> build_identity(T iden) noexcept;

	template <typename T>
	constexpr matrix3<T> build_scale(T scale_x, T scale_y) noexcept;

	template <typename T>
	constexpr matrix3<T> build_scale(T scale) noexcept;

	template <typename T>
	constexpr matrix3<T> build_scale(const vector2<T>& scale) noexcept;

	template <typename T>
	constexpr matrix3<T> build_translation(T translate_x, T translate_y) noexcept;

	template <typename T>
	constexpr matrix3<T> build_translation(const vector2<T>& translation) noexcept;
}


#pragma warning(pop)
#include "matrix3.inl"
