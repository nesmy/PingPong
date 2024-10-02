#pragma once
#include "Background.h"
#include "Ball.h"
#include "Paddle.h"
#include "Score.h"
#include "Scene.h"

class Pong : public BB::Scene {
 public:
  Pong();
  virtual ~Pong();
  
  virtual void loadResources();
   
 private:
  // Paddle* player;
  // Paddle* computer;
  // Ball* ball;
  BG* bG;
  // Score* score;
  // Score* score2;
  int player_score, cpu_score;
};