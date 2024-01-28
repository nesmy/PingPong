#include "raylib.h"
class Ball {
public:
  Ball(Texture2D texture) : _Texture(texture) {}
  ~Ball() {}

  void Draw() { DrawTextureV(_Texture, _Position, WHITE); }
  void Update() {
    _Position.x += _Speed_x;
    _Position.y += _Speed_y;
  }

  Vector2 &GetPosition() { return _Position; }
  Rectangle &GetDest() { return _Dest; }
  Rectangle &GetSrc() { return _Src; }
  Texture &GetTexture() { return _Texture; }

  int _Speed_x, _Speed_y;
  int _Radius;

private:
  Texture2D _Texture;
  Vector2 _Position;
  Rectangle _Dest;
  Rectangle _Src;
};
