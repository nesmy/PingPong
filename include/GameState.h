#pragma once

#include "GTime.h"
#include "raylib.h"
#include <iostream>
#include <list>

typedef struct Button {
  Rectangle _Src;
  Color _color;
} Button;

class GameState {
public:
  GameState();
  ~GameState();
  void StartMenu(Timer *timer);
  void MainMenu();
  void GameOver(int *Pscore, int *Cscore, Timer *timer);
  void SettingsMenu(int Pspeed, int Cspeed, int Bspeed);
  void ToggleMenu();
  void Update();
  bool IsOverButton(Rectangle rec);

  bool _GameStart = false;
  bool _GameOver = false;
  bool _GameMenu = true;
  int _Selected;
  bool _SetOpen = false;
  bool _EndProg = false;

private:
  Button _Quit;
  Button _Continue;
  Button _Start;
  Button _Settings;
  Button _Restart;
  Button _ReturnB;
  Button _LeftHook;
  Button _RightHook;
  std::list<Button *> listBox;
#define BOXWIDTH 200
#define BOXHEIGHT 70
#define BOXOFF 40
#define BOXFSIZE 35

private:
  void ToggleSettings();
  void Continue();
  void Start(Timer *timer);
  void Restart(int *Pscore, int *Cscore, Timer *timer);
  void Settings();
  void Quit();
  void ReturnB();
  void LeftHook();
  void RightHook();
};
