#pragma once
#include "Engine/GTime.h"
#include "Engine/Object.h"
#include "ResourceManager.h"


class BG : public BB::Object {
 public:
  BG(BB::Timer* time);
  
  virtual ~BG();

  virtual bool update(bool onGround);
  virtual void Draw();
  virtual Rectangle getBoundingBox();
  // virtual void goUp();
  // virtual void goLeft();
  // virtual void goRight();
  // virtual void goDown();
  // virtual void goNowhere();
  // virtual void doInteractWith();
 private:
  BB::Timer* mTime;
  // Vector2 getUpperLeftPosition();

};
