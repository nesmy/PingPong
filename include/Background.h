#pragma once
#include "Engine/Object.h"
#include "ResourceManager.h"


class BG : public BB::Object {
 public:
  BG();
  // {
  //   BB::ResourceManager::AddObject(this);
  //   Texture = BB::ResourceManager::LoadTexture("Resources/arts/Board.png", "Board");
  //   Position = Vector2{x, y};
  //   Scale = 1.0f;
  //   Rotation = 0.0f;
  // }
  virtual ~BG();

  virtual bool update(bool onGround);
  virtual void Draw();
  virtual Rectangle getBoundingBox();
  // virtual void goUp();
  // virtual void goLeft();
  // virtual void goRight();
  // virtual void goDown();
  // virtual void goNowhere();
  // virtual void doInteractWith();

  // void Draw(){
  //   Rectangle source = {0,0, (float)GetScreenWidth(), (float)GetScreenHeight()};
  //   // DrawTextureEx(Texture, Position, Rotation, Scale, WHITE);
  //   DrawTextureRec(Texture, source, Position, WHITE);
  // }
 private:
  // Vector2 getUpperLeftPosition();

};
