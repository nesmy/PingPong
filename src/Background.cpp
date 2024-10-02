#include "Background.h"

BG::BG(){
  Texture = BB::ResourceManager::LoadTexture("Resources/arts/Board.png","Board");
  Position = Vector2{0, 47};
  Scale = 1.0f;
  Rotation = 0.0f;
}

BG::~BG() {}

bool BG::update(bool onGround) { return true; }

void BG::Draw(){
  DrawText("TIME", GetScreenWidth() / 2 - 30, 10, 20, WHITE);
  DrawText("1:60", GetScreenWidth() / 2 - 30, 30, 20, WHITE);
  Rectangle source = {0,0, (float)GetScreenWidth(), (float)GetScreenHeight()};
  
  // DrawTextureEx(test, Vector2{0,0}, Rotation, Scale, WHITE);
  DrawTextureRec(Texture, source, Position, WHITE);
}

Rectangle BG::getBoundingBox(){
  Rectangle result = {Position.x, Position.y, (float)Texture.width, (float)Texture.height};
  return  result;
}

