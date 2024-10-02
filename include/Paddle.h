#pragma once
#include "Ball.h"
#include "Engine/Object.h"
#include "ResourceManager.h"


class Paddle : public BB::Object {
 public:
  Paddle(float x, float y, bool player, std::shared_ptr<Ball> ball)
    :mBall(ball), mPlayer(player){
    if(player){
      Texture = BB::ResourceManager::LoadTexture("Resources/arts/Player.png", "Player");
    }else {
      Texture = BB::ResourceManager::LoadTexture("Resources/arts/Computer.png", "Computer");
    }
    Position = Vector2{x, y};
    Scale = 1.0f;
    Rotation = 0.0f;
    mSpeed = 6;
  }
  virtual ~Paddle() {}

  virtual void Draw(){
    DrawTextureEx(Texture, Position, Rotation, Scale, WHITE);
  }

  virtual bool update(bool onGround){
    if(mPlayer){
      MovePad();
      if(CheckCollisionCircleRec(mBall->GetPosition(), mBall->mRadius, Rectangle{GetPosition().x, GetPosition().y, (float)GetTexture().width,(float)GetTexture().height})){
	mBall->drawTrail = true;
	mBall->mSpeed_x *= -1;
    }
    }else {
      MoveCPU();
      if(CheckCollisionCircleRec(mBall->GetPosition(), mBall->mRadius, Rectangle{GetPosition().x, GetPosition().y, (float)GetTexture().width, (float)GetTexture().height})){
	mBall->drawTrail = true;
	mBall->mSpeed_x *= -1;
  }
    }
    return true;
  }

  void MovePad(){
    if(IsKeyDown(KEY_UP)){
      Position.y -= mSpeed;
    }
    if(IsKeyDown(KEY_DOWN)){
      Position.y += mSpeed;
    }
    LimitMovement();
  }

  void MoveCPU(){
    if(Position.y + Texture.height / 2 > mBall->GetPosition().y){
      Position.y -= mSpeed;
    }
    if(Position.y + Texture.height / 2 <= mBall->GetPosition().y){
      Position.y += mSpeed;
    }

    LimitMovement();
  }
  
private:
  void LimitMovement(){
    if(Position.y <= BB::ResourceManager::GetTexture("ScoreBar").height){
      Position.y = BB::ResourceManager::GetTexture("ScoreBar").height;
    }
    if(Position.y + Texture.height >= GetScreenHeight()){
      Position.y = GetScreenHeight() - Texture.height;
    }
  }

  std::shared_ptr<Ball> mBall;
  bool mPlayer;
public:
  int mSpeed;
};
