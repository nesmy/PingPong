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
		virtual void Setup() {};
		void OnEvent(Event& e);
		virtual void OnRender() {};
		virtual void OnInput() {};
		
		inline static Application& Get() { return *s_Instance;}
		inline Window& GetWindow() { return *m_Window;}
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		SpriteRenderer* Renderer;
	private:
		static Application* s_Instance;
	};

	// to be define
	Application* CreateApplication();

}
