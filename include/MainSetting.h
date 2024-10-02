#pragma once

#include "Scene.h"
#include "Pong.h"

class MainSettingScene : public BB::Scene {
 public:
  MainSettingScene(){
    returnClicked = false;
    restartClicked = false;
    quit = false;
  }
  virtual ~MainSettingScene(){
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
  bool returnClicked;
  bool restartClicked;
  bool quit;
};
