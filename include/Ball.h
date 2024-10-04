#pragma once
#include "Engine/Object.h"
#include "ResourceManager.h"


class Ball : public BB::Object {
 public:
  Ball(float x, float y, int &player, int &cpu)
    : player_score(player), cpu_score(cpu){
    Trail = BB::ResourceManager::LoadTexture("Resources/arts/BallMotion.png","Trail");
    Texture = BB::ResourceManager::LoadTexture("Resources/arts/Ball.png", "Ball");
    BB::ResourceManager::AddObject(this);
    Position = Vector2{x,y};
    Scale = 1.0f;
    Rotation = 0.0f;
    traiRot = 90.0f;
    mRadius = 15.0f;
    mSpeed_x = 7;
    mSpeed_y = 7;
  }
  virtual ~Ball() {}

  virtual bool update(bool onGround){
    MoveBall();
    return true;
  }

  //ball movement
  void MoveBall(){
    Position.x += mSpeed_x;
    Position.y += mSpeed_y;

    //edge collision
    if(Position.y + mRadius >= GetScreenHeight() || Position.y - mRadius <= BB::ResourceManager::GetTexture("ScoreBar").height){
      drawTrail = true;
      mSpeed_y *= -1;
    }
    if (Position.x + mRadius >= GetScreenWidth()){
      cpu_score++;
      Reset();
    }
    if(Position.x - mRadius <= 0){
      player_score++;
      Reset();
    }
  }

  virtual void Draw(){
    DrawCircle(Position.x, Position.y, mRadius, RED);
    Vector2 temp = Vector2{Position.x - Texture.width / 2, Position.y - Texture.height /2};
    Rectangle source = {0,0, -(float)Trail.width, (float)Trail.height };
    Rectangle dest = {Position.x,Position.y,(float)Trail.width,(float)Trail.height};
    Vector2 origin = {0,0};
    // if(drawTrail){
    // traiRot = 90.0f;
    // // DrawTextureEx(Trail, Position, traiRot, Scale, WHITE);
      // DrawTextureRec(Trail, source, Position, WHITE);
      // DrawTexturePro(Trail, source, dest, origin, traiRot, WHITE);
    // }
    DrawTextureEx(Texture, temp, Rotation, Scale, WHITE);
  }

  void Reset(){
    Position.x = (float)GetScreenWidth() / 2;
    Position.y = (float)GetScreenHeight() / 2;

    int speed_choices[2] = {-1, 1};
    mSpeed_x *= speed_choices[GetRandomValue(0,1)];
    mSpeed_y *= speed_choices[GetRandomValue(0,1)];
  }
private:
  Texture2D Trail;
public:
  bool drawTrail = false;
  int mRadius;
  int mSpeed_x, mSpeed_y;
  float traiRot;
  int &cpu_score, &player_score;
};
