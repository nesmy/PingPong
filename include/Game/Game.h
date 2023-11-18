#include "Engine.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

class Game : public Engine::Application
{
public:
	Game();
	~Game();

	void Setup() override;
	void OnRender() override;

	Engine::SpriteRenderer* Renderer;
	glm::vec2 position =  glm::vec2(0, 0);
};