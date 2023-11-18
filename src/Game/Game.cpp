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
    /*
	Engine::ResourceManager::LoadShader("Assets/shaders/Basic.shader", nullptr, "sprite");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(1280),
        static_cast<float>(720), 0.0f, -1.0f, 1.0f);
    Engine::ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    Engine::ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Engine::Shader shader = Engine::ResourceManager::GetShader("sprite");
    Renderer = new Engine::SpriteRenderer(shader);
    // load textures
    Engine::ResourceManager::LoadTexture("Assets/png/Ball.jpg", false, "ball");
    */

}

void Game::OnRender()
{
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Begin("Test");
    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    /*
    EN_INFO("test");
    
    Engine::Texture2D ball = Engine::ResourceManager::GetTexture("sprite");
    Renderer->DrawSprite(ball, glm::vec2(0.0f, 0.0f), glm::vec2(1280, 720), 0.0f);
    */
}


Engine::Application* Engine::CreateApplication()
{
	return new Game();
}