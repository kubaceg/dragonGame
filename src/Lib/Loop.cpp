#include "Loop.h"

void Loop::FPS_Initial() {
  NextTick = 0;
  interval = 1*1000/FPS;
}

void Loop::FPS_Fn() {
  if (NextTick > SDL_GetTicks()) SDL_Delay(NextTick - SDL_GetTicks());
  NextTick = SDL_GetTicks() + interval;
}