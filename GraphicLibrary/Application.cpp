#include "Application.hpp"

Application* Application::application = nullptr;


namespace
{
	void    key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void    cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	void    mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void    scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	//void	framebuffer_size_callback(GLFWwindow* window, int width, int height);
	bool    is_full = false;
}


void Application::Init()
{
	//c.load
	if (!glfwInit())
	{
		glfwTerminate();
		return;
	}


	GLenum glew_err_check;

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RED_BITS, 8);
	glfwWindowHint(GLFW_GREEN_BITS, 8);
	glfwWindowHint(GLFW_BLUE_BITS, 8);
	glfwWindowHint(GLFW_DEPTH_BITS, 24);

	window = glfwCreateWindow(1280, 720, "CS200_JeesooKim", nullptr, nullptr);

	glfwMakeContextCurrent(window);
	/*glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwGetFramebufferSize(window, &width, &height);*/
	if (!window)
	{
		glfwTerminate();
		return;
	}
	glew_err_check = glewInit();

	if (glew_err_check != GLEW_NO_ERROR)
	{
		glfwTerminate();
		return;
	}

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	glfwSetWindowMonitor(window, nullptr,
		100,
		80,
		static_cast<int>(1280),
		static_cast<int>(720), 0);
	window_size = { 1280, 720 };
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetScrollCallback(window, scroll_callback);

	glfwSwapInterval(true);
}
//void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}

void Application::Update(float dt)
{
	input.Triggered_Reset();

	glfwSwapBuffers(window);
	glfwPollEvents();

	int w, h;
	glfwGetWindowSize(window, &w, &h);
	window_size.width = (float)w;
	window_size.height = (float)h;

	if (input.Is_Key_Triggered(GLFW_KEY_F))
	{
		Toggle_Fullscreen();
	}
	if (input.Is_Key_Triggered(GLFW_KEY_K))
	{
		Save();
	}
	if (input.Is_Key_Triggered(GLFW_KEY_R))
	{
		Clear();

	}


	temp_dt += dt;
	if (temp_dt >= 1.0f)
	{
		std::stringstream title;
		title << "CS200_JeesooKim" << " " << " [" << FPS_frame << " FPS]";
		glfwSetWindowTitle(window, title.str().c_str());
		FPS_frame = 0;
		temp_dt = 0;
	}
	FPS_frame++;

	if (input.Is_Key_Triggered(GLFW_KEY_ESCAPE))
	{
		exit(0);
	}
	if (input.Is_Key_Triggered(GLFW_KEY_V))
	{
		is_vsync_on = !is_vsync_on;
		TurnOnMonitorVerticalSynchronization(is_vsync_on);
	}
}
void Application::Delete()
{

}

void Application::Save()
{
}

void Application::Clear()
{
}
bool Application::IsFullScreen()
{
	return glfwGetWindowMonitor(window);
}

void Application::TurnOnMonitorVerticalSynchronization(bool enable)
{
	is_vsync_on = enable;
	glfwSwapInterval(enable);
}

void Application::Toggle_Fullscreen()
{
	if (!IsFullScreen())
	{
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		glfwGetWindowPos(window, &x_pos, &y_pos);
		glfwGetWindowSize(window, &width, &height);
		glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
		glViewport(0, 0, mode->width, mode->height);
		TurnOnMonitorVerticalSynchronization(is_vsync_on);
	}
	else
	{
		glfwSetWindowMonitor(window, nullptr, x_pos, y_pos, width, height, 0);
		glViewport(0, 0, width, height);
	}
	glfwSwapBuffers(window);
	glfwSwapInterval(true);
}

Application* Application::Get_Application()
{
	if (application == nullptr)
		application = new Application;

	return application;
}

namespace
{
	void mouse_button_callback(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
	{
		input.Set_Mouse_Input(button, action);
	}
	void cursor_position_callback(GLFWwindow* /*window*/, double xpos, double ypos)
	{
		input.Set_Mouse_Position(xpos, ypos);
	}
	void key_callback(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
	{
		input.Set_Keyboard_Input(key, action);
	}
	void scroll_callback(GLFWwindow* /*window*/, double xoffset, double yoffset)
	{
		input.Set_Mouse_Wheel(xoffset, yoffset);
	}
	/*void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}*/
}
