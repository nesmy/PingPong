#include "Pong.h"
#include "ResourceManager.h"
#include "Setting.h"

using namespace BB;

Pong::Pong() {}
Pong::~Pong() {}

void Pong::loadResources(){
  start();
  std::shared_ptr<BG> Background = std::make_shared<BG>(&time);
  std::shared_ptr<Score> Score1 = std::make_shared<Score>(0,0, false, cpu_score);
  std::shared_ptr<Score> Score2 = std::make_shared<Score>((float)GetScreenWidth() - ResourceManager::GetTexture("ScoreBar").width, 0, true, player_score);
  std::shared_ptr<Ball> ball = std::make_shared<Ball>((float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2, player_score, cpu_score);
  Computer = std::make_shared<Paddle>(15, (float)GetScreenHeight() / 2, false, ball);
  std::shared_ptr<Paddle> Player = std::make_shared<Paddle>((float)GetScreenWidth() - Computer->GetTexture().width - 15  , (float)GetScreenHeight() / 2 - (float)Computer->GetTexture().height / 2,true, ball);  

  
  playerAvatar = Player;
  Objects.emplace_back(Background);
  Objects.emplace_back(Score1);
  Objects.emplace_back(Score2);
  Objects.emplace_back(ball);
  Objects.emplace_back(Computer);
  Objects.emplace_back(Player);
}

std::shared_ptr<BB::Scene> Pong::update(){
    BB::Scene::update();

  if(easy){
    Computer->mCpuSpeed = 3;
  }else if (medium) {
    Computer->mCpuSpeed = 4;
  }else if (hard) {
    Computer->mCpuSpeed = 6;
  }
  
    if(cpu_score == 7 || player_score == 7){
      cpu_score = 0;
      player_score = 0;
      PlaySound(BB::ResourceManager::GetSound("Over"));
      BB::ResourceManager::GetScene("Game")->loadResources();
      return BB::ResourceManager::GetScene("Over");
    }
    else if(TimerDone(&time)){
      cpu_score = 0;
      player_score = 0;
      PlaySound(BB::ResourceManager::GetSound("Over"));
      BB::ResourceManager::GetScene("Game")->loadResources();      
      return BB::ResourceManager::GetScene("Over");
    }
    else if(IsKeyDown(KEY_ESCAPE)){
      return ResourceManager::GetScene("Setting");
    }
    else {
      return nullptr;
    }
  }
