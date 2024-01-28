#include "AiPaddle.h"
#include "Ball.h"
#include "Score.h"
#include "raylib.h"
#include <iostream>
#include <ostream>
#include <string>

bool GameMenu = true;
void ToggleMenu();
int main(int argc, char *argv[]) {
  InitWindow(802, 455, "PingPong");
  SetTargetFPS(60);

  // BackGround
  Texture2D BackGround = LoadTexture("assets/arts/Board.png");

  // Ball
  Ball ball(LoadTexture("assets/arts/Ball.png"));

  // ScoreBar
  Texture2D Score0 = LoadTexture("assets/arts/ScoreBar.png");
  Score Score1(Score0);
  Score1.GetPosition().x = 0;
  Score1.GetPosition().y = 0;
  Score Score2(Score0);
  Score2.GetPosition().x = GetScreenWidth() - Score0.width;
  Score2.GetPosition().y = 0;
  Score2.GetSrc() =
      (Rectangle){0, 0, (float)-Score0.width, (float)Score0.height};

  // Paddle
  Paddle Player(LoadTexture("assets/arts/Player.png"));
  Player.GetPosition().x = 0;
  Player.GetPosition().y =
      (float)GetScreenHeight() / 2 - (float)Player.GetTexture().height / 2;
  Player._Speed = 6;

  // AiPaddle
  AiPaddle Computer(LoadTexture("assets/arts/Computer.png"));
  Computer.GetPosition().x = GetScreenWidth() - Computer.GetTexture().width;
  Computer.GetPosition().y =
      (float)GetScreenHeight() / 2 - (float)Computer.GetTexture().height / 2;
  Computer._Speed = 3;

  bool GameStart = true;
  int Pscore = 0;
  int Cscore = 0;

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_SPACE) == true)
      ToggleMenu();
    BeginDrawing();
    ClearBackground(WHITE);
    if (!GameMenu) {
      // GameStart
      GameStart = false;

      // Update
      ball.Update(Pscore, Cscore);
      std::cout << "Pscore: " << Pscore << " Cscore: " << Cscore << std::endl;
      Player.Update();
      Computer.Update(ball.GetPosition().y);

      // CHeck collisions
      if (CheckCollisionCircleRec(
              ball.GetPosition(), ball._Radius,
              (Rectangle){Player.GetPosition().x - 30, Player.GetPosition().y,
                          (float)Player.GetTexture().width,
                          (float)Player.GetTexture().height})) {
        ball._Speed_x *= -1;
      } else if (CheckCollisionCircleRec(
                     ball.GetPosition(), ball._Radius,
                     (Rectangle){Computer.GetPosition().x,
                                 Computer.GetPosition().y,
                                 (float)Computer.GetTexture().width,
                                 (float)Computer.GetTexture().height}))
        ball._Speed_x *= -1;

      // Drawing
      DrawTexture(BackGround, 0, 0, WHITE);
      Score1.Draw();
      DrawText(std::to_string(Pscore).c_str(), GetScreenWidth() / 2 - 45, 5, 40,
               WHITE);
      Score2.Draw();
      DrawText(std::to_string(Cscore).c_str(), GetScreenWidth() / 2 + 25, 5, 40,
               WHITE);
      ball.Draw();
      Player.Draw();
      Computer.Draw();
    } else {
      if (GameStart) {
        ClearBackground(BLACK);
      } else {
        DrawText("PAUSE", GetScreenWidth() / 2, GetScreenHeight() / 2, 24,
                 GREEN);
      }
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

void ToggleMenu() {
  if (GameMenu == true)
    GameMenu = false;
  else
    GameMenu = true;
}
