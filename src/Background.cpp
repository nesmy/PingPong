#include "Background.h"

BG::BG(BB::Timer *time)
  :mTime(time)    {
  Texture = BB::ResourceManager::LoadTexture("Resources/arts/Board.png","Board");
  BB::ResourceManager::AddObject(this);
  Position = Vector2{0, 47};
  Scale = 1.0f;
  Rotation = 0.0f;
  BB::StartTimer(mTime, 120.0f);
}

BG::~BG() {}

bool BG::update(bool onGround) {
  BB::UpdateTimer(mTime);
  return true;
}

void BG::Draw(){
  DrawText("TIME", GetScreenWidth() / 2 - MeasureText("TIME", 20) / 2, 5, 20, VIOLET);
  DrawText(TextFormat("%01i:%01i", (int)mTime->Lifetime / 60,
		      (int)mTime->Lifetime % 60),
	   GetScreenWidth() / 2 -
	   MeasureText(TextFormat("%01i:%01i", (int)mTime->Lifetime / 60,
				  (int)mTime->Lifetime % 60),
		       20) /
	   2,

	   25, 20, WHITE);
  Rectangle source = {0,0, (float)GetScreenWidth(), (float)GetScreenHeight()};
  
  // DrawTextureEx(test, Vector2{0,0}, Rotation, Scale, WHITE);
  DrawTextureRec(Texture, source, Position, WHITE);
}

Rectangle BG::getBoundingBox(){
  Rectangle result = {Position.x, Position.y, (float)Texture.width, (float)Texture.height};
  return  result;
}

