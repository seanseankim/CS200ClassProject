#include "View.hpp"
#include "Graphic.hpp"
#include "Application.hpp"
#include "Input.hpp"

void View::Init()
{
	cameraView.SetViewSize(1280, 720);
	vector2<float> save_window_size = Application::Get_Application()->Get_Window_Size();
	ndc = MATRIX3::build_scale(save_window_size.x / 2, save_window_size.y / 2);
}

void View::Update(float dt)
{
	//zoom in or out
	if (input.Mouse_Wheel_Scroll() < 0)
	{
		cameraView.AddZoom(-0.05f);
		input.Set_Mouse_Wheel(0.0, 0.0);
	}
	else if (input.Mouse_Wheel_Scroll() > 0)
	{
		cameraView.AddZoom(0.05f);
		input.Set_Mouse_Wheel(0.0, 0.0);
	}
	//rotate camera
	if (input.Is_Key_Pressed(GLFW_KEY_DELETE))
	{
		camera.Rotate(0.05f);
	}
	if (input.Is_Key_Pressed(GLFW_KEY_PAGE_DOWN))
	{
		camera.Rotate(-0.05f);
	}
	//reset camera
	if (input.Is_Key_Pressed(GLFW_KEY_END))
	{
		cameraView.SetZoom(0.7f);
		camera.ResetUp();
	}
	if (input.Is_Key_Pressed(GLFW_KEY_RIGHT))
	{
		vector2<float> new_center = camera.GetCenter();
		new_center.x += 1.0f;
		camera.SetCenter(new_center);
	}
	if (input.Is_Key_Pressed(GLFW_KEY_LEFT))
	{
		vector2<float> new_center = camera.GetCenter();
		new_center.x -= 1.0f;
		camera.SetCenter(new_center);
	}
	if (input.Is_Key_Pressed(GLFW_KEY_DOWN))
	{
		vector2<float> new_center = camera.GetCenter();
		new_center.y -= 1.0f;
		camera.SetCenter(new_center);
	}
	if (input.Is_Key_Pressed(GLFW_KEY_UP))
	{
		vector2<float> new_center = camera.GetCenter();
		new_center.y += 1.0f;
		camera.SetCenter(new_center);
	}
}

Camera& View::GetCamera()
{
	return camera;
}

CameraView& View::GetCameraView()
{
	return cameraView;
}

matrix3<float> View::GetNDC()
{
	return ndc;
}
