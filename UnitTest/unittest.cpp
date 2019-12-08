/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "angle.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "matrix3.hpp"

TEST_CASE("Vector2 Contructors")
{
	vector2<float> floatCtorTest{ 1.f };
	REQUIRE(floatCtorTest.x == 1.f);
	REQUIRE(floatCtorTest.y == 1.f);
	vector2<float> floatCtorTest2{ 2.f, 3.f };
	REQUIRE(floatCtorTest2.x == 2.f);
	REQUIRE(floatCtorTest2.y == 3.f);
}

TEST_CASE("Vector2 Basic Operators")
{
	vector2<float> floatAdditionTest1{ 1.f };
	vector2<float> floatAdditionTest2{ 1.f };
	vector2<float> floatAdditionAnswer{ 2.f };
	REQUIRE((floatAdditionTest1 + floatAdditionTest2) == floatAdditionAnswer);

	vector2<float> floatAdditionTest3{ -1.f };
	vector2<float> floatAdditionAnswer2{ 0.f };
	REQUIRE((floatAdditionTest1 + floatAdditionTest3) == floatAdditionAnswer2);

	vector2<float> floatSubtractionTest1{ 1.f };
	vector2<float> floatSubtractionTest2{ 1.f };
	vector2<float> floatSubtractionAnswer{ 0.f };
	REQUIRE((floatSubtractionTest1 - floatSubtractionTest2) == floatSubtractionAnswer);

	vector2<float> floatSubtractionTest3{ -3.f };
	vector2<float> floatSubtractionAnswer2{ 4.f };
	REQUIRE((floatSubtractionTest1 - floatSubtractionTest3) == floatSubtractionAnswer2);

	vector2<float> multipleWithFloatTest{ 2.f };
	float scaler{ 3.f };
	vector2<float> multipleWithFloatAnswer{ 6.f };
	REQUIRE((multipleWithFloatTest * scaler) == multipleWithFloatAnswer);

	vector2<float> divideWithFloatTest{ 10.f };
	float divisor{ 2.f };
	vector2<float> divideWithFloatAnswer{ 5.f };
	REQUIRE((divideWithFloatTest / divisor) == divideWithFloatAnswer);

	vector2<float> flipTest{ -5.f };
	vector2<float> flipAnswer{ 5.f };
	REQUIRE(-flipTest == flipAnswer);

	vector2<float> equalTest{ 1.f };
	bool isEqual = (equalTest == equalTest);
	REQUIRE(isEqual == true);

	vector2<float> notEqualTest{ 10.f };
	vector2<float> notEqualTest2{ 302.f };
	bool isNotEqual = (notEqualTest != notEqualTest2);
	REQUIRE(isNotEqual == true);
}

