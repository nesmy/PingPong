#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "ResourceManager.h"
#include "SpriteRenderer.h"

namespace Engine {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		virtual void Setup() = 0;
		void OnEvent(Event& e);
		virtual void OnRender() {};
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		SpriteRenderer* Renderer;
	};

	// to be define
	Application* CreateApplication();

}