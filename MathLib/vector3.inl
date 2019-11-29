template <typename T>
vector3<T>::vector3() noexcept
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

template <typename T>
vector3<T>::vector3(T repeated_value) noexcept
{
	x = repeated_value;
	y = repeated_value;
	z = repeated_value;
}

template <typename T>
vector3<T>::vector3(T vx, T vy, T vz) noexcept
{
	x = vx;
	y = vy;
	z = vz;
}

template <typename T>
constexpr void operator-=(vector3<T>& v, const vector3<T>& subtracting_vector) noexcept
{
	v.x -= subtracting_vector.x;
	v.y -= subtracting_vector.y;
	v.z -= subtracting_vector.z;
}

template <typename T>
constexpr void operator*=(vector3<T>& v, T scale) noexcept
{
	v.x *= scale;
	v.y *= scale;
	v.z *= scale;
}


template <typename T>
constexpr void operator/=(vector3<T>& v, T divisor) noexcept
{
	assert(divisor != 0);
	v.x /= divisor;
	v.y /= divisor;
	v.z /= divisor;
}

template <typename T>
constexpr vector3<T> operator-(const vector3<T>& v) noexcept
{
	vector3<T> negated_vector;
	negated_vector.x = -v.x;
	negated_vector.y = -v.y;
	negated_vector.z = -v.z;
	return negated_vector;
}

template <typename T>
constexpr vector3<T> operator+(const vector3<T>& v1, const vector3<T>& v2) noexcept
{
	vector3<T> added_vector;
	added_vector.x = v1.x + v2.x;
	added_vector.y = v1.y + v2.y;
	added_vector.z = v1.z + v2.z;
	return added_vector;
}

template <typename T>
constexpr vector3<T> operator-(const vector3<T>& v1, const vector3<T>& v2) noexcept
{
	vector3<T> subtracted_vector;
	subtracted_vector.x = v1.x - v2.x;
	subtracted_vector.y = v1.y - v2.y;
	subtracted_vector.z = v1.z - v2.z;
	return subtracted_vector;
}
template <typename T>
constexpr vector3<T> operator*(const vector3<T>& v, float scale) noexcept
{
	vector3<T> multiplied_vector;
	multiplied_vector.x = v.x * scale;
	multiplied_vector.y = v.y * scale;
	multiplied_vector.z = v.z * scale;
	return multiplied_vector;
}

template <typename T>
constexpr vector3<T> operator*(T scale, const vector3<T>& v) noexcept
{
	vector3<T> multiplied_vector;
	multiplied_vector.x = v.x * scale;
	multiplied_vector.y = v.y * scale;
	multiplied_vector.z = v.z * scale;
	return multiplied_vector;
}

template <typename T>
constexpr vector3<T> operator/(const vector3<T>& v, T divisor) noexcept
{
	vector3<T> divided_vector;
	assert(divisor != 0);
	divided_vector.x = v.x / divisor;
	divided_vector.y = v.y / divisor;
	divided_vector.z = v.z / divisor;
	return divided_vector;
}
template <typename T>
constexpr  bool operator==(const vector3<T>& v1, const vector3<T>& v2) noexcept
{
	if (std::abs(v1.x - v2.x) <= std::numeric_limits<T>::epsilon() &&
		std::abs(v1.y - v2.y) <= std::numeric_limits<T>::epsilon() &&
		std::abs(v1.z - v2.z) <= std::numeric_limits<T>::epsilon())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
constexpr  bool operator!=(const vector3<T>& v1, const vector3<T>& v2) noexcept
{
	if (std::abs(v1.x - v2.x) <= std::numeric_limits<T>::epsilon() &&
		std::abs(v1.y - v2.y) <= std::numeric_limits<T>::epsilon() &&
		std::abs(v1.z - v2.z) <= std::numeric_limits<T>::epsilon())
	{
		return false;
	}
	else
	{
		return true;
	}
}


template <typename T>
constexpr  T dot(vector3<T> a, vector3<T> b) noexcept
{
	T dotproduct = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return dotproduct;
}

template <typename T>
constexpr vector3<T>        cross(vector3<T> a, vector3<T> b) noexcept
{
	vector3<T> crossproduct;
	crossproduct.x = (a.y * b.z) - (a.z * b.y);
	crossproduct.y = -(a.x * b.z) + (a.z * b.x);
	crossproduct.z = (a.x * b.y) - (a.y * b.x);
	return crossproduct;
}

template <typename T>
constexpr  T magnitude_squared(vector3<T> a) noexcept
{
	return  dot(a, a);
}

template <typename T>
constexpr  T magnitude(vector3<T> a) noexcept
{
	return sqrt(dot(a, a));
}

template <typename T>
constexpr vector3<T>        normalize(vector3<T> a) noexcept
{
	vector3<T> v;
	v.x = a.x / sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	v.y = a.y / sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	v.z = a.z / sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	return v;
}
template <typename T>
constexpr  T distance_between_squared(vector3<T> a, vector3<T> b) noexcept
{
	T distance;
	distance = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
	return distance;
}
template <typename T>
constexpr  T distance_between(vector3<T> a, vector3<T> b) noexcept
{
	T distance;
	distance = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
	return distance;
}

template <typename T>
constexpr  T angle_between(vector3<T> a, vector3<T> b) noexcept
{
	T angle;
	angle = (dot(a, b) / (magnitude(a) * magnitude(b)));
	return acos(angle);
}
