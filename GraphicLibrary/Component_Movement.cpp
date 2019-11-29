#include "Component_Movement.hpp"
#include "Screenshot.hpp"
#include "Application.hpp"

void Movement::Init(Object* obj)
{
	m_owner = obj;
}

void Movement::Update(float dt)
{
	if (input.Is_Key_Pressed(GLFW_KEY_W))
	{
		m_owner->GetTransform().AddTranslation({ 0.0f, 1.0f });

		if (input.Is_Key_Pressed((GLFW_KEY_D)))
		{
			m_owner->GetTransform().AddTranslation({ 1.0f, 0.0f });
		}
		else if (input.Is_Key_Pressed((GLFW_KEY_A)))
		{
			m_owner->GetTransform().AddTranslation({ -1.0f, 0.0f });
		}

		m_owner->GetMesh().Get_Is_Moved() = true;
		m_owner->Set_Need_Update_Points(true);
	}
	else if (input.Is_Key_Pressed(GLFW_KEY_S))
	{
		m_owner->GetTransform().AddTranslation({ 0.0f, -1.0f });
		if (input.Is_Key_Pressed((GLFW_KEY_D)))
		{
			m_owner->GetTransform().AddTranslation({ 1.0f, 0.0f });
		}
		else if (input.Is_Key_Pressed((GLFW_KEY_A)))
		{
			m_owner->GetTransform().AddTranslation({ -1.0f, 0.0f });
		}
		m_owner->GetMesh().Get_Is_Moved() = true;
		m_owner->Set_Need_Update_Points(true);

	}
	else if (input.Is_Key_Pressed((GLFW_KEY_A)))
	{
		m_owner->GetTransform().AddTranslation({ -1.0f, 0.0f });
		
		m_owner->GetMesh().Get_Is_Moved() = true;
		m_owner->Set_Need_Update_Points(true);
	}
	else if (input.Is_Key_Pressed((GLFW_KEY_D)))
	{
		m_owner->GetTransform().AddTranslation({ 1.0f, 0.0f });
		
		m_owner->GetMesh().Get_Is_Moved() = true;
		m_owner->Set_Need_Update_Points(true);
	}

	if (input.Is_Key_Pressed(GLFW_KEY_Q))
	{
		float original_rotation = m_owner->GetTransform().GetRotation();
		m_owner->GetTransform().SetRotation(++original_rotation);

		m_owner->GetMesh().Get_Is_Moved() = true;
		m_owner->Set_Need_Update_Points(true);
	}
	if (input.Is_Key_Pressed(GLFW_KEY_E))
	{
		float original_rotation = m_owner->GetTransform().GetRotation();
		m_owner->GetTransform().SetRotation(--original_rotation);

		m_owner->GetMesh().Get_Is_Moved() = true;
		m_owner->Set_Need_Update_Points(true);
	}
	if (input.Is_Key_Pressed(GLFW_KEY_Z))
	{
		float original_scale = m_owner->GetTransform().GetScale().x;
		original_scale += (0.01);
		m_owner->GetTransform().SetScale(original_scale);

		m_owner->GetMesh().Get_Is_Moved() = true;
		m_owner->Set_Need_Update_Points(true);
	}
	if (input.Is_Key_Pressed(GLFW_KEY_C))
	{
		float original_scale = m_owner->GetTransform().GetScale().x;
		original_scale -= (0.01);
		m_owner->GetTransform().SetScale(original_scale);

		m_owner->GetMesh().Get_Is_Moved() = true;
		m_owner->Set_Need_Update_Points(true);
	}
	if (input.Is_Key_Pressed(GLFW_KEY_SPACE))
	{
		m_owner->GetTransform().SetRotation(0);
		m_owner->GetTransform().SetScale(1);

		m_owner->GetMesh().Get_Is_Moved() = true;
		m_owner->Set_Need_Update_Points(true);
	}
	if (input.Is_Key_Pressed(GLFW_KEY_CAPS_LOCK))
	{
		Application* currentApp = Application::Get_Application();
		vector2<float> windowSize;
		windowSize = currentApp->Get_Window_Size();
		auto screenShot = capture_screenshot_of_back_buffer_to_image(windowSize.x, windowSize.y);
		screenShot.SaveToPNG("Screenshot.png");

	}
}