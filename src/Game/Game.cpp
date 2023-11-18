#include "Game.h"

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

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(1280),
        static_cast<float>(720), 0.0f, -1.0f, 1.0f);
    Engine::ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    Engine::ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Engine::Shader shader = Engine::ResourceManager::GetShader("sprite");
    Renderer = new Engine::SpriteRenderer(shader);
    // load textures
    Engine::ResourceManager::LoadTexture("Assets/png/Ball.png", true, "ball");
    Engine::ResourceManager::LoadTexture("Assets/png/Player.png", true, "player");
    Engine::ResourceManager::LoadTexture("Assets/png/Computer.png", true, "ai");
    Engine::ResourceManager::LoadTexture("Assets/png/Board.png", true, "background");
    

}

void Game::OnRender()
{
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Begin("Test");
    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
    //EN_INFO("test");
    
    Engine::Texture2D ball = Engine::ResourceManager::GetTexture("ball");
    Engine::Texture2D player = Engine::ResourceManager::GetTexture("player");
    Engine::Texture2D ai = Engine::ResourceManager::GetTexture("ai");
    // draw background
    Engine::Texture2D back = Engine::ResourceManager::GetTexture("background");
    Renderer->DrawSprite(back, glm::vec2(0.0f, 0.0f), glm::vec2(1280, 720), 0.0f);
    Renderer->DrawSprite(ball, glm::vec2(1280 / 2 - 15, 720 / 2 - 30), glm::vec2(30, 30), 0.0f);
    Renderer->DrawSprite(player, glm::vec2(0.0f, 0.0f), glm::vec2(17, 120), 0.0f);
    Renderer->DrawSprite(ai, glm::vec2(1280.0f - 17.0f, 0.0f), glm::vec2(17, 120), 0.0f);
    
}


Engine::Application* Engine::CreateApplication()
{
	return new Game();
}