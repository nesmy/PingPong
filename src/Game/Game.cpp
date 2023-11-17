#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

Engine::Application* Engine::CreateApplication()
{
	return new Game();
}