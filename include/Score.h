#pragma once
#include "Engine/Object.h"
#include "ResourceManager.h"


class Score : public BB::Object {
 public:
  Score(float x, float y, bool flip, int& score)
    :mScore(score){
    Flip = flip;
    Texture = BB::ResourceManager::LoadTexture("Resources/arts/ScoreBar.png", "ScoreBar");
    Position = Vector2{x,y};
    Scale = 1.0f;
    Rotation = 0.0f;
  }
  virtual ~Score() {}

  void Draw(){
    Rectangle source = {0,0, -(float)Texture.width, (float)Texture.height };
    if(Flip == false){
      DrawTextureEx(Texture, Position, Rotation, Scale, WHITE);
      DrawText(TextFormat("%i", mScore), 250, 10, 30, BLACK);
    }else {
      DrawTextureRec(Texture, source, Position, WHITE);
      DrawText(TextFormat("%i", mScore), 540, 10, 30, BLACK);
    }
  }

  virtual bool update(bool onGround){
    
    return true;
  }

 private:
  bool Flip;
  int &mScore;
};
