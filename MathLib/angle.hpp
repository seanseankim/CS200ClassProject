#pragma once
namespace ANGLE
{
	float PI = 3.1415926535897932384626433832795f;
	float HALF_PI = PI / 2.0f;
	float QUARTER_PI = PI / 4.0f;
	float TWO_PI = 2.0f * PI;

	float to_radians(float angle_in_degrees) { return angle_in_degrees * PI / 180.0f; }
	float to_degrees(float angle_in_radians) { return angle_in_radians * 180.0f / PI; }
}
