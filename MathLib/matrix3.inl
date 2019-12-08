/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
template <typename T>
constexpr matrix3<T>::matrix3() noexcept
{
	column0.x = static_cast<T>(0);
	column0.y = static_cast<T>(0);
	column0.z = static_cast<T>(0);
	column1.x = static_cast<T>(0);
	column1.y = static_cast<T>(0);
	column1.z = static_cast<T>(0);
	column2.x = static_cast<T>(0);
	column2.y = static_cast<T>(0);
	column2.z = static_cast<T>(0);
}

template <typename T>
constexpr matrix3<T>::matrix3(vector3<T> first_column, vector3<T> second_column, vector3<T> third_column) noexcept
{
	column0.x = first_column.x;
	column0.y = first_column.y;
	column0.z = first_column.z;
	column1.x = second_column.x;
	column1.y = second_column.y;
	column1.z = second_column.z;
	column2.x = third_column.x;
	column2.y = third_column.y;
	column2.z = third_column.z;
}
template <typename T>
constexpr matrix3<T>::matrix3(T column0_row0, T column0_row1, T column0_row2, T column1_row0, T column1_row1,
	T column1_row2, T column2_row0, T column2_row1, T column2_row2) noexcept
{
	column0.x = column0_row0;
	column0.y = column0_row1;
	column0.z = column0_row2;
	column1.x = column1_row0;
	column1.y = column1_row1;
	column1.z = column1_row2;
	column2.x = column2_row0;
	column2.y = column2_row1;
	column2.z = column2_row2;
}

template <typename T>
constexpr T  matrix3<T>::operator()(T column, T row) const noexcept
{
	assert(column < 3 && column >= 0);
	assert(row < 3 && row >= 0);
	return elements[column][row];
}

template <typename T>
constexpr T& matrix3<T>::operator()(int column, int row) noexcept
{
	assert(column < 3 && column >= 0);
	assert(row < 3 && row >= 0);
	return elements[column][row];
}


template <typename T>
constexpr matrix3<T> operator*(const matrix3<T>& m1, const matrix3<T>& m2) noexcept
{
	matrix3<T> product;

	product.column0.x = (m1.column0.x * m2.column0.x) + (m1.column1.x * m2.column0.y) + (m1.column2.x * m2.column0.z);
	product.column1.x = (m1.column0.x * m2.column1.x) + (m1.column1.x * m2.column1.y) + (m1.column2.x * m2.column1.z);
	product.column2.x = (m1.column0.x * m2.column2.x) + (m1.column1.x * m2.column2.y) + (m1.column2.x * m2.column2.z);
	product.column0.y = (m1.column0.y * m2.column0.x) + (m1.column1.y * m2.column0.y) + (m1.column2.y * m2.column0.z);
	product.column1.y = (m1.column0.y * m2.column1.x) + (m1.column1.y * m2.column1.y) + (m1.column2.y * m2.column1.z);
	product.column2.y = (m1.column0.y * m2.column2.x) + (m1.column1.y * m2.column2.y) + (m1.column2.y * m2.column2.z);
	product.column0.z = (m1.column0.z * m2.column0.x) + (m1.column1.z * m2.column0.y) + (m1.column2.z * m2.column0.z);
	product.column1.z = (m1.column0.z * m2.column1.x) + (m1.column1.z * m2.column1.y) + (m1.column2.z * m2.column1.z);
	product.column2.z = (m1.column0.z * m2.column2.x) + (m1.column1.z * m2.column2.y) + (m1.column2.z * m2.column2.z);

	return product;
}

template <typename T>
constexpr void    operator*=(matrix3<T>& m1, const matrix3<T>& m2) noexcept
{
	m1 = m1 * m2;
}

template <typename T>
constexpr vector3<T> operator*(const matrix3<T>& m, vector3<T> v) noexcept
{
	vector3<T> product;
	product.x = (m.column0.x * v.x) + (m.column1.x * v.y) + (m.column2.x * v.z);
	product.y = (m.column0.y * v.x) + (m.column1.y * v.y) + (m.column2.y * v.z);
	product.z = (m.column0.z * v.x) + (m.column1.z * v.y) + (m.column2.z * v.z);
	return product;
}

template <typename T>
constexpr matrix3<T> MATRIX3::transpose(const matrix3<T>& m) noexcept
{
	matrix3<T> transpose_matrix;
	transpose_matrix.column0.x = m.column0.x;
	transpose_matrix.column0.y = m.column1.x;
	transpose_matrix.column0.z = m.column2.x;
	transpose_matrix.column1.x = m.column0.y;
	transpose_matrix.column1.y = m.column1.y;
	transpose_matrix.column1.z = m.column2.y;
	transpose_matrix.column2.x = m.column0.z;
	transpose_matrix.column2.y = m.column1.z;
	transpose_matrix.column2.z = m.column2.z;
	return transpose_matrix;
}

