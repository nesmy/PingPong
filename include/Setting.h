#pragma once

#include "Scene.h"
#include "Pong.h"

class SettingScene : public BB::Scene {
 public:
  SettingScene(){
    startClicked = false;
    restartClicked = false;
    quit = false;
  }
  virtual ~SettingScene(){
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
  bool startClicked;
  bool restartClicked;
  bool quit;
};
