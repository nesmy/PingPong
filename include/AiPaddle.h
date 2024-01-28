#include "Paddle.h"
#include "raylib.h"

class AiPaddle : public Paddle {
public:
  AiPaddle(Texture2D texture) : Paddle(texture) {
    _Position.x = 20;
    _Position.y = (float)GetScreenHeight() / 2 - (float)_Texture.height / 2;
    _Speed = 5;
  }
  ~AiPaddle() { UnloadTexture(_Texture); }

  void Update(int ball_y) {
    if (_Position.y + (float)_Texture.height / 2 > ball_y)
      _Position.y -= _Speed;
    else if (_Position.y + (float)_Texture.height / 2 <= ball_y)
      _Position.y += _Speed;

    LimitMovement();
  }

private:
};