template <typename T>
constexpr matrix3<T> MATRIX3::build_rotation(T angle_in_radians) noexcept
{
	matrix3<T> rotation_matrix;
	rotation_matrix.column0.x = static_cast<T>(cos(angle_in_radians));
	rotation_matrix.column0.y = static_cast<T>(sin(angle_in_radians));
	rotation_matrix.column0.z = 0.0f;
	rotation_matrix.column1.x = static_cast<T>(-(sin(angle_in_radians)));
	rotation_matrix.column1.y = static_cast<T>(cos(angle_in_radians));
	rotation_matrix.column1.z = 0.0f;
	rotation_matrix.column2.x = 0.0f;
	rotation_matrix.column2.y = 0.0f;
	rotation_matrix.column2.z = 1.0f;

	if (fabs(rotation_matrix.column0.x) <= std::numeric_limits<T>::epsilon())
	{
		rotation_matrix.column0.x = 0.0f;
	}
	if (fabs(rotation_matrix.column0.y) <= std::numeric_limits<T>::epsilon())
	{
		rotation_matrix.column0.y = 0.0f;
	}
	if (fabs(rotation_matrix.column1.x) <= std::numeric_limits<T>::epsilon())
	{
		rotation_matrix.column1.x = 0.0f;
	}
	if (fabs(rotation_matrix.column1.y) <= std::numeric_limits<T>::epsilon())
	{
		rotation_matrix.column1.y = 0.0f;
	}
	return rotation_matrix;
}

template <typename T>
constexpr  matrix3<T> MATRIX3::build_identity(T iden) noexcept
{
	iden;
	matrix3<T> identity_matrix;
	identity_matrix.column0.x = 1.0f;
	identity_matrix.column0.y = 0.0f;
	identity_matrix.column0.z = 0.0f;
	identity_matrix.column1.x = 0.0f;
	identity_matrix.column1.y = 1.0f;
	identity_matrix.column1.z = 0.0f;
	identity_matrix.column2.x = 0.0f;
	identity_matrix.column2.y = 0.0f;
	identity_matrix.column2.z = 1.0f;
	return identity_matrix;
}

template <typename T>
constexpr matrix3<T> MATRIX3::build_scale(T scale_x, T scale_y) noexcept
{
	matrix3<T> scale_matrix;
	scale_matrix.column0.x = scale_x;
	scale_matrix.column0.y = 0.0;
	scale_matrix.column0.z = 0.0;
	scale_matrix.column1.x = 0.0;
	scale_matrix.column1.y = scale_y;
	scale_matrix.column1.z = 0.0;
	scale_matrix.column2.x = 0.0;
	scale_matrix.column2.y = 0.0;
	scale_matrix.column2.z = 1.0;
	return scale_matrix;
}

template <typename T>
constexpr matrix3<T> MATRIX3::build_scale(T scale) noexcept
{
	matrix3<T> scale_matrix;
	scale_matrix.column0.x = scale;
	scale_matrix.column0.y = 0.0;
	scale_matrix.column0.z = 0.0;
	scale_matrix.column1.x = 0.0;
	scale_matrix.column1.y = scale;
	scale_matrix.column1.z = 0.0;
	scale_matrix.column2.x = 0.0;
	scale_matrix.column2.y = 0.0;
	scale_matrix.column2.z = 1.0;
	return scale_matrix;
}

template <typename T>
constexpr matrix3<T> MATRIX3::build_scale(const vector2<T>& scale) noexcept
{
	matrix3<T> scale_matrix;
	scale_matrix.column0.x = scale.x;
	scale_matrix.column0.y = 0.0;
	scale_matrix.column0.z = 0.0;
	scale_matrix.column1.x = 0.0;
	scale_matrix.column1.y = scale.y;
	scale_matrix.column1.z = 0.0;
	scale_matrix.column2.x = 0.0;
	scale_matrix.column2.y = 0.0;
	scale_matrix.column2.z = 1.0;
	return scale_matrix;
}

template <typename T>
constexpr matrix3<T> MATRIX3::build_translation(T translate_x, T translate_y) noexcept
{
	matrix3<T> translation_matrix;
	translation_matrix.column0.x = 1.0;
	translation_matrix.column0.y = 0.0;
	translation_matrix.column0.z = 0.0;
	translation_matrix.column1.x = 0.0;
	translation_matrix.column1.y = 1.0;
	translation_matrix.column1.z = 0.0;
	translation_matrix.column2.x = translate_x;
	translation_matrix.column2.y = translate_y;
	translation_matrix.column2.z = 1.0;
	return translation_matrix;
}

template <typename T>
constexpr matrix3<T> MATRIX3::build_translation(const vector2<T>& translation) noexcept
{
	matrix3<T> translation_matrix;
	translation_matrix.column0.x = 1.0;
	translation_matrix.column0.y = 0.0;
	translation_matrix.column0.z = 0.0;
	translation_matrix.column1.x = 0.0;
	translation_matrix.column1.y = 1.0;
	translation_matrix.column1.z = 0.0;
	translation_matrix.column2.x = translation.x;
	translation_matrix.column2.y = translation.y;
	translation_matrix.column2.z = 1.0;
	return translation_matrix;
}