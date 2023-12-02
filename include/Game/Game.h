#include "Application.h"
#include "Engine.h"

class Game : public Engine::Application
{
public:
	Game();
	~Game();

	void Setup();
	//void OnEvent(Engine::Event& e);
	void OnRender();

	Engine::SpriteRenderer* Renderer;
	Engine::Texture2D ball;
	Engine::Texture2D player;
	Engine::Texture2D computer;
	Engine::Texture2D background;
};
