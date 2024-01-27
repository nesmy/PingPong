#include "raylib.h"
class Score {
public:
  Score(Texture2D texture) : _Texture(texture) {}
  ~Score() {}

  void Draw() { DrawTextureV(_Texture, _Position, WHITE); }

  Vector2 &GetPosition() { return _Position; }
  Rectangle &GetDest() { return _Dest; }
  Rectangle &GetSrc() { return _Src; }

private:
  Texture2D _Texture;
  Vector2 _Position;
  Rectangle _Dest;
  Rectangle _Src;
};
