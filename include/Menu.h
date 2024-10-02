#pragma once

#include "Pong.h"
#include "Setting.h"
#include "Scene.h"
#include <memory>

class MenuScene : public BB::Scene {
 public:
  MenuScene(){
    startClicked = false;
    settingClicked = false;
    quit = false;
  }
  virtual ~MenuScene(){
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
  bool settingClicked;
  bool quit;
};
