/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#pragma once
#pragma warning(push)
#pragma warning(disable : 4201) // warning C4201 : nonstandard extension used : nameless struct / union


template <typename T>
struct [[nodiscard]] vector2
{
	union {
		struct
		{
			T x, y;
		};
		struct
		{
			T u, v;
		};
		struct
		{
			T width, height;
		};
		T elements[2];
	};

	vector2() noexcept;
	explicit vector2(T repeated_float) noexcept;
	vector2(T fx, T fy) noexcept;
};

template <typename T>
constexpr void operator+=(vector2<T>& v, const vector2<T>& adding_vector) noexcept;

template <typename T>
constexpr void operator-=(vector2<T>& v, const vector2<T>& subtracting_vector) noexcept;

template <typename T>
constexpr void operator*=(vector2<T>& v, T scale) noexcept;

template <typename T>
constexpr void operator/=(vector2<T>& v, T divisor) noexcept;

template <typename T>
constexpr vector2<T> operator-(const vector2<T>& v) noexcept;

template <typename T>
constexpr vector2<T> operator+(const vector2<T>& v1, const vector2<T>& v2) noexcept;

template <typename T>
constexpr vector2<T> operator-(const vector2<T>& v1, const vector2<T>& v2) noexcept;

template <typename T>
constexpr vector2<T> operator*(const vector2<T>& v, T scale) noexcept;

template <typename T>
constexpr vector2<T> operator*(T scale, const vector2<T>& v) noexcept;

template <typename T>
constexpr vector2<T> operator/(const vector2<T>& v, T divisor) noexcept;

template <typename T>
[[nodiscard]] constexpr bool operator==(const vector2<T>& v1, const vector2<T>& v2) noexcept;
template <typename T>
[[nodiscard]] constexpr bool operator!=(const vector2<T>& v1, const vector2<T>& v2) noexcept;

template <typename T>
[[nodiscard]] constexpr T dot(vector2<T> a, vector2<T> b) noexcept;

template <typename T>
constexpr vector2<T>             perpendicular_to(vector2<T> a) noexcept;

template <typename T>
[[nodiscard]] constexpr T magnitude_squared(vector2<T> a) noexcept;

template <typename T>
[[nodiscard]] constexpr T magnitude(vector2<T> a) noexcept;

template <typename T>
constexpr vector2<T>             normalize(vector2<T> a) noexcept;

template <typename T>
[[nodiscard]] constexpr T distance_between_squared(vector2<T> a, vector2<T> b) noexcept;

template <typename T>
[[nodiscard]] constexpr T distance_between(vector2<T> a, vector2<T> b) noexcept;

template <typename T>
[[nodiscard]] constexpr T angle_between(vector2<T> a, vector2<T> b) noexcept;

template <typename T>
constexpr vector2<T>             rotate_by(T angle_in_radians, vector2<T> v) noexcept;


#pragma warning(pop)
#include <cassert>
#include <limits>
#include "vector2.inl"