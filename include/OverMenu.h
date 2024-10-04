#pragma once

#include "Pong.h"
#include "Setting.h"
#include "Scene.h"

class OverMenuScene : public BB::Scene {
 public:
  OverMenuScene(){
    restartClicked = false;
    quit = false;
    sound = LoadSound("Resouces/Sound/over.mp3");
  }
  virtual ~OverMenuScene(){
  }
  
  virtual std::shared_ptr<BB::Scene> update();
  virtual bool shouldQuit(){
    return quit;
  }
  virtual void Draw();
  
  virtual void doExit() {
    quit = true;
  }

 private:
  bool restartClicked;
  bool quit;
  Sound sound;
};