TEST_CASE("Vector2 Advanced Functions")
{
	vector2<float> dotTest1{ 2.f, 3.f };
	vector2<float> dotTest2{ 4.f, 5.f };
	float dotResult{ 23.f };
	REQUIRE(dot(dotTest1, dotTest2) == dotResult);

	vector2<float> perpendicularTest{ 2.f, 10.f };
	vector2<float> perpendicularAnswer{ -10.f, 2.f };
	REQUIRE(perpendicular_to(perpendicularTest) == perpendicularAnswer);

	vector2<float> perpendicularTest2{ 1.f, 0.f };
	vector2<float> perpendicularAnswer2{ -0.f, 1.f };
	REQUIRE(perpendicular_to(perpendicularTest2) == perpendicularAnswer2);

	vector2<float> magnitudeSquaredTest{ 10.f };
	float magnitudeSquaredAnswer{ 200.f };
	REQUIRE(magnitude_squared(magnitudeSquaredTest) == magnitudeSquaredAnswer);

	vector2<float> magnitudeSquaredTest2{ 0.f };
	float magnitudeSquaredAnswer2{ 0.f };
	REQUIRE(magnitude_squared(magnitudeSquaredTest2) == magnitudeSquaredAnswer2);

	vector2<float> magnitudeSquaredTest3{ 20.f, -20.f };
	float magnitudeSquaredAnswer3{ 800.f };
	REQUIRE(magnitude_squared(magnitudeSquaredTest3) == magnitudeSquaredAnswer3);

	vector2<float> magnitudeTest{ 3.f, 4.f };
	float magnitudeAnswer{ 5.f };
	REQUIRE(magnitude(magnitudeTest) == magnitudeAnswer);

	vector2<float> magnitudeTest2{ 20.f, 0.f };
	float magnitudeAnswer2{ 20.f };
	REQUIRE(magnitude(magnitudeTest2) == magnitudeAnswer2);

	vector2<float> normalizeTest{ 1.f };
	vector2<float> normalizeAnswer{ 1.f / sqrtf(2) };
	REQUIRE(normalize(normalizeTest) == normalizeAnswer);

	vector2<float> normalizeTest2{ 5.f, 0.f };
	vector2<float> normalizeAnswer2{ 1.f, 0.f };
	REQUIRE(normalize(normalizeTest2) == normalizeAnswer2);

	vector2<float> distanceSqTest{ 1.f, 0.f };
	vector2<float> distanceSqTest2{ 5.f, 0.f };
	float distanceSqAnswer{ 16.f };
	REQUIRE(distance_between_squared(distanceSqTest, distanceSqTest2) == distanceSqAnswer);

	vector2<float> distanceSqTest3{ 5.f, 10.f };
	vector2<float> distanceSqTest4{ 1.f, 9.f };
	float distanceSqAnswer2{ 17.f };
	REQUIRE(distance_between_squared(distanceSqTest3, distanceSqTest4) == distanceSqAnswer2);

	vector2<float> distanceTest{ 1.f, 5.f };
	vector2<float> distanceTest2{ 5.f, 1.f };
	float distanceAnswer{ 4.f * sqrtf(2.f) };
	REQUIRE(distance_between(distanceTest, distanceTest2) == distanceAnswer);

	vector2<float> distanceTest3{ 10.f, 13.f };
	vector2<float> distanceTest4{ 6.f, 10.f };
	float distanceAnswer2{ 5.f };
	REQUIRE(distance_between(distanceTest3, distanceTest4) == distanceAnswer2);

	float angle = angle_between(vector2<float>(1.f, 0.f), vector2<float>(0.f, 1.f));
	REQUIRE(angle == ANGLE::PI / 2);

	vector2<float> rotateTest{ 1.f, 0.f };
	vector2<float> rotateAnswer{ -1.f, 0.f };
	REQUIRE(rotate_by(ANGLE::PI, rotateTest) == rotateAnswer);

	vector2<float> rotateTest2{ 0.f, 1.f };
	vector2<float> rotateAnswer2{ -1.f, 0.f };
	REQUIRE(rotate_by(ANGLE::HALF_PI, rotateTest2) == rotateAnswer);
}


TEST_CASE("Matrix Constructor")
{
	matrix3<float> mat_ctor_test1;
	REQUIRE(mat_ctor_test1.column0.x == 0.f);
	REQUIRE(mat_ctor_test1.column1.x == 0.f);
	REQUIRE(mat_ctor_test1.column2.x == 0.f);

	REQUIRE(mat_ctor_test1.column0.y == 0.f);
	REQUIRE(mat_ctor_test1.column1.y == 0.f);
	REQUIRE(mat_ctor_test1.column2.y == 0.f);

	REQUIRE(mat_ctor_test1.column0.z == 0.f);
	REQUIRE(mat_ctor_test1.column1.z == 0.f);
	REQUIRE(mat_ctor_test1.column2.z == 0.f);

	vector3<float> first = { 1.f,2.f,3.f };
	vector3<float> second = { 4.f,5.f,6.f };
	vector3<float> third = { 7.f,8.f,9.f };
	matrix3<float> mat_ctor_test2(first, second, third);

	REQUIRE(mat_ctor_test2.column0.x == 1.f);
	REQUIRE(mat_ctor_test2.column0.y == 2.f);
	REQUIRE(mat_ctor_test2.column0.z == 3.f);

	REQUIRE(mat_ctor_test2.column1.x == 4.f);
	REQUIRE(mat_ctor_test2.column1.y == 5.f);
	REQUIRE(mat_ctor_test2.column1.z == 6.f);

	REQUIRE(mat_ctor_test2.column2.x == 7.f);
	REQUIRE(mat_ctor_test2.column2.y == 8.f);
	REQUIRE(mat_ctor_test2.column2.z == 9.f);

	matrix3<float> mat_ctor_test3(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);

	REQUIRE(mat_ctor_test3.column0.x == 1.f);
	REQUIRE(mat_ctor_test3.column0.y == 2.f);
	REQUIRE(mat_ctor_test3.column0.z == 3.f);

	REQUIRE(mat_ctor_test3.column1.x == 4.f);
	REQUIRE(mat_ctor_test3.column1.y == 5.f);
	REQUIRE(mat_ctor_test3.column1.z == 6.f);

	REQUIRE(mat_ctor_test3.column2.x == 7.f);
	REQUIRE(mat_ctor_test3.column2.y == 8.f);
	REQUIRE(mat_ctor_test3.column2.z == 9.f);
}

