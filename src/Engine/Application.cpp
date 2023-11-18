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
		
		ResourceManager::LoadShader("Assets/shaders/Basic.shader", nullptr, "sprite");

		glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(1280),
			static_cast<float>(720), 0.0f, -1.0f, 1.0f);
		ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
		ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
		// set render-specific controls
		Shader shader = ResourceManager::GetShader("sprite");
		Renderer = new SpriteRenderer(shader);
		// load textures
		ResourceManager::LoadTexture("Assets/png/Ball.jpg", false, "ball");
		
		while (m_Running)
		{
			
			m_Window->OnUpdate();
			OnRender();
			
			
			
			Texture2D ball = ResourceManager::GetTexture("sprite");
			Renderer->DrawSprite(ball, glm::vec2(0.0f, 0.0f), glm::vec2(1280, 720), 0.0f);
			
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
