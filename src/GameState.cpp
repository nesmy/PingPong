#include "GameState.h"
#include "raylib.h"
#include <iostream>
GameState::GameState() {
  listBox.push_back(&_Quit);
  listBox.push_back(&_Start);
  listBox.push_back(&_Continue);
  listBox.push_back(&_Restart);
  listBox.push_back(&_Settings);
  for (auto box : listBox) {
    box->_Src.width = BOXWIDTH;
    box->_Src.height = BOXHEIGHT;
  }
  _Settings._Src.x = (float)GetScreenWidth() / 2 - _Settings._Src.width / 2;
  _Settings._Src.y = (float)GetScreenHeight() / 2;
  _Quit._Src.x = (float)GetScreenWidth() / 2 - _Quit._Src.width / 2;
  _Quit._Src.y = _Settings._Src.y + (_Settings._Src.height + BOXOFF);
  _Start._Src.x = (float)GetScreenWidth() / 2 - _Start._Src.width / 2;
  _Start._Src.y = _Settings._Src.y - (_Settings._Src.height + BOXOFF);
  _Continue._Src.x = _Start._Src.x;
  _Continue._Src.y = _Start._Src.y;
  _Restart = _Settings;
}

GameState::~GameState() {}
void GameState::StartMenu(Timer *timer) {
  ClearBackground(BLACK);
  DrawText("Ping Pong",
           (float)GetScreenWidth() / 2 -
               (float)MeasureText("Ping Pong", BOXFSIZE) / 2,
           _Start._Src.y - (_Settings._Src.height + BOXOFF), BOXFSIZE, RED);
  _Quit._Src.x = (float)GetScreenWidth() / 2 - _Quit._Src.width / 2;
  _Quit._Src.y = _Settings._Src.y + (_Settings._Src.height + BOXOFF);
  Start(timer);
  Quit();
  Settings();
}
void GameState::MainMenu() {
  DrawText("PAUSE",
           (float)GetScreenWidth() / 2 -
               (float)MeasureText("PAUSE", BOXFSIZE) / 2,
           _Start._Src.y - (_Settings._Src.height + BOXOFF), BOXFSIZE, RED);
  _Quit._Src.x = (float)GetScreenWidth() / 2 - _Quit._Src.width / 2;
  _Quit._Src.y = _Settings._Src.y + (_Settings._Src.height + BOXOFF);
  _Continue._Src.x = _Start._Src.x;
  _Continue._Src.y = _Start._Src.y;
  Continue();
  Quit();
  Settings();
}
void GameState::GameOver(int *Pscore, int *Cscore, Timer *timer) {
  DrawText("GAME OVER",
           _Start._Src.x + _Start._Src.width / 2 -
               (float)MeasureText("GAME OVER", BOXFSIZE) / 2,
           _Start._Src.y, BOXFSIZE, RED);
  Restart(Pscore, Cscore, timer);
  _Quit._Src.x = (float)GetScreenWidth() / 2 - _Quit._Src.width / 2;
  _Quit._Src.y = _Settings._Src.y + (_Settings._Src.height + BOXOFF);
  Quit();
}
void GameState::SettingsMenu(int Pspeed, int Cspeed, int Bspeed) {
  ClearBackground(BLACK);
  DrawText(TextFormat("PLAYER SPEED: %02i", Pspeed), 20, GetScreenHeight() / 4,
           40, RED);
  DrawText(TextFormat("AI SPEED: %02i", Cspeed), 20, GetScreenHeight() / 3 + 20,
           40, RED);
  DrawText(TextFormat("BALL SPEED: %02i", Bspeed), 20, GetScreenHeight() / 2,
           40, RED);
  _Continue._Src.x = 20;
  _Continue._Src.y = (float)GetScreenHeight() - _Quit._Src.height - 120;
  Continue();
  _Quit._Src.x = 20;
  _Quit._Src.y = (float)GetScreenHeight() - _Quit._Src.height - 40;
  Quit();
}

void GameState::ToggleMenu() {
  if (_GameMenu == true)
    _GameMenu = false;
  else
    _GameMenu = true;
}

void GameState::Update() {}

bool GameState::IsOverButton(Rectangle rec) {
  return CheckCollisionPointRec(GetMousePosition(), rec);
}

void GameState::Quit() {
  DrawRectangleRec(_Quit._Src, WHITE);
  DrawText("QUIT",
           _Quit._Src.x + _Quit._Src.width / 2 -
               (float)MeasureText("QUIT", BOXFSIZE) / 2,
           _Quit._Src.y + _Quit._Src.height / 2 - (float)BOXFSIZE / 2, BOXFSIZE,
           RED);
  if (IsOverButton(_Quit._Src) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    _EndProg = true;
  }
}

void GameState::Continue() {
  DrawRectangleRec(_Continue._Src, WHITE);
  DrawText("CONTINUE",
           _Continue._Src.x + _Continue._Src.width / 2 -
               (float)MeasureText("CONTINUS", BOXFSIZE) / 2,
           _Continue._Src.y + _Continue._Src.height / 2 - (float)BOXFSIZE / 2,
           BOXFSIZE, RED);
  if (IsOverButton(_Continue._Src) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    if (!_GameStart)
      ToggleSettings();
    else {
      ToggleMenu();
      ToggleSettings();
    }
  }
}
void GameState::Restart(int *Pscore, int *Cscore, Timer *timer) {
  DrawRectangleRec(_Restart._Src, WHITE);
  DrawText("RESTART",
           _Restart._Src.x + _Restart._Src.width / 2 -
               (float)MeasureText("RESTART", BOXFSIZE) / 2,
           _Restart._Src.y + _Restart._Src.height / 2 - (float)BOXFSIZE / 2,
           BOXFSIZE, RED);
  if (IsOverButton(_Restart._Src) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    *Pscore = 0;
    *Cscore = 0;
    StartTimer(timer, 300.0f);
    _GameOver = false;
  }
}
void GameState::Start(Timer *timer) {
  DrawRectangleRec(_Start._Src, WHITE);
  DrawText("START",
           _Start._Src.x + _Start._Src.width / 2 -
               (float)MeasureText("START", BOXFSIZE) / 2,
           _Start._Src.y + _Start._Src.height / 2 - (float)BOXFSIZE / 2,
           BOXFSIZE, RED);
  if (IsOverButton(_Start._Src) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    _GameStart = true;
    ToggleMenu();
    StartTimer(timer, 300.0f);
  }
}
void GameState::Settings() {
  if (IsOverButton(_Settings._Src) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    ToggleSettings();
  }
  DrawRectangleRec(_Settings._Src, WHITE);
  DrawText("Settings",
           _Settings._Src.x + _Settings._Src.width / 2 -
               (float)MeasureText("Settings", BOXFSIZE) / 2,
           _Settings._Src.y + _Settings._Src.height / 2 - (float)BOXFSIZE / 2,
           BOXFSIZE, RED);
  // if (IsOverButton(_Settings._Src) &&
  // IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) std::cout << "TODO\n";
}
void GameState::ReturnB() {}

void GameState::ToggleSettings() {
  if (_SetOpen)
    _SetOpen = false;
  else {
    _SetOpen = true;
  }
}
