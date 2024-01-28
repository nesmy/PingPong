#include "Paddle.h"
#include "raylib.h"

class AiPaddle : public Paddle {
public:
  AiPaddle(Texture2D texture) : Paddle(texture) {}
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