TEST_CASE("operator()")
{

	matrix3<float> mat_test(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);


	REQUIRE(mat_test(0, 0) == 1.f);
	REQUIRE(mat_test(0, 1) == 2.f);
	REQUIRE(mat_test(0, 2) == 3.f);
	REQUIRE(mat_test(1, 0) == 4.f);
	REQUIRE(mat_test(1, 1) == 5.f);
	REQUIRE(mat_test(1, 2) == 6.f);
	REQUIRE(mat_test(2, 0) == 7.f);
	REQUIRE(mat_test(2, 1) == 8.f);
	REQUIRE(mat_test(2, 2) == 9.f);


}

TEST_CASE("matrix3 operator*")
{
	matrix3<float> first_mat_test(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	matrix3<float> first_mat_test2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	matrix3<float> first_result = first_mat_test * first_mat_test2;

	matrix3<float> real_result(30.f, 36.f, 42.f, 66.f, 81.f, 96.f, 102.f, 126.f, 150.f);

	REQUIRE(first_result(0, 0) == real_result(0, 0));
	REQUIRE(first_result(0, 1) == real_result(0, 1));
	REQUIRE(first_result(0, 2) == real_result(0, 2));
	REQUIRE(first_result(1, 0) == real_result(1, 0));
	REQUIRE(first_result(1, 1) == real_result(1, 1));
	REQUIRE(first_result(1, 2) == real_result(1, 2));
	REQUIRE(first_result(2, 0) == real_result(2, 0));
	REQUIRE(first_result(2, 1) == real_result(2, 1));
	REQUIRE(first_result(2, 2) == real_result(2, 2));

	matrix3<float> second_mat_test(1.f, 0.f, 3.f, -56.f, 88.f, -6.f, -14.f, 463.f, 9.f);
	matrix3<float> second_mat_test2(1.f, 0.f, -60.f, -4.f, 0.f, 0.f, 0.f, 73.f, 9.f);
	matrix3<float> second_result = second_mat_test * second_mat_test2;

	matrix3<float> second_real_result(841.f, -27780.f, -537.f, -4.f, 0.f, -12.f, -4214.f, 10591.f, -357.f);

	REQUIRE(second_result(0, 0) == second_real_result(0, 0));
	REQUIRE(second_result(0, 1) == second_real_result(0, 1));
	REQUIRE(second_result(0, 2) == second_real_result(0, 2));
	REQUIRE(second_result(1, 0) == second_real_result(1, 0));
	REQUIRE(second_result(1, 1) == second_real_result(1, 1));
	REQUIRE(second_result(1, 2) == second_real_result(1, 2));
	REQUIRE(second_result(2, 0) == second_real_result(2, 0));
	REQUIRE(second_result(2, 1) == second_real_result(2, 1));
	REQUIRE(second_result(2, 2) == second_real_result(2, 2));

}

TEST_CASE("matrix3 operator*=")
{
	matrix3<float> first_mat_test(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	matrix3<float> first_mat_test2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	first_mat_test *= first_mat_test2;

	matrix3<float> real_result(30.f, 36.f, 42.f, 66.f, 81.f, 96.f, 102.f, 126.f, 150.f);

	REQUIRE(first_mat_test(0, 0) == real_result(0, 0));
	REQUIRE(first_mat_test(0, 1) == real_result(0, 1));
	REQUIRE(first_mat_test(0, 2) == real_result(0, 2));
	REQUIRE(first_mat_test(1, 0) == real_result(1, 0));
	REQUIRE(first_mat_test(1, 1) == real_result(1, 1));
	REQUIRE(first_mat_test(1, 2) == real_result(1, 2));
	REQUIRE(first_mat_test(2, 0) == real_result(2, 0));
	REQUIRE(first_mat_test(2, 1) == real_result(2, 1));
	REQUIRE(first_mat_test(2, 2) == real_result(2, 2));

	matrix3<float> second_mat_test(1.f, 0.f, 3.f, -56.f, 88.f, -6.f, -14.f, 463.f, 9.f);
	matrix3<float> second_mat_test2(1.f, 0.f, -60.f, -4.f, 0.f, 0.f, 0.f, 73.f, 9.f);
	second_mat_test *= second_mat_test2;

	matrix3<float> second_real_result(841.f, -27780.f, -537.f, -4.f, 0.f, -12.f, -4214.f, 10591.f, -357.f);

	REQUIRE(second_mat_test(0, 0) == second_real_result(0, 0));
	REQUIRE(second_mat_test(0, 1) == second_real_result(0, 1));
	REQUIRE(second_mat_test(0, 2) == second_real_result(0, 2));
	REQUIRE(second_mat_test(1, 0) == second_real_result(1, 0));
	REQUIRE(second_mat_test(1, 1) == second_real_result(1, 1));
	REQUIRE(second_mat_test(1, 2) == second_real_result(1, 2));
	REQUIRE(second_mat_test(2, 0) == second_real_result(2, 0));
	REQUIRE(second_mat_test(2, 1) == second_real_result(2, 1));
	REQUIRE(second_mat_test(2, 2) == second_real_result(2, 2));

}

TEST_CASE("matrix3 operator* with vec")
{
	matrix3<float> first_mat_test(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	vector3<float> vec_test(1.f, 2.f, 3.f);
	vector3<float> result = first_mat_test * vec_test;

	vector3<float> real_result = { 30.f, 36.f, 42.f };

	REQUIRE(result.x == real_result.x);
	REQUIRE(result.y == real_result.y);
	REQUIRE(result.z == real_result.z);


	matrix3<float> second_mat_test(-30.f, 12.f, 0.f, -20.f, 593.f, 0.f, 0.f, 23.f, 23.f);
	vector3<float> vec_test2(0.f, -12.f, 23.f);
	vector3<float> result2 = second_mat_test * vec_test2;

	vector3<float> real_result2(240.f, -6587.f, 529.f);

	REQUIRE(result2.x == real_result2.x);
	REQUIRE(result2.y == real_result2.y);
	REQUIRE(result2.z == real_result2.z);
}

TEST_CASE("matrix3 transpose")
{
	matrix3<float> mat_test(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
	matrix3<float> result(1.f, 4.f, 7.f, 2.f, 5.f, 8.f, 3.f, 6.f, 9.f);
	mat_test = MATRIX3::transpose(mat_test);

	REQUIRE(mat_test(0, 0) == result(0, 0));
	REQUIRE(mat_test(0, 1) == result(0, 1));
	REQUIRE(mat_test(0, 2) == result(0, 2));
	REQUIRE(mat_test(1, 0) == result(1, 0));
	REQUIRE(mat_test(1, 1) == result(1, 1));
	REQUIRE(mat_test(1, 2) == result(1, 2));
	REQUIRE(mat_test(2, 0) == result(2, 0));
	REQUIRE(mat_test(2, 1) == result(2, 1));
	REQUIRE(mat_test(2, 2) == result(2, 2));
}

TEST_CASE("matrix3 rotation")
{
	matrix3<float> test = MATRIX3::build_rotation<float>(30.f);;

	matrix3<float> result(cos(30.f), sin(30.f), 0.f, -sin(30.f), cos(30.f), 0.f, 0.f, 0.f, 1.f);

	REQUIRE(test(0, 0) == result(0, 0));
	REQUIRE(test(0, 1) == result(0, 1));
	REQUIRE(test(0, 2) == result(0, 2));
	REQUIRE(test(1, 0) == result(1, 0));
	REQUIRE(test(1, 1) == result(1, 1));
	REQUIRE(test(1, 2) == result(1, 2));
	REQUIRE(test(2, 0) == result(2, 0));
	REQUIRE(test(2, 1) == result(2, 1));
	REQUIRE(test(2, 2) == result(2, 2));
}

TEST_CASE("matrix3 identity")
{
	matrix3<float> test = MATRIX3::build_identity(1.0f);

	matrix3<float> result(1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 1.f);

	REQUIRE(test(0, 0) == result(0, 0));
	REQUIRE(test(0, 1) == result(0, 1));
	REQUIRE(test(0, 2) == result(0, 2));
	REQUIRE(test(1, 0) == result(1, 0));
	REQUIRE(test(1, 1) == result(1, 1));
	REQUIRE(test(1, 2) == result(1, 2));
	REQUIRE(test(2, 0) == result(2, 0));
	REQUIRE(test(2, 1) == result(2, 1));
	REQUIRE(test(2, 2) == result(2, 2));
}

TEST_CASE("matrix3 scale_2float")
{
	matrix3<float> test = MATRIX3::build_scale<float>(10.f, 20.f);

	matrix3<float> result(10.f, 0.f, 0.f, 0.f, 20.f, 0.f, 0.f, 0.f, 1.f);

	REQUIRE(test(0, 0) == result(0, 0));
	REQUIRE(test(0, 1) == result(0, 1));
	REQUIRE(test(0, 2) == result(0, 2));
	REQUIRE(test(1, 0) == result(1, 0));
	REQUIRE(test(1, 1) == result(1, 1));
	REQUIRE(test(1, 2) == result(1, 2));
	REQUIRE(test(2, 0) == result(2, 0));
	REQUIRE(test(2, 1) == result(2, 1));
	REQUIRE(test(2, 2) == result(2, 2));
}

TEST_CASE("matrix3 scale_1float")
{
	matrix3<float> test = MATRIX3::build_scale<float>(10.f);

	matrix3<float> result(10.f, 0.f, 0.f, 0.f, 10.f, 0.f, 0.f, 0.f, 1.f);

	REQUIRE(test(0, 0) == result(0, 0));
	REQUIRE(test(0, 1) == result(0, 1));
	REQUIRE(test(0, 2) == result(0, 2));
	REQUIRE(test(1, 0) == result(1, 0));
	REQUIRE(test(1, 1) == result(1, 1));
	REQUIRE(test(1, 2) == result(1, 2));
	REQUIRE(test(2, 0) == result(2, 0));
	REQUIRE(test(2, 1) == result(2, 1));
	REQUIRE(test(2, 2) == result(2, 2));
}

TEST_CASE("matrix3 scale_vector")
{
	matrix3<float> test = MATRIX3::build_scale<float>({ 10.f,20.f });

	matrix3<float> result(10.f, 0.f, 0.f, 0.f, 20.f, 0.f, 0.f, 0.f, 1.f);

	REQUIRE(test(0, 0) == result(0, 0));
	REQUIRE(test(0, 1) == result(0, 1));
	REQUIRE(test(0, 2) == result(0, 2));
	REQUIRE(test(1, 0) == result(1, 0));
	REQUIRE(test(1, 1) == result(1, 1));
	REQUIRE(test(1, 2) == result(1, 2));
	REQUIRE(test(2, 0) == result(2, 0));
	REQUIRE(test(2, 1) == result(2, 1));
	REQUIRE(test(2, 2) == result(2, 2));
}

TEST_CASE("matrix3 translation_2float")
{
	matrix3<float> test = MATRIX3::build_translation<float>(10.f, 25.f);

	matrix3<float> result(1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 10.f, 25.f, 1.f);

	REQUIRE(test(0, 0) == result(0, 0));
	REQUIRE(test(0, 1) == result(0, 1));
	REQUIRE(test(0, 2) == result(0, 2));
	REQUIRE(test(1, 0) == result(1, 0));
	REQUIRE(test(1, 1) == result(1, 1));
	REQUIRE(test(1, 2) == result(1, 2));
	REQUIRE(test(2, 0) == result(2, 0));
	REQUIRE(test(2, 1) == result(2, 1));
	REQUIRE(test(2, 2) == result(2, 2));
}


TEST_CASE("matrix3 translation_vector")
{
	matrix3<float> test = MATRIX3::build_translation<float>({ 10.f, 25.f });

	matrix3<float> result(1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 10.f, 25.f, 1.f);

	REQUIRE(test(0, 0) == result(0, 0));
	REQUIRE(test(0, 1) == result(0, 1));
	REQUIRE(test(0, 2) == result(0, 2));
	REQUIRE(test(1, 0) == result(1, 0));
	REQUIRE(test(1, 1) == result(1, 1));
	REQUIRE(test(1, 2) == result(1, 2));
	REQUIRE(test(2, 0) == result(2, 0));
	REQUIRE(test(2, 1) == result(2, 1));
	REQUIRE(test(2, 2) == result(2, 2));
}

TEST_CASE("vector3<float> default constructor")
{
	vector3<float> test_vector;

	REQUIRE(test_vector.x == 0.0f);
	REQUIRE(test_vector.y == 0.0f);
	REQUIRE(test_vector.z == 0.0f);
}

TEST_CASE("vector3<float> repeated value constructor")
{
	vector3<float> test_vector(1.0f);

	REQUIRE(test_vector.x == 1.0f);
	REQUIRE(test_vector.y == 1.0f);
	REQUIRE(test_vector.z == 1.0f);
}

TEST_CASE("vector3<float> constructor")
{
	vector3<float> test_vector(0.0f, 1.0f, -1.0f);

	REQUIRE(test_vector.x == 0.0f);
	REQUIRE(test_vector.y == 1.0f);
	REQUIRE(test_vector.z == -1.0f);
}


TEST_CASE("vector3<float> operator-=")
{
	vector3<float> test_vector_1(10.0f, -10.0f, 0.0f);
	vector3<float> test_vector_2(10.0f, -10.0f, 0.0f);

	test_vector_1 -= test_vector_2;

	REQUIRE(test_vector_1.x == 0.0f);
	REQUIRE(test_vector_1.y == 0.0f);
	REQUIRE(test_vector_1.z == 0.0f);
}

TEST_CASE("vector3<float> operator*=")
{
	vector3<float> test_vector_1(1.0f, -1.0f, 0.0f);
	float scale = 5.0f;

	test_vector_1 *= scale;

	REQUIRE(test_vector_1.x == 5.0f);
	REQUIRE(test_vector_1.y == -5.0f);
	REQUIRE(test_vector_1.z == 0.0f);
}

TEST_CASE("vector3<float> operator/=")
{
	vector3<float> test_vector_1(5.0f, -5.0f, 0.0f);
	vector3<float> test_vector_2(0.5f, -0.1f, 0.0001f);
	float divisor = 5.0f;

	test_vector_1 /= divisor;
	test_vector_2 /= divisor;

	REQUIRE(test_vector_1.x == 1.0f);
	REQUIRE(test_vector_1.y == -1.0f);
	REQUIRE(test_vector_1.z == 0.0f);

	REQUIRE(test_vector_2.x == 0.1f);
	REQUIRE(test_vector_2.y == -0.02f);
	REQUIRE(test_vector_2.z == 0.00002f);
}


TEST_CASE("vector3<float> operator- negation")
{
	vector3<float> test_vector_1(5.0f, -5.0f, 0.0f);
	vector3<float> negated_vector;

	negated_vector = -test_vector_1;

	REQUIRE(negated_vector.x == -5.0f);
	REQUIRE(negated_vector.y == 5.0f);
	REQUIRE(negated_vector.z == 0.0f);
}


TEST_CASE("vector3<float> operator+")
{
	vector3<float> test_vector_1(5.0f, -5.0f, 123.235f);
	vector3<float> test_vector_2(10.0f, -5.0f, -29.4526f);
	vector3<float> sum;

	sum = test_vector_1 + test_vector_2;

	REQUIRE(sum.x == 15.0f);
	REQUIRE(sum.y == -10.0f);
	REQUIRE(sum.z == 93.7824f);
}


TEST_CASE("vector3<float> operator-")
{
	vector3<float> test_vector_1(5.0f, -5.0f, 123.235f);
	vector3<float> test_vector_2(10.0f, -5.0f, -29.4526f);
	vector3<float> subtraction;

	subtraction = test_vector_1 - test_vector_2;

	REQUIRE(subtraction.x == -5.0f);
	REQUIRE(subtraction.y == 0.0f);
	REQUIRE(subtraction.z == 152.6876f);
}

TEST_CASE("vector3<float> operator* : vector3 * float")
{
	vector3<float> test_vector_1(5.0f, -534.0f, 123.23f);
	float scale_1 = 0.0f;
	float scale_2 = -0.05f;
	float scale_3 = 29.45f;
	vector3<float> result_1;
	vector3<float> result_2;
	vector3<float> result_3;

	result_1 = test_vector_1 * scale_1;
	result_2 = test_vector_1 * scale_2;
	result_3 = test_vector_1 * scale_3;

	REQUIRE(result_1.x == 0.0f);
	REQUIRE(result_1.y == 0.0f);
	REQUIRE(result_1.z == 0.0f);

	REQUIRE(result_2.x == Approx(-0.25f).epsilon(0.001));
	REQUIRE(result_2.y == Approx(26.7f).epsilon(0.001));
	REQUIRE(result_2.z == Approx(-6.1615f).epsilon(0.001));

	REQUIRE(result_3.x == Approx(147.25f).epsilon(0.001));
	REQUIRE(result_3.y == Approx(-15726.3f).epsilon(0.001));
	REQUIRE(result_3.z == Approx(3629.1235f).epsilon(0.001));
}

TEST_CASE("vector3<float> operator* : float * vector3")
{

	vector3<float> test_vector_1(5.0f, -534.0f, 123.23f);
	float scale_1 = 0.0f;
	float scale_2 = -0.05f;
	float scale_3 = 29.45f;
	vector3<float> result_1;
	vector3<float> result_2;
	vector3<float> result_3;

	result_1 = scale_1 * test_vector_1;
	result_2 = scale_2 * test_vector_1;
	result_3 = scale_3 * test_vector_1;

	REQUIRE(result_1.x == 0.0f);
	REQUIRE(result_1.y == 0.0f);
	REQUIRE(result_1.z == 0.0f);

	REQUIRE(result_2.x == Approx(-0.25f).epsilon(0.001));
	REQUIRE(result_2.y == Approx(26.7f).epsilon(0.001));
	REQUIRE(result_2.z == Approx(-6.1615f).epsilon(0.001));

	REQUIRE(result_3.x == Approx(147.25f).epsilon(0.001));
	REQUIRE(result_3.y == Approx(-15726.3f).epsilon(0.001));
	REQUIRE(result_3.z == Approx(3629.1235f).epsilon(0.001));
}

TEST_CASE("vector3<float> operator/ ")
{
	vector3<float> test_vector_1(3.0f, -17.0f, 16.78f);
	float divisor_1 = 7.0f;
	float divisor_2 = -3.0f;
	float divisor_3 = 0.032f;
	vector3<float> result_1;
	vector3<float> result_2;
	vector3<float> result_3;

	result_1 = test_vector_1 / divisor_1;
	result_2 = test_vector_1 / divisor_2;
	result_3 = test_vector_1 / divisor_3;

	REQUIRE(result_1.x == Approx(0.4285f).epsilon(0.001));
	REQUIRE(result_1.y == Approx(-2.4285f).epsilon(0.001));
	REQUIRE(result_1.z == Approx(2.39714f).epsilon(0.001));

	REQUIRE(result_2.x == Approx(-1.0f).epsilon(0.001));
	REQUIRE(result_2.y == Approx(5.6666f).epsilon(0.001));
	REQUIRE(result_2.z == Approx(-5.5933f).epsilon(0.001));

	REQUIRE(result_3.x == Approx(93.75f).epsilon(0.001));
	REQUIRE(result_3.y == Approx(-531.25f).epsilon(0.001));
	REQUIRE(result_3.z == Approx(524.375f).epsilon(0.001));
}

TEST_CASE("vector3<float> operator== ")
{
	vector3<float> test_vector_1(1.56f, -29.25f, 12348.213f);
	vector3<float> test_vector_2(1.56f, -29.25f, 12348.213f);

	bool compare = (test_vector_1 == test_vector_2);

	REQUIRE(compare == 1);
}

TEST_CASE("vector3<float> operator!= ")
{
	vector3<float> test_vector_1(1.56f, -29.25f, 12348.213f);
	vector3<float> test_vector_2(-1.56f, -24.25f, 21548.3f);

	bool compare = (test_vector_1 != test_vector_2);

	REQUIRE(compare == 1);
}

TEST_CASE("vector3<float> dot ")
{
	vector3<float> test_vector_1(1.56f, -29.25f, 18.23f);
	vector3<float> test_vector_2(-1.82f, -15.97f, 48.3f);

	float dot_product = dot(test_vector_1, test_vector_2);

	REQUIRE(dot_product == Approx(1344.7923f).epsilon(0.0001));
}

TEST_CASE("vector3<float> cross ")
{
	vector3<float> test_vector_1(1.56f, -29.25f, 18.23f);
	vector3<float> test_vector_2(-1.82f, -15.97f, 48.3f);

	vector3<float> cross_product = cross(test_vector_1, test_vector_2);

	REQUIRE(cross_product.x == Approx(-1121.6419).epsilon(0.0001));
	REQUIRE(cross_product.y == Approx(-108.5266).epsilon(0.0001));
	REQUIRE(cross_product.z == Approx(-78.1482).epsilon(0.0001));
}

TEST_CASE("vector3<float> magnitude_squared ")
{
	vector3<float> test_vector_1(1.56f, -29.25f, 18.23f);

	float mag_sqr = magnitude_squared(test_vector_1);

	REQUIRE(mag_sqr == Approx(1190.329).epsilon(0.001));
}

TEST_CASE("vector3<float> magnitude ")
{
	vector3<float> test_vector_1(1.56f, -29.25f, 18.23f);

	float mag = magnitude(test_vector_1);

	REQUIRE(mag == Approx(34.5011f).epsilon(0.0001));
}

TEST_CASE("vector3<float> normalize ")
{
	vector3<float> test_vector_1(1.56f, -29.25f, 18.23f);

	vector3<float> normalized = normalize(test_vector_1);

	REQUIRE(normalized.x == Approx(0.04521f).epsilon(0.001));
	REQUIRE(normalized.y == Approx(-0.84779f).epsilon(0.001));
	REQUIRE(normalized.z == Approx(0.52838f).epsilon(0.001));
}

TEST_CASE("vector3<float> distance_between_squared ")
{
	vector3<float> test_vector_1(1.56f, -29.25f, 18.23f);
	vector3<float> test_vector_2(2.32f, 9.12f, -7.1f);

	float distance = distance_between_squared(test_vector_1, test_vector_2);

	REQUIRE(distance == Approx(2114.4433f).epsilon(0.001));
}

TEST_CASE("vector3<float> distance_between ")
{
	vector3<float> test_vector_1(1.56f, -29.25f, 18.23f);
	vector3<float> test_vector_2(2.32f, 9.12f, -7.1f);

	float distance = distance_between(test_vector_1, test_vector_2);

	REQUIRE(distance == Approx(45.9830f).epsilon(0.001));
}

TEST_CASE("vector3<float> angle_between ")
{
	vector3<float> test_vector_1(1.56f, -29.25f, 18.23f);
	vector3<float> test_vector_2(2.32f, 9.12f, -7.1f);

	float angle = angle_between(test_vector_1, test_vector_2);

	REQUIRE(angle == Approx(2.8771f).epsilon(0.001));
}