/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
template <typename T>
vector2<T>::vector2() noexcept
{
	x = 0;
	y = 0;
}

template <typename T>
vector2<T>::vector2(T repeated_float) noexcept
{
	x = repeated_float;
	y = repeated_float;
}

template <typename T>
vector2<T>::vector2(T fx, T fy) noexcept
{
	x = fx;
	y = fy;
}

template <typename T>
constexpr void operator+=(vector2<T>& v, const vector2<T>& adding_vector) noexcept
{
	v.x += adding_vector.x;
	v.y += adding_vector.y;
}

template <typename T>
constexpr void operator-=(vector2<T>& v, const vector2<T>& subtracting_vector) noexcept
{
	v.x -= subtracting_vector.x;
	v.y -= subtracting_vector.y;
}

template <typename T>
constexpr void operator*=(vector2<T>& v, T scale) noexcept
{
	v.x *= scale;
	v.y *= scale;
}

template <typename T>
constexpr void operator/=(vector2<T>& v, T divisor) noexcept
{
	assert(divisor != 0);
	v.x /= divisor;
	v.y /= divisor;
}

template <typename T>
constexpr vector2<T> operator-(const vector2<T>& v) noexcept
{
	vector2<T> result_vec;
	result_vec.x = -(v.x);
	result_vec.y = -(v.y);

	return result_vec;
}

template <typename T>
constexpr vector2<T> operator+(const vector2<T>& v1, const vector2<T>& v2) noexcept
{
	vector2<T> result_vec;
	result_vec.x = v1.x + v2.x;
	result_vec.y = v1.y + v2.y;

	return result_vec;
}


template <typename T>
constexpr vector2<T> operator-(const vector2<T>& v1, const vector2<T>& v2) noexcept
{
	vector2<T> result_vec;
	v2.x > v1.x ? result_vec.x = v2.x - v1.x : result_vec.x = v1.x - v2.x;
	v2.y > v1.y ? result_vec.y = v2.y - v1.y : result_vec.y = v1.y - v2.y;

	return result_vec;
}


template <typename T>
constexpr vector2<T> operator*(const vector2<T>& v, T scale) noexcept
{
	vector2<T> result_vec;
	result_vec.x = v.x * scale;
	result_vec.y = v.y * scale;

	return result_vec;
}

template <typename T>
constexpr vector2<T> operator*(T scale, const vector2<T>& v) noexcept
{
	vector2<T> result_vec;
	result_vec.x = v.x * scale;
	result_vec.y = v.y * scale;

	return result_vec;
}


template <typename T>
constexpr vector2<T> operator/(const vector2<T>& v, T divisor) noexcept
{
	assert(divisor != 0);

	vector2<T> result_vec;
	result_vec.x = v.x / divisor;
	result_vec.y = v.y / divisor;

	return result_vec;
}


template <typename T>
constexpr  bool operator==(const vector2<T>& v1, const vector2<T>& v2) noexcept
{
	if (std::abs(v1.x - v2.x) <= std::numeric_limits<T>::epsilon() &&
		std::abs(v1.y - v2.y) <= std::numeric_limits<T>::epsilon())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
constexpr  bool operator!=(const vector2<T>& v1, const vector2<T>& v2) noexcept
{
	if (std::abs(v1.x - v2.x) <= std::numeric_limits<T>::epsilon() &&
		std::abs(v1.y - v2.y) <= std::numeric_limits<T>::epsilon())
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <typename T>
constexpr T dot(vector2<T> a, vector2<T> b) noexcept
{
	T dot_product = 0.0f;

	dot_product += (a.x * b.x);
	dot_product += (a.y * b.y);

	return dot_product;
}


template <typename T>
constexpr vector2<T>             perpendicular_to(vector2<T> a) noexcept
{
	vector2<T> result_vec;
	result_vec.x = -(a.y);
	result_vec.y = a.x;

	return result_vec;
}

template <typename T>
constexpr T magnitude_squared(vector2<T> a) noexcept
{
	T magnitude_val_squared = 0.0f;

	magnitude_val_squared += dot(a, a);

	return magnitude_val_squared;
}

template <typename T>
constexpr T magnitude(vector2<T> a) noexcept
{
	T magnitude_val = 0.0f;

	magnitude_val = sqrt(dot(a, a));

	return magnitude_val;
}

template <typename T>
constexpr vector2<T>             normalize(vector2<T> a) noexcept
{
	vector2<T> result_vec;
	T   magnitude_val = 0.0f;

	magnitude_val = magnitude(a);
	result_vec.x = a.x / magnitude_val;
	result_vec.y = a.y / magnitude_val;

	return result_vec;
}

template <typename T>
constexpr T distance_between_squared(vector2<T> a, vector2<T> b) noexcept
{
	T distance_squared = 0.0f;
	T distance_x = 0.0f;
	T distance_y = 0.0f;

	distance_x = b.x - a.x;
	distance_y = b.y - a.y;

	distance_squared = ((distance_x * distance_x) + (distance_y * distance_y));

	return distance_squared;
}

template <typename T>
constexpr T distance_between(vector2<T> a, vector2<T> b) noexcept
{
	T distance = 0.0f;
	T distance_x = 0.0f;
	T distance_y = 0.0f;

	distance_x = b.x - a.x;
	distance_y = b.y - a.y;

	distance = sqrt((distance_x * distance_x) + (distance_y * distance_y));

	return distance;
}

template <typename T>
constexpr T angle_between(vector2<T> a, vector2<T> b) noexcept
{
	T cos_theta = dot(a, b) / (magnitude(a) * magnitude(b));
	T radian = acosf(cos_theta);
	T angle = radian;

	return angle;
}

template <typename T>
constexpr vector2<T>             rotate_by(T angle_in_radians, vector2<T> v) noexcept
{
	vector2<T> result_vec;
	result_vec.x = static_cast<T>((cos(angle_in_radians) * v.x) - (sin(angle_in_radians) * v.y));
	result_vec.y = static_cast<T>((sin(angle_in_radians) * v.x) + (cos(angle_in_radians) * v.y));

	return result_vec;
}