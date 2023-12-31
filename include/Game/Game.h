#include "Application.h"
#include "Engine.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

class Game : public Engine::Application
{
public:
	Game();
	~Game();

	void vec2_norm(float& x, float&y);
	void Setup();
	void OnInput();
	void OnRender();

	Engine::Application& app = Engine::Application::Get();

	Engine::SpriteRenderer* Renderer;
	Engine::Texture2D ball;
	Engine::Texture2D player;
	Engine::Texture2D computer;
	Engine::Texture2D background;
	glm::vec2 positionP =  glm::vec2(0.0f, app.GetWindow().GetHeight()/2 - 120.0f);
	glm::vec2 positionC =  glm::vec2(app.GetWindow().GetWidth() - 17.0f, (app.GetWindow().GetHeight()/2) - 120.0f);
	glm::vec2 positionB =  glm::vec2((app.GetWindow().GetWidth()/2), (app.GetWindow().GetHeight()/2));
	glm::vec2 positionBG =  glm::vec2(0.0f, 0.0f);
	glm::vec2 boardsize = glm::vec2(17.0f, 120.0f);
	glm::vec2 ballsize = glm::vec2(30.0f, 30.0f);
	glm::vec2 bgsize = glm::vec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());
private:
	int Score_left = 0;
	int Score_right = 0;
	float Ball_dir_x = -1.0f;
	float Ball_dir_y = 1.0f;
	int Ball_speed = 1;
	int Speed = 5;
};
