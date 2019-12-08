/*
*Jeesoo Kim
*Class Project
*CS200
*Fall 2019
*/
#include "Engine.hpp"
#include "Application.hpp"
#include "StateManager.hpp"
#include "ObjectManager.hpp"
#include "Graphic.hpp"
#include "../CS200_Jeesoo/Start.hpp"
#include "../CS200_Jeesoo/demo1.hpp"
#include "../CS200_Jeesoo/demo2.hpp"


namespace
{
	Application* m_app = nullptr;
	Graphic* m_graphic = nullptr;
	StateManager* m_stateManager = nullptr;
	ObjectManager* m_objectManager = nullptr;
}

void Engine::Init()
{
	m_app = Application::Get_Application();
	m_app->Init();
	m_objectManager = ObjectManager::GetObjectManager();
	m_objectManager->Init();
	m_stateManager = StateManager::GetStateManager();
	m_stateManager->Init();
	m_graphic = Graphic::GetGraphic();
	m_graphic->Init();
	m_stateManager->AddState("Start", new Start);
	m_stateManager->AddState("Demo1", new Demo1);
	m_stateManager->AddState("Demo2", new Demo2);

}

void Engine::Update()
{
	m_dt = timer.GetElapsedSeconds();
	timer.Reset();
	m_app->Update(m_dt);
	m_stateManager->Update(m_dt);
	m_graphic->Update(m_dt);
	m_objectManager->Update(m_dt);

	Reset();

	if (input.Is_Key_Triggered(GLFW_KEY_1))
	{
		m_stateManager->is_pause = !m_stateManager->is_pause;
		std::cout << "PAUSED!\n";
	}
}

void Engine::Clear() 
{
	m_app->Clear();
}

void Engine::Delete()
{
	//object delete
}

void Engine::Reset()
{
	if (Graphic::GetGraphic()->get_need_update_sprite())
	{
		Graphic::GetGraphic()->get_need_update_sprite() = false;
	}
}
bool Engine::IsDone()
{
	return Is_Done;
}