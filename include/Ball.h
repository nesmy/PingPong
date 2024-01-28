#include "raylib.h"
class Ball {
public:
  Ball(Texture2D texture) : _Texture(texture) {
    _Radius = ((_Texture.width * _Texture.width) / (8 * _Texture.height) +
               _Texture.height / 2);

    _Position.x = (float)GetScreenWidth() / 2 - (float)_Texture.width / 2;
    _Position.y = (float)GetScreenHeight() / 2 - (float)_Texture.height / 2;
    _Radius = 20;
    _Speed_x = 7;
    _Speed_y = 7;
    _iniPos = _Position;
  }
  ~Ball() { UnloadTexture(_Texture); }

  void Draw() { DrawTextureV(_Texture, _Position, WHITE); }
  void Update(int &Pscore, int &Cscore) {
    _Position.x += _Speed_x;
    _Position.y += _Speed_y;

    if (_Position.y + _Radius >= GetScreenHeight() || _Position.y <= 47) {
      _Speed_y *= -1;
    } else if (_Position.x + _Radius >= GetScreenWidth() || _Position.x <= 0) {
      _Speed_x *= -1;
    }

    if (_Position.x >= GetScreenWidth()) {
      Pscore++;
      ResetBall();
    } else if (_Position.x <= 0) {
      Cscore++;
      ResetBall();
    }
  }
  void ResetBall() {
    int speed_choices[2] = {-1, 1};
    _Position = _iniPos;
    _Speed_x *= speed_choices[GetRandomValue(0, 1)];
    _Speed_y *= speed_choices[GetRandomValue(0, 1)];
  }

  Vector2 &GetPosition() { return _Position; }
  Rectangle &GetDest() { return _Dest; }
  Rectangle &GetSrc() { return _Src; }
  Texture &GetTexture() { return _Texture; }

  int _Speed_x, _Speed_y;
  int _Radius;

private:
  Vector2 _iniPos;
  Texture2D _Texture;
  Vector2 _Position;
  Rectangle _Dest;
  Rectangle _Src;
};
