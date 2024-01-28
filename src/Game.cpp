#include "Ball.h"
#include "Paddle.h"
#include "Score.h"
#include "raylib.h"

int main(int argc, char *argv[]) {
  InitWindow(802, 455, "PingPong");
  SetTargetFPS(60);

  // BackGround
  Texture2D BackGround = LoadTexture("assets/arts/Board.png");

  // Ball
  Ball ball(LoadTexture("assets/arts/Ball.png"));
  ball.GetPosition().x =
      (float)GetScreenWidth() / 2 - (float)ball.GetTexture().width / 2;
  ball.GetPosition().y =
      (float)GetScreenHeight() / 2 - (float)ball.GetTexture().height / 2;
  ball._Radius = 20;
  ball._Speed_x = 7;
  ball._Speed_y = 7;

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

  Paddle Computer(LoadTexture("assets/arts/Computer.png"));
  Computer.GetPosition().x = GetScreenWidth() - Computer.GetTexture().width;
  Computer.GetPosition().y =
      (float)GetScreenHeight() / 2 - (float)Computer.GetTexture().height / 2;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    DrawTexture(BackGround, 0, 0, WHITE);
    ball.Update();
    Score1.Draw();
    Score2.Draw();
    ball.Draw();
    Player.Draw();
    Computer.Draw();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
