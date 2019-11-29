#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <sstream>
#include "vector2.hpp"
#include "Input.hpp"
#include "vector2.hpp"


class Application
{
private:
	Application() {}
	static Application* application;

	GLFWwindow* window;
	bool is_vsync_on;
	int x_pos, y_pos;
	int width, height;

	float temp_dt = 0.0f;
	int FPS_frame = 0;

	vector2<float> window_size{};
	bool show_demo_window = true;

public:
	static Application* Get_Application();
	void Init();
	void Update(float dt);
	void Delete();
	bool IsFullScreen();
	void Toggle_Fullscreen();
	void Clear();
	void Save();

	void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	void TurnOnMonitorVerticalSynchronization(bool enable);

	vector2<float> Get_Window_Size()
	{
		return window_size;
	}
};
