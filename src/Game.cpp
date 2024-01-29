#include "AiPaddle.h"
#include "Ball.h"
#include "GameState.h"
#include "Score.h"
#include "raylib.h"
#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char *argv[]) {
  InitWindow(1000, 620, "PingPong");
  SetTargetFPS(60);
  SetExitKey(KEY_NULL);

  // BackGround
  Texture2D BackGround = LoadTexture("assets/arts/Board.png");
  BackGround.width = GetScreenWidth();
  BackGround.height = GetScreenHeight();

  // ScoreBar
  Texture2D Score0 = LoadTexture("assets/arts/ScoreBar.png");
  Score0.width += 50;
  Score Score1(Score0);
  Score1.GetPosition().x = 0;
  Score1.GetPosition().y = 0;
  Score Score2(Score0);
  Score2.GetPosition().x = GetScreenWidth() - Score0.width;
  Score2.GetPosition().y = 0;
  Score2.GetSrc() =
      (Rectangle){0, 0, (float)-Score0.width, (float)Score0.height};

  // Ball
  Ball ball(LoadTexture("assets/arts/Ball.png"));

  // Paddle
  Paddle Player(LoadTexture("assets/arts/Player.png"));

  // AiPaddle
  AiPaddle Computer(LoadTexture("assets/arts/Computer.png"));

  int Pscore = 0;
  int Cscore = 0;

  GameState Game;
  Timer timer = {10};

  while (!Game._EndProg) {

    if (WindowShouldClose())
      Game._EndProg = true;

    Game.Update();
    BeginDrawing();
    if (!Game._GameStart && !Game._SetOpen && !Game._GameOver) {
      Game.StartMenu(&timer);
    } else if (!Game._GameMenu && Game._GameOver == false) {
      // GameStart
      Game._GameStart = true;

      // Update
      ball.Update(Cscore, Pscore);
      Player.Update();
      Computer.Update(ball.GetPosition().y);
      UpdateTimer(&timer);

      // CHeck collisions
      if (CheckCollisionCircleRec(
              ball.GetPosition(), ball._Radius,
              (Rectangle){Player.GetPosition().x, Player.GetPosition().y,
                          (float)Player.GetTexture().width,
                          (float)Player.GetTexture().height})) {
        if (ball._Speed_x > 0)
          ball._Speed_x *= -1;
      } else if (CheckCollisionCircleRec(
                     ball.GetPosition(), ball._Radius,
                     (Rectangle){Computer.GetPosition().x - 30,
                                 Computer.GetPosition().y,
                                 (float)Computer.GetTexture().width,
                                 (float)Computer.GetTexture().height}))
        if (ball._Speed_x < 0)
          ball._Speed_x *= -1;

      // Drawing
      DrawTexture(BackGround, 0, 0, WHITE);
      Score1.Draw();
      DrawText(std::to_string(Cscore).c_str(), GetScreenWidth() / 3 - 20, 5, 40,
               BLACK);
      Score2.Draw();
      DrawText(std::to_string(Pscore).c_str(), GetScreenWidth() / 1.5 + 20, 5,
               40, BLACK);
      DrawText("TIME", GetScreenWidth() / 2 - 25, 0, 17, LIGHTGRAY);
      DrawText(TextFormat("%01i:%01i", (int)timer.Lifetime / 60,
                          (int)timer.Lifetime % 60),
               GetScreenWidth() / 2 -
                   MeasureText(TextFormat("%01i:%01i", (int)timer.Lifetime / 60,
                                          (int)timer.Lifetime % 60),
                               20) /
                       2,

               20, 20, LIGHTGRAY);
      ball.Draw();
      Player.Draw();
      Computer.Draw();
      if (Pscore == 7 || Cscore == 7) {
        Game._GameOver = true;
      } else if (TimerDone(&timer)) {
        Game._GameOver = true;
      }
    } else if (Game._GameOver) {
      Game.GameOver(&Pscore, &Cscore, &timer);
    } else if (Game._SetOpen) {
      Game.SettingsMenu(Player._Speed, Computer._Speed, ball._Speed_x);
    } else {
      Game.MainMenu();
    }

    if (IsKeyPressed(KEY_ESCAPE) && !Game._GameMenu) {
      Game.ToggleMenu();
    }
    DrawFPS(20, 20);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
