#include "Camera.hpp"

matrix3<float> Helper_build_world_to_camera(vector2<float> center_vec, vector2<float> up_vec, vector2<float> right_vec)
{
	return{
		right_vec.x,right_vec.y, (-right_vec.x * center_vec.x) + (-right_vec.y * center_vec.y),
		up_vec.x, up_vec.y, (-up_vec.x * center_vec.x) + (-up_vec.y * center_vec.y),
		0,0,1
	};
}

matrix3<float> helper_inverse_camera(matrix3<float> model_to_world)
{
	double det = model_to_world(0, 0) * (model_to_world(1, 1) * model_to_world(2, 2) - model_to_world(2, 1) * model_to_world(1, 2)) -
		model_to_world(0, 1) * (model_to_world(1, 0) * model_to_world(2, 2) - model_to_world(1, 2) * model_to_world(2, 0)) +
		model_to_world(0, 2) * (model_to_world(1, 0) * model_to_world(2, 1) - model_to_world(1, 1) * model_to_world(2, 0));

	double invdet = 1 / det;

	matrix3<float> minv;
	minv(0, 0) = static_cast<float>((model_to_world(1, 1) * model_to_world(2, 2) - model_to_world(2, 1) * model_to_world(1, 2)) * invdet);
	minv(0, 1) = static_cast<float>((model_to_world(0, 2) * model_to_world(2, 1) - model_to_world(0, 1) * model_to_world(2, 2)) * invdet);
	minv(0, 2) = static_cast<float>((model_to_world(0, 1) * model_to_world(1, 2) - model_to_world(0, 2) * model_to_world(1, 1)) * invdet);
	minv(1, 0) = static_cast<float>((model_to_world(1, 2) * model_to_world(2, 0) - model_to_world(1, 0) * model_to_world(2, 2)) * invdet);
	minv(1, 1) = static_cast<float>((model_to_world(0, 0) * model_to_world(2, 2) - model_to_world(0, 2) * model_to_world(2, 0)) * invdet);
	minv(1, 2) = static_cast<float>((model_to_world(1, 0) * model_to_world(0, 2) - model_to_world(0, 0) * model_to_world(1, 2)) * invdet);
	minv(2, 0) = static_cast<float>((model_to_world(1, 0) * model_to_world(2, 1) - model_to_world(2, 0) * model_to_world(1, 1)) * invdet);
	minv(2, 1) = static_cast<float>((model_to_world(2, 0) * model_to_world(0, 1) - model_to_world(0, 0) * model_to_world(2, 1)) * invdet);
	minv(2, 2) = static_cast<float>((model_to_world(0, 0) * model_to_world(1, 1) - model_to_world(1, 0) * model_to_world(0, 1)) * invdet);

	return minv;
}
Camera::Camera(vector2<float> camera_center, vector2<float> camera_up) noexcept
{
	center = camera_center;
	up = camera_up;
	right = perpendicular_to(-up);
}

void Camera::ResetUp(vector2<float> camera_up) noexcept
{
	up = camera_up;
	right = perpendicular_to(-up);
}

void Camera::MoveUp(float distance) noexcept
{
	SetCenter(vector2{ center.x + up.x * distance, center.y + distance * up.y });
}

void Camera::MoveRight(float distance) noexcept
{
	SetCenter(vector2{ center.x + right.x * distance, center.y + right.y * distance });
}

void Camera::Rotate(float angle_radians) noexcept
{
	up = rotate_by(angle_radians, up);
	right = perpendicular_to(-up);
}

matrix3<float> Camera::CameraToWorld() const noexcept
{
	matrix3<float> camera_to_world(right.x, right.y, 0, up.x, up.y, 0, center.x, center.y, 1);
	return camera_to_world;
}

matrix3<float> Camera::WorldToCamera() const noexcept
{
	matrix3<float> world_to_camera(right.x, up.x, 0, right.y, up.y, 0, -dot(right, center), -dot(up, center), 1);
	return world_to_camera;
}