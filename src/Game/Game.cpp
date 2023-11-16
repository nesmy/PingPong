#include <iostream>
#include "Log.h"

int main(int argc, char* argv[])
{
	Engine::Log::Init();
	EN_CORE_INFO("Hello World!");
	while (true);
	return 0;
}