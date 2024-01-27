#include "raylib.h"
class Paddle {
public:
  Paddle(Texture2D texture) : _Texture(texture) {}
  ~Paddle() {}

  void Draw() { DrawTextureV(_Texture, _Position, WHITE); }

  Vector2 &GetPosition() { return _Position; }
  Rectangle &GetDest() { return _Dest; }
  Rectangle &GetSrc() { return _Src; }
  Texture2D &GetTexture() { return _Texture; }

private:
  Texture2D _Texture;
  Vector2 _Position;
  Rectangle _Dest;
  Rectangle _Src;
};
