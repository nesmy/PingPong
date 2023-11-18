#include "Engine.h"

class Game : public Engine::Application
{
public:
	Game();
	~Game();

	void Setup() override;
	void OnRender() override;

	Engine::SpriteRenderer* Renderer;
};