/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
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

	GLFWwindow* window{};
	GLFWmonitor* monitor{};
	bool is_vsync_on = false;
	int x_pos = 0, y_pos = 0;
	int width = 1280 , height = 720;

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
