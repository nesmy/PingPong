#include "raylib.h"
#include <cstddef>
typedef struct {
  float Lifetime;
} Timer;

extern void StartTimer(Timer *time, float lifetime);
extern void UpdateTimer(Timer *time);
extern bool TimerDone(Timer *time);
