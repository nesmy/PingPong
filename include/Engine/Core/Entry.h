#include <iostream>
#include "enpch.h"

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char* argv[])
{
	Engine::Log::Init();
	EN_CORE_INFO("Starting Engine!");
	auto app = Engine::CreateApplication();
	app->Setup();
	app->Run();
	delete app;
	return 0;
}