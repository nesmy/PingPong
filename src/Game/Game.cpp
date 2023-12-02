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

void Game::vec2_norm(float &x, float &y)
{
    // sets a vectors length to 1 (which means that x + y == 1)
        float length = sqrt((x * x) + (y * y));
        if (length != 0.0f) {
            length = 1.0f / length;
            x *= length;
            y *= length;
        }
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
void Game::OnInput()
{
    positionB.x += Ball_dir_x * Ball_speed;
    positionB.y += Ball_dir_y * Ball_speed;

    // hit left board
    if (positionB.x < positionP.x + boardsize.x &&
        positionB.x > positionP.x &&
        positionB.y < positionP.y + boardsize.y &&
        positionB.y > positionP.y)
        {
        // set fly direction depending on where it hit the m_Racket
        // (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)
            float t = ((positionB.y - positionP.y)/ boardsize.y) - 0.5f;
            Ball_dir_x = fabs(Ball_dir_x); // force it to be positive
            Ball_dir_y = t;
        }
    
    // hit right board
    if (positionB.x > positionC.x &&
        positionB.x < positionC.x + boardsize.x &&
        positionB.y < positionC.y + boardsize.y &&
        positionB.y > positionC.y)
        {
        // set fly direction depending on where it hit the m_Racket
        // (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)
            float t = ((positionB.y - positionC.y)/ boardsize.y) - 0.5f;
            positionB.x = -fabs(Ball_dir_x); // force it to be negative
            positionB.y = t;
        }

    // hit left wall?
    if (positionB.x < 0)
    {
        ++Score_right;
        positionB.x = app.GetWindow().GetWidth() / 2;
        positionB.y = app.GetWindow().GetHeight() / 2;
        Ball_dir_x = fabs(Ball_dir_x); // force it to be positive
        Ball_dir_y = 0;
    }

    // hit right wall?
    if (positionB.x > app.GetWindow().GetWidth())
    {
        ++Score_left;
        positionB.x = app.GetWindow().GetWidth() / 2;
        positionB.y = app.GetWindow().GetHeight() / 2;
        Ball_dir_x = -fabs(Ball_dir_x); // force it to be negative
        Ball_dir_y = 0;
    }

    //hit top wall?
    if (positionB.y > app.GetWindow().GetHeight())
    {
        Ball_dir_y = -fabs(Ball_dir_y); // force it to be negative
    }

    //hit top wall?
    if (positionB.y > app.GetWindow().GetHeight())
    {
        Ball_dir_y = fabs(Ball_dir_y); // force it to be positive
    }

    // make sure that length of dir stays at 1
    vec2_norm(Ball_dir_x, Ball_dir_y);
    if(Engine::Input::IsKeyPressed(87))
        positionP.y -= Speed;
    
    if(Engine::Input::IsKeyPressed(83))
        positionP.y += Speed;

    if(Engine::Input::IsKeyPressed(265))
        positionC.y -= Speed;
    
    if(Engine::Input::IsKeyPressed(264))
        positionC.y += Speed;
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
