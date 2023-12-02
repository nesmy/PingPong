#include "Game.h"

#include "ResourceManager.h"
#include "Texture.h"
#include "fwd.hpp"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "glad/glad.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Setup()
{
    
	Engine::ResourceManager::LoadShader("Assets/shaders/Basic.shader", nullptr, "sprite");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(app.GetWindow().GetWidth()),
        static_cast<float>(app.GetWindow().GetHeight()), 0.0f, -1.0f, 1.0f);
    Engine::ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    Engine::ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Engine::Shader shader = Engine::ResourceManager::GetShader("sprite");
    Renderer = new Engine::SpriteRenderer(shader);
    // load textures
    Engine::ResourceManager::LoadTexture("Assets/png/Ball.png", true, "ball");

	Engine::ResourceManager::LoadTexture("Assets/png/Player.png",true, "player");
   
	Engine::ResourceManager::LoadTexture("Assets/png/Computer.png", true, "computer");
	Engine::ResourceManager::LoadTexture("Assets/png/Board.png", true, "back");

}
void Game::OnInput(Engine::Event &e)
{
    EN_INFO("test, {0}", e.GetEventType());
}

void Game::OnRender()
{ 
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //EN_INFO("test");
    
    Engine::Texture2D ball = Engine::ResourceManager::GetTexture("ball");
	Engine::Texture2D player = Engine::ResourceManager::GetTexture("player");
	Engine::Texture2D computer = Engine::ResourceManager::GetTexture("computer");
	Engine::Texture2D back = Engine::ResourceManager::GetTexture("back");

	Renderer->DrawSprite(back, positionBG, bgsize, 0.0f);
    Renderer->DrawSprite(ball, positionB, ballsize, 0.0f);
	Renderer->DrawSprite(player, positionP, boardsize, 0.0f);
	Renderer->DrawSprite(computer, positionC, boardsize, 0.0f);
    
    ImGui::Begin("Test");
    ImGui::SliderFloat2("PositionP", &positionP.y, 0.0f, (app.GetWindow().GetHeight() - boardsize.y));
    ImGui::SliderFloat2("PositionC", &positionC.y, 0.0f, (app.GetWindow().GetHeight() - boardsize.y));
    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}



Engine::Application* Engine::CreateApplication()
{
	return new Game();
}
