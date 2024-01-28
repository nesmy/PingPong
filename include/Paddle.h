#include "raylib.h"
class Paddle {
public:
  Paddle(Texture2D texture) : _Texture(texture) {}
  ~Paddle() { UnloadTexture(_Texture); }

  void Draw() { DrawTextureV(_Texture, _Position, WHITE); }
  void Update() {
    if (IsKeyDown(KEY_UP)) {
      _Position.y -= _Speed;
    } else if (IsKeyDown(KEY_DOWN)) {
      _Position.y += _Speed;
    }

    LimitMovement();
  }

  Vector2 &GetPosition() { return _Position; }
  Rectangle &GetDest() { return _Dest; }
  Rectangle &GetSrc() { return _Src; }
  Texture2D &GetTexture() { return _Texture; }

  int _Speed;

protected:
  void LimitMovement() {

    if (_Position.y <= 47)
      _Position.y = 47;
    else if (_Position.y >= GetScreenHeight() - _Texture.height)
      _Position.y = GetScreenHeight() - _Texture.height;
  }

protected:
  Texture2D _Texture;
  Vector2 _Position;
  Rectangle _Dest;
  Rectangle _Src;
};
