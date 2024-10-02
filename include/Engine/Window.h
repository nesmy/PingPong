#pragma once
#include "Config.h"

class Window {
 public:
  Window(int width, int height, const char* title){
    InitWindow(width, height, title);
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
  }
  ~Window(){
    CloseWindow();
  }
 private:
};
