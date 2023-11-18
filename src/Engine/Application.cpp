#include "Application.h"

#include "Log.h"


#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Engine {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
		//m_Window->
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		Setup();
		
		while (m_Running)
		{
			
			m_Window->OnUpdate();
			OnRender();
			
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		EN_CORE_TRACE("{0}", e);

		//for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		//{
		//	(*--it)->OnEvent(e);
		//	if (e.Handled)
		//		break;
		//}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}
